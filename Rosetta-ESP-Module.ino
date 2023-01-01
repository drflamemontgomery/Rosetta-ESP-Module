#include "src/ota.hpp"

// Specify which serial port is used for debug statements
#define DebugSerial Serial
#define DEBUG
#define HostUART Serial2

void setup()
{
    ota_setup();
    HostUART.begin(115200);
}

void loop()
{
    // OTA update handler, must run for OTA updates to be enabled
    ota_handle();
}