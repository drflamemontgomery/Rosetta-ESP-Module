#include "src/ota.hpp"

// Specify which serial port is used for debug statements
#define DebugSerial Serial
#define DEBUG
#define HostUART Serial2

const byte i2c_address = 0x20;

void setup()
{
    // Setup OTA wifi addresses and configuration
    ota_setup();

#ifdef DEBUG
    DebugSerial.begin(115200);
#endif

    // Setup UART communication to upstream processor
    HostUART.begin(115200);

    // Use the default I2C pins for I2C0. SDA on GPIO21, SCL on GPIO22.
    Wire.begin(i2c_address);
    Wire.onRequest(i2cRequest)
}

void loop()
{
    // OTA update handler, must run for OTA updates to be enabled
    ota_handle();
}

// Event request function called when a request is received
// More details of inter processor communication to implement
void i2cRequest(void) { Wire.send('a') }