#ifndef RUSTPLUSCLIENT_H
#define RUSTPLUSCLIENT_H

#include <WiFi.h>
#include <WebSocketsClient.h>
#include "rustplus.pb.h"
#include "pb.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include <pb_common.h>
#include <queue> // For message queue

class RustPlusClient {
public:
    // Constructor
    RustPlusClient(const char* ssid, const char* password);

    // Public methods
    void begin(const char* serverIP, uint16_t serverPort, uint64_t steamID, int32_t playerTOKEN);
    String getTime();
    void sendTeamMessage(const char* message);
    void loop();

private:
    // Private members
    const char* _ssid;          // Wi-Fi SSID
    const char* _password;      // Wi-Fi password
    char _serverIP[32];         // Server IP address
    uint16_t _serverPort;       // Server port
    uint64_t _steamID;          // Steam ID of the player
    int32_t _playerTOKEN;       // Player token for authentication
    int _seq;                   // Sequence number for requests
    WebSocketsClient _webSocket; // WebSocket client
    String _currentTime;        // Stores the current time received from the server
    bool _isConnected;          // Tracks WebSocket connection status
    std::queue<String> _messageQueue; // Queue for storing messages when WebSocket is disconnected

    // Private methods
    void connect();
    void webSocketEvent(WStype_t type, uint8_t *payload, size_t length);
    void sendRequest(rustplus_AppRequest request);
    void decodeResponse(const pb_byte_t* buff, size_t length);
    void fixGetTime();
    void retryQueuedMessages(); // Retry sending queued messages when WebSocket reconnects
};

#endif