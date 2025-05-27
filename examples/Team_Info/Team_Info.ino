#include <rustplus.h>

RustPlus rustplus;

const char* SERVER_IP = "123.123.123.123";
const uint16_t PORT = 12345;

const uint64_t STEAM_ID = 123456789;
const uint32_t PLAYER_TOKEN = 13242;

void setup() {
  Serial.begin(115200);

  WiFi.begin("SSID", "PASS");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  
  delay(500);

  rustplus.connect(SERVER_IP, PORT, STEAM_ID, PLAYER_TOKEN);

  rustplus.waitForConnection();
  
  if(rustplus.isConnected()) {
    RustPlus::TeamInfo team = rustplus.getTeam();
  
    Serial.println("\n=== TEAM INFORMATION ===");
    Serial.println("Leader SteamID: " + String(team.leaderSteamID));
    Serial.println("Members (" + String(team.memberCount) + "):");
  
      for(int i = 0; i < team.memberCount; i++) {
        RustPlus::TeamMember member = team.members[i];
    
        Serial.println("\nMember #" + String(i+1));
        Serial.println("Name: " + String(member.name));
        Serial.println("SteamID: " + String(member.steamID));
        Serial.println("Status: " + String(member.isOnline ? "Online" : "Offline"));
        Serial.println("Position: (" + String(member.x) + ", " + String(member.y) + ")");
        Serial.println("Alive: " + String(member.isAlive ? "Yes" : "No"));
        Serial.print("Spawn Time: ");
        Serial.println(member.spawnTime);  
        Serial.print("Death Time: ");
        Serial.println(member.deathTime);
    }
  } else {
    Serial.println("Failed To Connect To Server.");
  }
}

void loop() {
  if(rustplus.isConnected()) {
        rustplus.loop();
    } else {
        Serial.println("Not connected - attempting reconnect...");
        setup();
    }
}