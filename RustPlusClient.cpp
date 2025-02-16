#include "RustPlusClient.h"
#include <queue>

RustPlusClient::RustPlusClient(const char* ssid, const char* password) {
    _ssid = ssid;
    _password = password;
    _seq = 0;
    _currentTime = "";
    _isConnected = false; // Initialize connection status flag
}

void RustPlusClient::begin(const char* serverIP, uint16_t serverPort, uint64_t steamID, int32_t playerTOKEN) {
    strncpy(_serverIP, serverIP, sizeof(_serverIP) - 1);
    _serverPort = serverPort;
    _steamID = steamID;
    _playerTOKEN = playerTOKEN;

    WiFi.begin(_ssid, _password);
    Serial.print("Connecting to Wi-Fi");
    unsigned long startMillis = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startMillis < 10000) { // 10-second timeout
        delay(500);
        Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected to Wi-Fi");
        connect();
    } else {
        Serial.println("\nFailed to connect to Wi-Fi");
    }
}

void RustPlusClient::loop() {
    _webSocket.loop();

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected, restarting...");
        delay(1000);
        ESP.restart();
    }

    // Retry sending queued messages if WebSocket is connected
    if (_isConnected && !_messageQueue.empty()) {
        retryQueuedMessages();
    }
}

void RustPlusClient::connect() {
    _webSocket.begin(_serverIP, _serverPort, "/game");
    Serial.println("Connecting To Server.");
    _webSocket.onEvent([this](WStype_t type, uint8_t *payload, size_t length) {
        this->webSocketEvent(type, payload, length);
    });
}

void RustPlusClient::webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {
    switch (type) {
        case WStype_DISCONNECTED:
            Serial.println("WebSocket disconnected");
            _isConnected = false; // Update connection status
            break;
        case WStype_CONNECTED: {
            Serial.println("Connected To Server!");
            _isConnected = true; // Update connection status
            fixGetTime();
            retryQueuedMessages();
            break;
        }
        case WStype_TEXT:
            Serial.printf("Received: %s\n", payload);
            break;
        case WStype_BIN:
            decodeResponse(payload, length);
            break;
        case WStype_ERROR:
            Serial.println("WebSocket error");
            _isConnected = false; // Update connection status
            break;
        case WStype_PONG:
            Serial.println("WebSocket pong received");
            break;
        case WStype_FRAGMENT:
            Serial.println("WebSocket fragment received");
            break;
    }
}

String RustPlusClient::getTime() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = _seq;
    request.playerId = _steamID;
    request.playerToken = _playerTOKEN;
    request.getTime = rustplus_AppEmpty_init_default;
    request.has_getTime = true;
    sendRequest(request);

    unsigned long startMillis = millis();
    while (_currentTime == "" && millis() - startMillis < 5000) {
        _webSocket.loop(); 
    }

    return _currentTime != "" ? _currentTime : "Error: Time not received";
}

void RustPlusClient::sendTeamMessage(const char* messageText) {
    if (!_isConnected) {
        // Add message to the queue if WebSocket is not connected
        _messageQueue.push(String(messageText));
        Serial.println("WebSocket not connected. Message queued for retry.");
        return;
    }

    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = _seq;
    request.playerId = _steamID;
    request.playerToken = _playerTOKEN;

    rustplus_AppSendMessage sendMessage = rustplus_AppSendMessage_init_zero;

    sendMessage.message.arg = (void*)messageText;
    sendMessage.message.funcs.encode = [](pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
        const char* text = (const char*)(*arg);
        return pb_encode_tag_for_field(stream, field) &&
               pb_encode_string(stream, (const uint8_t*)text, strlen(text));
    };
    request.sendTeamMessage = sendMessage;
    request.has_sendTeamMessage = true;
	
    Serial.println("SENT");
    sendRequest(request);
}

void RustPlusClient::retryQueuedMessages() {
    while (!_messageQueue.empty()) {
        String message = _messageQueue.front(); 
        _messageQueue.pop(); 
        sendTeamMessage(message.c_str()); 
    }
}

void RustPlusClient::fixGetTime() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = _seq;
    request.playerId = _steamID;
    request.playerToken = _playerTOKEN;
    request.getTime = rustplus_AppEmpty_init_default;
    request.has_getTime = true;
    sendRequest(request);
}

void RustPlusClient::sendRequest(rustplus_AppRequest request) {
    uint8_t buffer[1024];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    if (pb_encode(&stream, rustplus_AppRequest_fields, &request)) {
        _webSocket.sendBIN(buffer, stream.bytes_written);
        _seq++;
    } else {
        Serial.printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
    }
}

void RustPlusClient::decodeResponse(const pb_byte_t* buff, size_t length) {
    rustplus_AppMessage response = rustplus_AppMessage_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buff, length);

    if (!pb_decode(&stream, rustplus_AppMessage_fields, &response)) {
        Serial.printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        _currentTime = "Decoding failed";
        return;
    }

    if (response.response.has_time) {
        float decimalTime = response.response.time.time;
        int hour = (int)decimalTime;
        int minutes = (int)((decimalTime - hour) * 60);
        int seconds = (int)(((decimalTime - hour) * 60 - minutes) * 60);
        String period = (hour >= 12) ? "PM" : "AM";
        hour = (hour > 12) ? hour - 12 : (hour == 0 ? 12 : hour);
        char formattedTime[12];
        snprintf(formattedTime, sizeof(formattedTime), "%02d:%02d:%02d %s", hour, minutes, seconds, period.c_str());
        _currentTime = String(formattedTime);
    } else {
        _currentTime = "Time information not available.";
    }
}