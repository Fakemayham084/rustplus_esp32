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
#define MAX_ITEMS 48
#define MAX_MONUMENTS 30
#define RUSTPLUS_TIMEOUT 5000 

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

    typedef struct {
        char token[64];
        float x;
        float y;
    } RustMonument;

    /* typedef struct {
        int width;
        int height;
        uint8_t* jpg_image;    
        size_t jpg_image_size; 
        int margin;
        RustMonument monuments[MAX_MONUMENTS];
        int monument_count;
        char background[64];  
    }  RustMap; */

    struct StorageItem {
        int32_t item_id;
        int32_t quantity;
        bool item_is_blueprint;
    } __attribute__((aligned(4))); 

    struct EntityInfo {
        int32_t type;
        bool value;
        StorageItem items[MAX_ITEMS];
        volatile int32_t item_count;
        int32_t capacity;
        bool has_protection;
        int32_t protection_expiry;
    } __attribute__((aligned(4)));  

    RustPlus();

    void connect(const char* ip, uint16_t port, uint64_t steamId, uint32_t playerToken);
    void setUseProxy(bool useProxy);
    void loop();

    const ServerTime& getTime();
    const ServerInfo& getInfo();
    const TeamInfo& getTeam();
    //const RustMap& getMapInfo();
    const EntityInfo& getEntityInfo(uint32_t entityId);

    bool sendTeamMessage(const char* messageText);
    bool setEntityValue(uint32_t entityId, bool value);

private:
    WebSocketsClient webSocket;
    ServerInfo serverInfo;
    TeamInfo teamInfo;
    ServerTime serverTime;
    //RustMap mapInfo;
    EntityInfo entityInfo;

    bool useProxy;
	bool _isConnected = false;
    char serverIP[32];
    uint16_t port;
    uint64_t steamID;
    uint32_t playerTOKEN;
    int seq;
    int member_index;
    char decodedName[33];

    bool responseReceived;
    unsigned long requestStartTime;
    int expectedResponseType; 

    void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);
    bool sendRequest(rustplus_AppRequest request);
    void decode(const pb_byte_t* buff, size_t length);
    bool waitForResponse();

    static bool teamMemberCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool nameCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool decode_string_field(pb_istream_t *stream, const pb_field_t *field, void **arg);
    static bool itemCallback(pb_istream_t *stream, const pb_field_t *field, void **arg);
};
#endif