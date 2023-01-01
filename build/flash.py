#!/usr/bin/env python3

import json
import os
import argparse

# Setup the argument parser
parser = argparse.ArgumentParser(
    prog="Rosetta ESP32 Flash Command Utility",
    description="Flashes the ESP32 in the Rosetta via USB or OTA",
)
parser.add_argument("--usb", action="store_true")
args = parser.parse_args()


# Load the JSON config file
settings = json.loads(open(os.path.dirname(__file__) + "/build_config.json").read())

print(settings)

flash_command = (
    "arduino-cli compile --fqbn "
    + settings["fqbn"]
    + " port "
    + (settings["port_usb"] if args.usb else settings["port_ota"])
)

# Check whether the ports have been configured
if args.usb and settings["port_usb"] is "user-configured":
    os.system.exit("Setup the ESP32 USB port for flashing in build/build_config.json")
elif not args.usb and settings["port_ota"] is "user_configured":
    os.system.exit("Setup the ESP32 OTA port for flashing in build/build_config.json")

os.system(flash_command.split(" "))
