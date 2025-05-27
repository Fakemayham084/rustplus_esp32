
# Rust+ API Wrapper for ESP32 (or any Wi-Fi-enabled board)

This repository provides an API wrapper for Rust+ that allows communication between an ESP32 (or any board with Wi-Fi and C++) and a Rust server. With this wrapper, you can easily interact with the Rust game server, including sending messages and retrieving server data like the current time.

![RustPlus Logo](https://github.com/Fakemayham084/rustplus_esp32/blob/main/rustpluslogo.png)

## Features
- Connects to a Rust server using the Rust+ API.
- Sends Messages to the Rust server.
- Retrieves the Current Time from the Rust server.
- Retrieves the Team Info from the Rust server.
- Retrieves the Server Info from the Rust server.
- Simple setup for integrating ESP32 or similar boards with Rust+.

## Requirements
- ESP32 (or any Wi-Fi-enabled board).
- Arduino IDE or another compatible environment for C++ development.
- Rust server with Rust+ API enabled.
- Steam ID and Player Token for authentication.

## Installation

1. Clone this repository to your local machine.
2. Open the project in the Arduino IDE or another compatible C++ environment.
3. Install the `RustPlus` library if it's not already included.
4. Modify the following parameters in the code:

   - **SSID**: Your Wi-Fi network name.
   - **PASS**: Your Wi-Fi network password.
   - **IP**: The server IP address where your Rust+ server is running.
   - **PORT**: The port for the Rust+ API.
   - **STEAMID**: Your Steam ID.
   - **PLAYERTOKEN**: Your player token for the Rust server.

## Code Examples

### 1. **Get Current Time**

This script connects to the server and gets the current time.

```cpp
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
```

### 2. **Send Message Script**

This script connects to the server and sends a message.

```cpp
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
    rustplus.sendTeamMessage("Hello From RustPlus");
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
```

### 3. **Gets Team Info**

This Script connects to the server and gets Team Info

```cpp
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
```

### 4. **Get Server Info**

This Script connects to the server and gets Server Info

```cpp
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
```

## Join Our Discord Community!

If you have questions or need support, feel free to join our Discord server using the invite code below:

[Discord Invite Link](https://discord.gg/pPyWFBSt2e)
