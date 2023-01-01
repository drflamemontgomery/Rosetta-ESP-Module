# Rosetta-ESP-Module
Esp32 Module for the Rosetta project 


## Setup
Install Arduino CLI tools from https://arduino.github.io/arduino-cli/0.21/installation/

    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

## VS Code

Add the following lines to settings.json
```json
    "C_Cpp.updateChannel": "Insiders",
    "C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: WebKit, IndentWidth: 4,  ColumnLimit: 120}",
    "C_Cpp.intelliSenseEngine": "Tag Parser",
    "C_Cpp.default.includePath": [
    "/Applications/Arduino.app/Contents/Java/tools/**",
    "/Applications/Arduino.app/Contents/Java/hardware/arduino/**",
    "/Applications/Arduino.app/Contents/Java/libraries",
    "${workspaceRoot}",
    "/Users/your_user/Documents/Arduino/libraries"
]
```