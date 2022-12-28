#!/bin/bash

export FQBN=esp32:esp32:esp-dev-module

arduino-cli upload --port $PORT --fqbn $FQBN Rosetta-esp-module