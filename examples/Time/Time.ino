#include <RustPlusClient.h>

// Wi-Fi credentials
const char* ssid = "SSID";
const char* password = "PASS";
const char* serverIP = "IP";
uint16_t serverPort = PORT; // Example port
uint64_t steamID = STEAMID; // Your Steam ID
int32_t playerTOKEN = PLAYERTOKEN; // Your player token

// Create RustPlusClient object
RustPlusClient client(ssid, password);

void setup() {
    Serial.begin(115200);

    // Connects To Server
    client.begin(serverIP, serverPort, steamID, playerTOKEN);

    // Gets The Current Times Then Prints It To The Serial.
    String currentTime = rustPlus.getTime();
    Serial.println("Current Time: " + currentTime);
}

void loop() {
    // LOOP
    client.loop();
}