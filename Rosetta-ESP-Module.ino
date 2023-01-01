#include "src/ota.hpp"

void setup(){
    ota_setup();
}

void loop(){
    // OTA update handler
    ota_handle();

}