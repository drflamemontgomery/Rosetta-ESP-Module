#!/bin/bash

echo "Installing Arduino CLI ..."
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

echo "Check if Arduino CLI is installed and add Path variable updates TODO"

arduino-cli config init

echo "Add the following lines to ~/.arduino15/arduino-cli.yaml"
echo "board_manager:
 additional_urls:
  - https://arduino.esp8266.com/stable/package_esp8266com_index.json
  - https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"

echo "Adding ESP boards to config file"

echo "Searching for new packages"
arduino-cli core search esp32:esp32
arduino-cli core search esp8266:esp8266

echo "Installing the arduino cores"
echo "Installing SAMD ..."
arduino-cli core install arduino:samd

echo "Installing AVR ..."
arduino-cli core install arduino:avr

echo "Installing ESP8266 ..."
arduino-cli core install esp8266:esp8266

echo "Installing ESP32 ..."
arduino-cli core install esp32:esp32

