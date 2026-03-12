#pragma once

#include <Arduino.h>

enum class GimbalType {
    THROTTLE,
    CENTERED,
};

struct GimbalAxis {
    uint8_t    pin;
    GimbalType type;
    int        raw_min;
    int        raw_mid;
    int        raw_max;
    uint8_t    deadzone;
};

class Gimbal {
public:
    Gimbal(GimbalAxis x, GimbalAxis y);

    void     read();
    uint16_t valueX() const;
    uint16_t valueY() const;
    int      rawX()   const;
    int      rawY()   const;

private:
    GimbalAxis _x;
    GimbalAxis _y;
    uint16_t   _valX;
    uint16_t   _valY;

    uint16_t _normalize(const GimbalAxis& axis, int raw) const;
};