#ifndef __WIFI_NETWORKS_HPP__
#define __WIFI_NETWORKS_HPP__

void WifiUtilityStateMachine();
void WifiUtilityStateMachine(WifiConnectionState state);
WifiConnectionState checkSavedWifiConnection(void);
WifiConnectionState searchForConnection();
WifiConnectionState queryNetworkNumber(void);
WifiConnectionState queryUpdateWifiDetails();
WifiConnectionState queryNetworkNumber();
WifiConnectionState connectToNetwork();
WifiConnectionState saveNetworkToEeprom();

void debug_printWifiNetworks(int wifi_index);

#endif // __WIFI_NETWORKS_HPP__