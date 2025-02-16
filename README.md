# Rust+ API Wrapper for ESP32 (or any Wi-Fi-enabled board)

This repository provides an API wrapper for Rust+ that allows communication between an ESP32 (or any board with Wi-Fi and C++) and a Rust server. With this wrapper, you can easily interact with the Rust game server, including sending messages and retrieving server data like the current time.

## Features
- Connects to a Rust server using the Rust+ API.
- Sends messages to the Rust server.
- Retrieves the current time from the Rust server.
- Simple setup for integrating ESP32 or similar boards with Rust+.

## Requirements
- ESP32 (or any Wi-Fi-enabled board).
- Arduino IDE or another compatible environment for C++ development.
- Rust server with Rust+ API enabled.
- Steam ID and Player Token for authentication.

## Installation

1. Clone this repository to your local machine.
2. Open the project in the Arduino IDE or another compatible C++ environment.
3. Install the `RustPlusClient` library if it's not already included.
4. Modify the following parameters in the code:

   - **SSID**: Your Wi-Fi network name.
   - **PASS**: Your Wi-Fi network password.
   - **IP**: The server IP address where your Rust+ server is running.
   - **PORT**: The port for the Rust+ API.
   - **STEAMID**: Your Steam ID.
   - **PLAYERTOKEN**: Your player token for the Rust server.

## Code Examples

### 1. **Send Message Script**

This script connects to the server and sends a message.

```cpp
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

    // Sends A Set Message
    client.sendTeamMessage("Hello From ESP32");
}

void loop() {
    // LOOP
    client.loop();
}
