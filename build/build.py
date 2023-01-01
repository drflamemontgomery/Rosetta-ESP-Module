#!/usr/bin/env python3

import json
import os

# Load the JSON config file
settings = json.loads(open(os.path.dirname(__file__) + "/build_config.json").read())

compile_command = "arduino-cli compile --fqbn " + settings["fqbn"]

os.system(compile_command)
