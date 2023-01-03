/*
  Implements the Controller class which each supported game controller is converted to.

  Implement a driver mapping in this class for each type of controller. The ESP32 only passes the controller data and
  doesn't do any remapping. The RP2040 does the remapping.

  ESP32 can handle a maximum of 9 bluetooth (classic and BLE) devices. 9 controllers will be statically allocated where
  newly paired controllers will be mapped to a controller not currently mapped to a bluetooth device.
*/

#include "controllers.hpp"

// Include the classes/drivers for each controller supported by Rosetta

enum ControllerType { JOYCON_R, JOYCON_L, SWITCH_PRO_CONTROLLER, XBOX_ONE, PS3, PS4, PS5 };

class Controller() {

    // Prototype
    Controller() {} Controller(ControllerType cType) {}

    // Gets the controller state from the internal class state, this is the last state that was received for the
    // controller
    GetState() {}

    // Polls the controller for the new state and updates the classes internal state
    Update(void) {}

    // Attach a controller to an available device
    AttachDevice() {}

    SetDeviceType(ControllerType cType) {

    }

}; // Controller
