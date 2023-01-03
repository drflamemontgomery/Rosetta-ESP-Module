/*
    Wifi networks implements a state machine for finding and connecting to a wifi network.
    This state machine can be a used as a backend for a UART or internet based front end.

    Wifi scan based on Arduino Wifi sketch examples
*/

#include "wifiNetworks.hpp"
#include "WiFi.h"
#include "string.h"

enum WifiConnectionState {
    CHECK_SAVED_WIFI_CONNECTION,
    NO_WIFI_CONNECTION_SAVED,
    WIFI_CONNECTION_SAVED,
    UPDATE_WIFI_DETAILS,
    SEARCH_FOR_WIFI_NETWORK,
    SELECT_WIFI_NETWORK,
    CONNECT_TO_WIFI_NETWORK,
    SAVE_NETWORK_TO_EEPROM,
    BOOT_ROSETTA
};

// The state machine for connecting and saving a wifi network
void WifiUtilityStateMachine(WifiConnectionState state)
{
    switch (state) {
    case CHECK_SAVED_WIFI_CONNECTION:
        state = checkSavedWifiConnection();
        break;
    case NO_WIFI_CONNECTION_SAVED:
        state = SEARCH_FOR_WIFI_NETWORK;
        break;
    case WIFI_CONNECTION_SAVED:
        state = queryUpdateWifiDetails();
        break;
    case SEARCH_FOR_WIFI_NETWORK:
        state = searchForConnection();
        break;
    case SELECT_WIFI_NETWORK:
        state = queryNetworkNumber();
        break;
    case CONNECT_TO_WIFI_NETWORK:
        state = connectToNetwork();
        break;
    case SAVE_NETWORK_TO_EEPROM:
        state = saveNetworkToEeprom();
        break;
    case BOOT_ROSETTA:
        // Exit the state machine
        break;
    default:
        DebugSerial.println("Fell into default Wifi Utility State Machine. Booting to Rosetta ...");
        state = BOOT_ROSETTA;
        break;
    }
}

WifiConnectionState checkSavedWifiConnection(void)
{
    //** Read EEPROM and check if a state is stored
    if (valid_wifi_config) {
        return WIFI_CONNECTION_SAVED;
    }
    return NO_WIFI_CONNECTION_SAVED;
}

WifiConnectionState queryUpdateWifiDetails()
{
    // Prompt user for input
    string prompt = "Network $NETWORK saved. Update wifi network details (y/n)?";

    //**Get input

    if (input == 'y') {
        return SEARCH_FOR_WIFI_NETWORK;
    } else if (input == 'n') {
        return BOOT_ROSETTA;
    }
    // print invalid input
    return WIFI_CONNECTION_SAVED;
}

WifiConnectionState searchForConnection()
{
    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    DebugSerial.println("Scan done");
    if (n == 0) {
        DebugSerial.println("no networks found");
    } else {
        DebugSerial.print(n);
        DebugSerial.println(" networks found");
        DebugSerial.println("Nr | SSID                             | RSSI");
        for (int i = 0; i < n; ++i) {
            //** implement prompt of wifi networks that isn't debug
            debug_printWifiNetworks();
            delay(10);
        }
    }
    Serial.println("");

    return SELECT_WIFI_NETWORK;
}

WifiConnectionState queryNetworkNumber(int& networkNumber)
{
    // Prompt user for input
    string prompt = "Which network do you want to connect to (1-9)?";

    //**Get input

    // handle state connected to - check for out of range / invalid state,
    // print invalid input
    return CONNECT_TO_WIFI_NETWORK;
}

WifiConnectionState connectToNetwork() { return SAVE_NETWORK_TO_EEPROM; }

WifiConnectionState saveNetworkToEeprom()
{
    // Save the network ssid and hashed password to eeprom, potentially use min json

    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();
}

void debug_printWifiNetworks(int wifi_index)
{
    DebugSerial.printf("%2d", wifi_index + 1);
    DebugSerial.print(" | ");
    DebugSerial.printf("%-32.32s", WiFi.SSID(wifi_index).c_str());
    DebugSerial.print(" | ");
    DebugSerial.printf("%4d", WiFi.RSSI(wifi_index));
    DebugSerial.println();
}