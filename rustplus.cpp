#include "rustplus.h"

RustPlus::RustPlus() : 
    useProxy(false), port(0), steamID(0), playerTOKEN(0), seq(0), member_index(0),
    responseReceived(false), requestStartTime(0), expectedResponseType(0) {
    decodedName[0] = '\0';
    serverIP[0] = '\0';
}

void RustPlus::connect(const char* ip, uint16_t port, uint64_t steamId, uint32_t playerToken) {
    strncpy(serverIP, ip, sizeof(serverIP) - 1);
    serverIP[sizeof(serverIP) - 1] = '\0';
    this->port = port;
    this->steamID = steamId;
    this->playerTOKEN = playerToken;

    if (useProxy) {
        const char* proxyHost = "companion-rust.facepunch.com";
        String path = "/game/" + String(serverIP) + "/" + String(port);
        webSocket.beginSSL(proxyHost, 443, path.c_str(), "wss");
    } else {
        webSocket.begin(serverIP, port, "/");
    }
    
    webSocket.setReconnectInterval(5000);
    webSocket.onEvent([this](WStype_t type, uint8_t * payload, size_t length) {
        this->webSocketEvent(type, payload, length);
    });
}

bool RustPlus::waitForResponse() {
    requestStartTime = millis();
    responseReceived = false;
    
    while (!responseReceived && (millis() - requestStartTime < RUSTPLUS_TIMEOUT)) {
        webSocket.loop();
        delay(10);
    }
    
    return responseReceived;
}

const RustPlus::ServerTime& RustPlus::getTime() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getTime = rustplus_AppEmpty_init_default;
    request.has_getTime = true;
    
    expectedResponseType = 1;
    if (!sendRequest(request)) {
        return ServerTime();
    }
    
    return waitForResponse() ? serverTime : ServerTime();
}

const RustPlus::ServerInfo& RustPlus::getInfo() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;

    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getInfo = rustplus_AppEmpty_init_default;
    request.has_getInfo = true;
    
    expectedResponseType = 2;
    if (!sendRequest(request)) {
        return ServerInfo();
    }
    
    return waitForResponse() ? serverInfo : ServerInfo();
}

const RustPlus::TeamInfo& RustPlus::getTeam() {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;

    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getTeamInfo = rustplus_AppEmpty_init_default;
    request.has_getTeamInfo = true;
    
    expectedResponseType = 3;
    if (!sendRequest(request)) {
        return TeamInfo();
    }
    
    return waitForResponse() ? teamInfo : TeamInfo();
}

/* const RustPlus::RustMap& RustPlus::getMapInfo() {
    Serial.println("[DEBUG] getMapInfo: Preparing map request");
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getMap = rustplus_AppEmpty_init_default;
    request.has_getMap = true;

    expectedResponseType = 4;
    if (!sendRequest(request)) {
        Serial.println("[DEBUG] getMapInfo: sendRequest failed");
        return RustMap();
    }

    Serial.println("[DEBUG] getMapInfo: Waiting for map response...");
    return waitForResponse() ? mapInfo : RustMap();
} */

const RustPlus::EntityInfo& RustPlus::getEntityInfo(uint32_t entityId) {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;

    memset(&entityInfo, 0, sizeof(EntityInfo));
    
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.getEntityInfo = rustplus_AppEmpty_init_default;
    request.has_getEntityInfo = true;
    request.entityId = entityId;
    request.has_entityId = true;
    
    expectedResponseType = 3;
    if (!sendRequest(request)) {
        return entityInfo;
    }
    
    if (!waitForResponse()) {
        return entityInfo;
    }

    return entityInfo;
}

bool RustPlus::setEntityValue(uint32_t entityId, bool value) {
    rustplus_AppRequest request = rustplus_AppRequest_init_zero;
    request.seq = seq;
    request.playerId = steamID;
    request.playerToken = playerTOKEN;
    request.has_entityId = true;
    request.entityId = entityId;
    request.has_setEntityValue = true;
    request.setEntityValue.value = value;

    return sendRequest(request);
}

bool RustPlus::sendTeamMessage(const char* messageText) {
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

    return sendRequest(request);
}

bool RustPlus::sendRequest(rustplus_AppRequest request) {
    Serial.println("[DEBUG] sendRequest: Start");
    uint8_t buffer[1024];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    if (pb_encode(&stream, rustplus_AppRequest_fields, &request)) {
        Serial.printf("[DEBUG] sendRequest: Encoded %u bytes\n", stream.bytes_written);
        bool success = webSocket.sendBIN(buffer, stream.bytes_written);
        Serial.printf("[DEBUG] sendRequest: sendBIN returned %d\n", success);
        if (success) seq++;
        Serial.println("[DEBUG] sendRequest: Sent BIN");
        return success;
    } else {
        Serial.printf("[DEBUG] sendRequest: Encoding failed: %s\n", PB_GET_ERROR(&stream));
        return false;
    }
}

void RustPlus::webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    Serial.printf("[DEBUG] webSocketEvent: Type=%d, Length=%u\n", type, (unsigned)length);
    switch(type) {
        case WStype_CONNECTED:
            Serial.println("[DEBUG] Connected to WebSocket");
            _isConnected = true;
            break;
        case WStype_DISCONNECTED:
            Serial.println("[DEBUG] Disconnected from WebSocket");
            if (payload && length > 0) {
                Serial.print("[DEBUG] Disconnect reason: ");
                Serial.write(payload, length);
                Serial.println();
            }
            _isConnected = false;
            break;
        case WStype_BIN:
            Serial.printf("[DEBUG] Received binary payload of size: %u bytes\n", (unsigned)length);
            Serial.print("[DEBUG] First bytes: ");
            for (int i = 0; i < (length < 16 ? length : 16); ++i) {
                Serial.printf("%02X ", payload[i]);
            }
            Serial.println();
            decode(payload, length);
            break;
        case WStype_ERROR:
            Serial.println("[DEBUG] WebSocket Error");
            break;
        default:
            Serial.println("[DEBUG] webSocketEvent: Unknown type");
            break;
    }
}

void RustPlus::waitForConnection(unsigned long timeout) {
    Serial.println("[DEBUG] waitForConnection: Waiting for connection...");
    unsigned long start = millis();
    while(!_isConnected && (millis() - start < timeout)) {
        webSocket.loop();
        delay(100);
        Serial.print(".");
    }
    
    if(!_isConnected) {
        Serial.println("\n[DEBUG] Connection timeout!");
    } else {
        Serial.println("\n[DEBUG] Connected!");
    }
}

void RustPlus::decode(const pb_byte_t* buff, size_t length) {
    Serial.printf("[DEBUG] decode: Start, length=%u\n", (unsigned)length);

    entityInfo.item_count = 0;
    
    rustplus_AppMessage response = rustplus_AppMessage_init_zero;
    pb_istream_t stream = pb_istream_from_buffer(buff, length);

    response.response.info.name.funcs.decode = decode_string_field;
    response.response.info.headerImage.funcs.decode = decode_string_field;
    response.response.info.url.funcs.decode = decode_string_field;
    response.response.info.map.funcs.decode = decode_string_field;

    response.response.teamInfo.members.arg = this;
    response.response.teamInfo.members.funcs.decode = &teamMemberCallback;

    response.response.entityInfo.payload.items.arg = this;
    response.response.entityInfo.payload.items.funcs.decode = &itemCallback;

    if (!pb_decode(&stream, rustplus_AppMessage_fields, &response)) {
        Serial.printf("[DEBUG] decode: Decoding failed: %s\n", PB_GET_ERROR(&stream));
        return;
    }
    Serial.println("[DEBUG] decode: Decoding succeeded");

    if (response.response.has_time) {
        Serial.println("[DEBUG] decode: Handling time response");
        serverTime.dayLengthMinutes = response.response.time.dayLengthMinutes;
        serverTime.timeScale = response.response.time.timeScale;
        serverTime.sunrise = response.response.time.sunrise;
        serverTime.sunset = response.response.time.sunset;
        serverTime.time = response.response.time.time;

        if (expectedResponseType == 1) {
            responseReceived = true;
            expectedResponseType = 0;
        }

    } else if (response.response.has_info) {
        Serial.println("[DEBUG] decode: Handling info response");
        serverInfo.mapSize = response.response.info.mapSize;
        serverInfo.wipeTime = response.response.info.wipeTime;
        serverInfo.players = response.response.info.players;
        serverInfo.maxPlayers = response.response.info.maxPlayers;
        serverInfo.queuedPlayers = response.response.info.queuedPlayers;
        serverInfo.seed = response.response.info.seed;
        serverInfo.salt = response.response.info.salt;
        serverInfo.camerasEnabled = response.response.info.camerasEnabled;

        if (response.response.info.name.arg) {
            serverInfo.name = (char*)response.response.info.name.arg;
            free(response.response.info.name.arg);
        }
        if (response.response.info.headerImage.arg) {
            serverInfo.headerImage = (char*)response.response.info.headerImage.arg;
            free(response.response.info.headerImage.arg);
        }
        if (response.response.info.url.arg) {
            serverInfo.url = (char*)response.response.info.url.arg;
            free(response.response.info.url.arg);
        }
        if (response.response.info.map.arg) {
            serverInfo.map = (char*)response.response.info.map.arg;
            free(response.response.info.map.arg);
        }

        if (expectedResponseType == 2) {
            responseReceived = true;
            expectedResponseType = 0;
        }

    } else if (response.response.has_teamInfo) {
        Serial.println("[DEBUG] decode: Handling teamInfo response");
        teamInfo.leaderSteamID = response.response.teamInfo.leaderSteamId;

        if (expectedResponseType == 3) {
            responseReceived = true;
            expectedResponseType = 0;
        }

    } else if (response.response.has_entityInfo) {
        Serial.println("[DEBUG] decode: Handling entityInfo response");
 
        entityInfo.type = response.response.entityInfo.type;
        entityInfo.value = response.response.entityInfo.payload.value;
        entityInfo.has_protection = false;
        entityInfo.protection_expiry = 0;
        entityInfo.capacity = 0;

        switch (entityInfo.type) {
            case 0:
                Serial.printf("[DEBUG] Entity Type: Reserve\n");
                break;
            case 1:
                Serial.printf("[DEBUG] Entity Type: Switch\n");
                break;
            case 2:
                Serial.printf("[DEBUG] Entity Type: Alarm\n");
                break;
            case 3:
                Serial.printf("[DEBUG] Entity Type: Storage Monitor\n");
                entityInfo.has_protection = response.response.entityInfo.payload.hasProtection;
                entityInfo.protection_expiry = response.response.entityInfo.payload.protectionExpiry;
                entityInfo.capacity = response.response.entityInfo.payload.capacity;
                break;
            default:
                Serial.printf("[DEBUG] Entity Type: Unknown (%d)\n", entityInfo.type);
                break;
        }

        if (expectedResponseType == 3) {
            responseReceived = true;
            expectedResponseType = 0;
        }

    } else if (response.response.has_map) {
        Serial.println("[DEBUG] decode: Handling map response");
        Serial.println("[DEBUG] Map data received");

        if (expectedResponseType == 4) {
            responseReceived = true;
            expectedResponseType = 0;
        }

    } else {
        Serial.println("[DEBUG] decode: No known response type");
    }

    member_index = 0;
    Serial.printf("[DEBUG] decode end: entityInfo.item_count = %d\n", entityInfo.item_count);
}

void RustPlus::loop() {
	webSocket.loop();
}

bool RustPlus::teamMemberCallback(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    RustPlus* self = (RustPlus*)(*arg);
    if (self->member_index >= MAX_MEMBERS) return false;

    rustplus_AppTeamInfo_Member member = rustplus_AppTeamInfo_Member_init_zero;

    self->decodedName[0] = '\0';
    member.name.arg = self;
    member.name.funcs.decode = &RustPlus::nameCallback;

    if (!pb_decode(stream, rustplus_AppTeamInfo_Member_fields, &member)) {
        Serial.println("Failed to decode team member");
        return false;
    }

    self->teamInfo.members[self->member_index].steamID = member.steamId;
    strncpy(self->teamInfo.members[self->member_index].name, self->decodedName, 
            sizeof(self->teamInfo.members[self->member_index].name) - 1);
    self->teamInfo.members[self->member_index].name[sizeof(self->teamInfo.members[self->member_index].name) - 1] = '\0';
    self->teamInfo.members[self->member_index].x = member.x;
    self->teamInfo.members[self->member_index].y = member.y;
    self->teamInfo.members[self->member_index].isOnline = member.isOnline;
    self->teamInfo.members[self->member_index].spawnTime = member.spawnTime;
    self->teamInfo.members[self->member_index].isAlive = member.isAlive;
    self->teamInfo.members[self->member_index].deathTime = member.deathTime;
    self->member_index++;
    self->teamInfo.memberCount = self->member_index;

    return true;
}

bool RustPlus::nameCallback(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    RustPlus* self = (RustPlus*)(*arg);
    size_t len = stream->bytes_left;
    if (len >= sizeof(self->decodedName)) len = sizeof(self->decodedName) - 1;

    if (!pb_read(stream, (uint8_t*)self->decodedName, len)) {
        return false;
    }

    self->decodedName[len] = '\0';
    return true;
}

bool RustPlus::decode_string_field(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    size_t len = stream->bytes_left;
    char *str = (char*)malloc(len + 1);
    
    if (!str) return false;
    
    if (!pb_read(stream, (uint8_t*)str, len)) {
        free(str);
        return false;
    }
    
    str[len] = '\0';
    *arg = str;
    return true;
}

bool RustPlus::itemCallback(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    RustPlus* self = static_cast<RustPlus*>(*arg);
    Serial.println("[DEBUG] itemCallback: Processing item");
    
    if (self->entityInfo.item_count >= MAX_ITEMS) {
        Serial.println("[DEBUG] itemCallback: Maximum items reached");
        return false;
    }

    rustplus_AppEntityPayload_Item item = rustplus_AppEntityPayload_Item_init_zero;
    if (!pb_decode(stream, rustplus_AppEntityPayload_Item_fields, &item)) {
        Serial.println("[DEBUG] itemCallback: Failed to decode item");
        return false;
    }

    Serial.printf("[DEBUG] itemCallback: Decoded item - ID: %d, Quantity: %d, IsBlueprint: %d\n",
                 item.itemId, item.quantity, item.itemIsBlueprint);

    self->entityInfo.items[self->entityInfo.item_count].item_id = item.itemId;
    self->entityInfo.items[self->entityInfo.item_count].quantity = item.quantity;
    self->entityInfo.items[self->entityInfo.item_count].item_is_blueprint = item.itemIsBlueprint;
    
    self->entityInfo.item_count++;

    Serial.printf("[DEBUG] itemCallback: Total items now: %d\n", self->entityInfo.item_count);
    return true;
}