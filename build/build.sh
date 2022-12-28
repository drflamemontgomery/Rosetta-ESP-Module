#!/bin/bash

export FQBN=esp32:esp32:esp-dev-module

arduino-cli compile --fqbn $FQBN Rosetta-esp-module