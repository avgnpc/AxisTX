#pragma once

#include <Arduino.h>

#define BUTTON_DEBOUNCE_MS 30

enum class ButtonEvent {
    NONE,
    PRESSED,
    HELD,
};

class Button {
public:
    Button(uint8_t pin);

    void        begin();
    ButtonEvent read();
    bool        isPressed() const;

private:
    uint8_t       _pin;
    bool          _lastState;
    bool          _state;
    unsigned long _lastDebounce;
    unsigned long _pressedAt;
};