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

  RustPlus::ServerTime time = rustplus.getTime();
  
  Serial.println("\n=== TIME INFORMATION ===");
  Serial.println("Current Time: " + String(time.time));
  Serial.println("Sunrise: " + String(time.sunrise));
  Serial.println("Sunset: " + String(time.sunset));
  Serial.println("Day Length: " + String(time.dayLengthMinutes) + " minutes");
  Serial.println("Time Scale: " + String(time.timeScale) + "x");

  float timeToSunrise = fmod((time.sunrise - time.time + 24.0), 24.0);
  float timeToSunset = fmod((time.sunset - time.time + 24.0), 24.0);
  Serial.println("Time to sunrise: " + String(timeToSunrise) + " hours");
  Serial.println("Time to sunset: " + String(timeToSunset) + " hours");
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