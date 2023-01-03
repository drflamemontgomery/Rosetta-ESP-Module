#ifndef __CONTROLLERS_HPP__
#define __CONTROLLERS_HPP__

Controller::Controller();
Controller::Controller(ControllerType cType);
Controller::GetState();
Controller::Update(void);

Controller::AttachDevice();
Controller::SetDeviceType(ControllerType cType);

#endif // __CONTROLLERS_HPP__