#ifndef RUSTPLUS_H
#define RUSTPLUS_H

#include <WiFi.h>
#include <WebSocketsClient.h>
#include <string.h>
#include "rustplus.pb.h"
#include "pb.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include <pb_common.h>

#define MAX_MEMBERS 10
#define RUSTPLUS_TIMEOUT 5000  // Timeout for requests in milliseconds

class RustPlus {
public:

	bool isConnected() { return _isConnected; }
    void waitForConnection(unsigned long timeout = 10000);
		
    typedef struct {
        float dayLengthMinutes;
        float timeScale;
        float sunrise;
        float sunset;
        float time;
    } ServerTime;

    typedef struct {
        String name;
        String headerImage;
        String url;
        String map;
        uint32_t mapSize;
        uint32_t wipeTime;
        uint32_t players;
        uint32_t maxPlayers;
        uint32_t queuedPlayers;
        uint32_t seed;
        uint32_t salt;
        bool camerasEnabled;
    } ServerInfo;

    typedef struct {
        uint64_t steamID;
        char name[33];
        float x;
        float y;
        bool isOnline;
        uint32_t spawnTime;
        bool isAlive;
        uint32_t deathTime;
    } TeamMember;

    typedef struct {
        uint64_t leaderSteamID;
        TeamMember members[MAX_MEMBERS];
        int memberCount;
    } TeamInfo;

    // Constructor
    RustPlus();

    // Connection methods
    void connect(const char* ip, uint16_t port, uint64_t steamId, uint32_t playerToken);
    void setUseProxy(bool useProxy);
    void loop();

    // Synchronous information retrieval methods
    ServerTime getTime();
    ServerInfo getInfo();
    TeamInfo getTeam();

    // Team communication
    bool sendTeamMessage(const char* messageText);

private:
    WebSocketsClient webSocket;
    ServerInfo serverInfo;
    TeamInfo teamInfo;
    ServerTime serverTime;

    bool useProxy;
	bool _isConnected = false;
    char serverIP[32];
    uint16_t port;
    uint64_t steamID;
    uint32_t playerTOKEN;
    int seq;
    int member_index;
    char decodedName[33];

    // For synchronous requests
    bool responseReceived;
    unsigned long requestStartTime;
    int expectedResponseType; // 0 = none, 1 = time, 2 = info, 3 = team

    // Internal methods
    void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);
    bool sendRequest(rustplus_AppRequest request);
    void decode(const pb_byte_t* buff, size_t length);
    bool waitForResponse();

    // Protobuf callbacks
    static bool teamMemberCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool nameCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool decode_string_field(pb_istream_t *stream, const pb_field_t *field, void **arg);
};
#endif