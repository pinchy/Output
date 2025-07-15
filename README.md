# Output HAL Library

A simple Hardware Abstraction Layer (HAL) wrapper class for Arduino output pin functions.

## Author

Sebastien Eckersley-Maslin  
Date: 8 Sep 2019

## Overview

The `Output` class provides a convenient wrapper around Arduino's standard output pin functions, offering additional features like state tracking, output inversion, and semantic control methods.

## Features

- **State Management**: Internal state tracking with getter methods
- **Output Inversion**: Optional output inversion for active-low devices
- **Semantic Methods**: Intuitive `on()/off()` and `open()/close()` methods
- **Toggle Function**: Easy state toggling
- **State Verification**: Compare internal state with actual pin state

## Installation

1. Copy `Output.h` and `Output.cpp` to your Arduino project directory
2. Include the header in your sketch:
   ```cpp
   #include "Output.h"
   ```

## Usage

### Basic Usage

```cpp
#include "Output.h"

// Create output on pin 13, initial state LOW, not inverted
Output led(13, LOW, false);

void setup() {
    // Pin is already configured in constructor
}

void loop() {
    led.on();        // Turn on
    delay(1000);
    led.off();       // Turn off
    delay(1000);

    // Alternative toggle method
    led.toggle();
    delay(500);
}
```

### Advanced Usage

```cpp
// Create output with inversion (for active-low devices)
Output relay(8, LOW, true);  // Active low relay

// Or initialize later
Output motor;
motor.setPin(9, LOW, false);

// Check current state
if (motor.getState() == HIGH) {
    motor.off();
}

// Verify pin state matches internal state
int actualState = motor.checkState();
```

## API Reference

### Constructors

- `Output()` - Default constructor (requires `setPin()` call)
- `Output(int pin, bool initialState = false, bool invert = false)` - Initialize with pin configuration

### Configuration Methods

- `void setPin(int pin, bool initialState = false, bool invert = false)` - Set pin configuration
- `int getPin()` - Get the configured pin number

### Control Methods

- `void set(bool state)` - Set output to specific state
- `void on()` - Set output to ON/HIGH
- `void off()` - Set output to OFF/LOW
- `void open()` - Alias for `on()`
- `void close()` - Alias for `off()`
- `void toggle()` - Toggle current state

### State Methods

- `int getState()` - Get internal state variable
- `int checkState()` - Read actual pin state and update internal variable

## Constants

- `ON` - Defined as `HIGH`
- `OFF` - Defined as `LOW`

## Notes

- The `checkState()` method is useful for detecting if another service has modified the pin directly
- Output inversion is handled automatically when the `invert` parameter is set to `true`
- The class uses `bool` for state parameters but returns `int` for compatibility with Arduino constants

## Example Applications

- LED control
- Relay switching
- Motor control
- Valve operation
- Any digital output control requiring state management
