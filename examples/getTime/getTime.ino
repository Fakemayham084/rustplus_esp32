#include <RustPlus.h>

const char* ssid = "";
const char* password = "";

RustPlus rustPlus;

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    rustPlus.begin("", , , );

    delay(5000);

    String time = rustPlus.getTime();
    Serial.println("Current Time: " + time);
}

void loop() {
    rustPlus.loop();
}