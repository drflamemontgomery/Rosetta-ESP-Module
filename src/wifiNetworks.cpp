/*
    Wifi networks implements a state machine for finding and connecting to a wifi network.
    This state machine can be a used as a backend for a UART or internet based front end.

    Wifi scan based on Arduino Wifi sketch examples
*/

#include "wifiNetworks.hpp"
#include "WiFi.h"
#include "string.h"

enum WifiConnectionState {
    NO_WIFI_CONNECTION_SAVED,
    WIFI_CONNECTION_SAVED,
    UPDATE_WIFI_DETAILS,
    SEARCH_FOR_WIFI_NETWORK,
    BOOT_ROSETTA
}

// The state machine for connecting and saving a wifi network
void WifiUtilityStateMachine(WifiConnectionState state)
{
    switch (state) {
    case NO_WIFI_CONNECTION_SAVED:
        SearchForConnection();
        state = SEARCH_FOR_WIFI_NETWORK;
        break;
    case WIFI_CONNECTION_SAVED:
        QueryUpdateWifiDetails();
        break;
    case SEARCH_FOR_WIFI_NETWORK:
        SearchForConnection();
        break;
    }
}

void SearchForConnection()
{
    // Set WiFi to station mode and disconnect from an AP if it was previously connected.
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.printf("%2d", i + 1);
            Serial.print(" | ");
            Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial.print(" | ");
            Serial.printf("%4d", WiFi.RSSI(i));
            Serial.print(" | ");
            Serial.printf("%2d", WiFi.channel(i));
            Serial.print(" | ");
            switch (WiFi.encryptionType(i)) {
            case WIFI_AUTH_OPEN:
                Serial.print("open");
                break;
            case WIFI_AUTH_WEP:
                Serial.print("WEP");
                break;
            case WIFI_AUTH_WPA_PSK:
                Serial.print("WPA");
                break;
            case WIFI_AUTH_WPA2_PSK:
                Serial.print("WPA2");
                break;
            case WIFI_AUTH_WPA_WPA2_PSK:
                Serial.print("WPA+WPA2");
                break;
            case WIFI_AUTH_WPA2_ENTERPRISE:
                Serial.print("WPA2-EAP");
                break;
            case WIFI_AUTH_WPA3_PSK:
                Serial.print("WPA3");
                break;
            case WIFI_AUTH_WPA2_WPA3_PSK:
                Serial.print("WPA2+WPA3");
                break;
            case WIFI_AUTH_WAPI_PSK:
                Serial.print("WAPI");
                break;
            default:
                Serial.print("unknown");
            }
            Serial.println();
            delay(10);
        }
    }
    Serial.println("");

    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();
}

void QueryUpdateWifiDetails()
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