#include "src/ota.h"

void setup(){
    ota_setup();
}

void loop(){
    // Handle for OTA flashing
    ArduinoOTA.handle();
}