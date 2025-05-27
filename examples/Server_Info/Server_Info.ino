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
  
  delay(1000);

  rustplus.connect(SERVER_IP, PORT, STEAM_ID, PLAYER_TOKEN);

  rustplus.waitForConnection();
  
  if(rustplus.isConnected()) {
    RustPlus::ServerInfo info = rustplus.getInfo();
  
    Serial.println("\n=== SERVER INFORMATION ===");
    Serial.println("Name: " + info.name);
    Serial.println("Map: " + info.map + " (" + String(info.mapSize) + " size)");
    Serial.println("Players: " + String(info.players) + "/" + String(info.maxPlayers) + " (Queued: " + String(info.queuedPlayers) + ")");
    Serial.print("Wiped: ");
    Serial.println(info.wipeTime);
    Serial.println("Seed: " + String(info.seed) + " | Salt: " + String(info.salt));
    Serial.println("Cameras: " + String(info.camerasEnabled ? "Enabled" : "Disabled"));
    Serial.println("Header Image: " + info.headerImage);
    Serial.println("URL: " + info.url);

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