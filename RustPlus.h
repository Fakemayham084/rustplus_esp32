#ifndef RustPlus_h
#define RustPlus_h

#include <WiFi.h>
#include <WebSocketsClient.h>
#include "rustplus.pb.h"
#include "pb.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include <pb_common.h>

class RustPlus {
public:
    RustPlus();
    void begin(const char* ip, uint16_t port, uint64_t steamID, int32_t playerTOKEN);
    void loop();
    String getTime();
    void getTeamInfo();
    void getMap();
    void sendTeamMessage(const char* messageText);

private:
    WebSocketsClient webSocket;
    String currentTime;
    char serverIP[32];
    uint16_t serverPort;
    uint64_t steamID;
    int32_t playerTOKEN;
    int seq;

    void webSocketEvent(WStype_t type, uint8_t *payload, size_t length);
    void sendRequest(rustplus_AppRequest request);
    void decodeResponse(const pb_byte_t* buff, size_t length);
    static bool nameCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool teamMemberCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
};

#endif