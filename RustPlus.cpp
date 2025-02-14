#include "RustPlus.h"

RustPlus::RustPlus() : seq(0) {}

void RustPlus::begin(const char* ip, uint16_t port, uint64_t steamIDc, int32_t playerTOKENc) {
    strncpy(serverIP, ip, sizeof(serverIP) - 1);
    serverPort = port;
    steamID = steamIDc;
    playerTOKEN = playerTOKENc;

    webSocket.begin(serverIP, serverPort, "/game");
    webSocket.onEvent([this](WStype_t type, uint8_t *payload, size_t length) {
        this->webSocketEvent(type, payload, length);
    });
}

void RustPlus::loop() {
    webSocket.loop();
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi disconnected, restarting...");
        delay(1000);
        ESP.restart();
    }
}

String RustPlus::getTime() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getTime = rustplus_AppEmpty_init_default;
    request.has_getTime = true;
    sendRequest(request);

    unsigned long startMillis = millis();
    while (currentTime == "" && millis() - startMillis < 10000) {
        webSocket.loop();
    }

    return currentTime != "" ? currentTime : "Error: Time not received";
}

void RustPlus::getTeamInfo() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getTeamInfo = rustplus_AppEmpty_init_default;
    request.has_getTeamInfo = true;
    sendRequest(request);
}

void RustPlus::getMap() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getMap = rustplus_AppEmpty_init_default;
    request.has_getMap = true;
    sendRequest(request);
}

void RustPlus::sendRequest(rustplus_AppRequest request) {
    uint8_t buffer[1024];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    if (pb_encode(&stream, rustplus_AppRequest_fields, &request)) {
        webSocket.sendBIN(buffer, stream.bytes_written);
        seq++;
    } else {
        Serial.printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
    }
}

bool RustPlus::nameCallback(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    char buffer[64];
    size_t bytes_read = stream->bytes_left;

    if (!pb_read(stream, (uint8_t*)buffer, bytes_read)) {
        return false;
    }

    buffer[bytes_read] = '\0';

    Serial.printf("Name: %s\n", buffer);

    return true;
}

bool RustPlus::teamMemberCallback(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    rustplus_AppTeamInfo_Member member = rustplus_AppTeamInfo_Member_init_zero;

    member.name.arg = NULL;
    member.name.funcs.decode = &nameCallback;

    if (!pb_decode(stream, rustplus_AppTeamInfo_Member_fields, &member)) {
        Serial.println("Failed to decode team member");
        return false;
    }

    float gridScale = 146.28571428571428f;
    float gridX = member.x * gridScale;
    float gridY = member.y * gridScale;

    Serial.printf("Member SteamID: %llu\n", member.steamId);
    Serial.printf("Name: ");
    Serial.printf("Position: (%.2f, %.2f)\n", member.x, member.y);
    Serial.printf("Grid Position: (%.2f, %.2f)\n", gridX, gridY);
    Serial.printf("Is Online: %s\n", member.isOnline ? "Yes" : "No");
    Serial.printf("Spawn Time: %u\n", member.spawnTime);
    Serial.printf("Is Alive: %s\n", member.isAlive ? "Yes" : "No");
    Serial.printf("Death Time: %u\n", member.deathTime);

    return true;
}

void RustPlus::sendTeamMessage(const char* messageText) {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;

    rustplus_AppSendMessage sendMessage = rustplus_AppSendMessage_init_zero;

    sendMessage.message.arg = (void*)messageText;
    sendMessage.message.funcs.encode = [](pb_ostream_t *stream, const pb_field_t *field, void * const *arg) {
        const char* text = (const char*)(*arg);
        return pb_encode_tag_for_field(stream, field) &&
               pb_encode_string(stream, (const uint8_t*)text, strlen(text));
    };
    request.sendTeamMessage = sendMessage;
    request.has_sendTeamMessage = true;

    sendRequest(request);
}

void RustPlus::decodeResponse(const pb_byte_t* buff, size_t length) {
    rustplus_AppMessage response = rustplus_AppMessage_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buff, length);

    response.response.teamInfo.members.arg = NULL;
    response.response.teamInfo.members.funcs.decode = &teamMemberCallback;

    if (!pb_decode(&stream, rustplus_AppMessage_fields, &response)) {
        Serial.printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        currentTime = "Decoding failed";
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
        currentTime = String(formattedTime);
    } else if (response.response.has_teamInfo) {
        rustplus_AppTeamInfo teamInfo = response.response.teamInfo;
        Serial.printf("Team Leader: %llu\n", teamInfo.leaderSteamId);
    } else {
        currentTime = "Time information not available.";
    }
}

void RustPlus::webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {
    switch (type) {
        case WStype_DISCONNECTED:
            Serial.println("WebSocket disconnected");
            break;
        case WStype_CONNECTED:
            Serial.println("WebSocket connected");
            break;
        case WStype_TEXT:
            Serial.printf("Received: %s\n", payload);
            break;
        case WStype_BIN:
            decodeResponse(payload, length);
            break;
        case WStype_ERROR:
            Serial.println("WebSocket error");
            break;
    }
}