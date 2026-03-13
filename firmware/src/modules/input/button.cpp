#include "button.h"

#define HOLD_THRESHOLD_MS 600

Button::Button(uint8_t pin)
    : _pin(pin), _lastState(HIGH), _state(HIGH),
      _lastDebounce(0), _pressedAt(0)
{}

void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
}

ButtonEvent Button::read() {
    bool raw = digitalRead(_pin);

    if (raw != _lastState) {
        _lastDebounce = millis();
    }
    _lastState = raw;

    if ((millis() - _lastDebounce) < BUTTON_DEBOUNCE_MS) {
        return ButtonEvent::NONE;
    }

    if (_state == HIGH && raw == LOW) {
        _state = LOW;
        _pressedAt = millis();
        return ButtonEvent::PRESSED;
    }

    if (_state == LOW && raw == LOW) {
        if ((millis() - _pressedAt) >= HOLD_THRESHOLD_MS) {
            _pressedAt = millis();
            return ButtonEvent::HELD;
        }
    }

    if (_state == LOW && raw == HIGH) {
        _state = HIGH;
    }

    return ButtonEvent::NONE;
}

bool Button::isPressed() const {
    return _state == LOW;
}