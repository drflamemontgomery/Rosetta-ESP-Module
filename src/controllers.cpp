/*
  Implements the Controller class which each supported game controller is converted to.


*/

#include "controllers.hpp"

// Include the classes/drivers for each controller supported by Rosetta

class Controller()
{

    // Prototype
    Controller() { }

    // Gets the controller state from the internal class state, this is the last state that was received for the
    // controller
    GetState() { }

    // Polls the controller for the new state and updates the classes internal state
    Update(void) { }

} // Controller
