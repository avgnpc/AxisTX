#include "gimbal.h"
#include "../../config.h"

Gimbal::Gimbal(GimbalAxis x, GimbalAxis y)
    : _x(x), _y(y), _valX(0), _valY(0)
{}

void Gimbal::read() {
    _valX = _normalize(_x, analogRead(_x.pin));
    _valY = _normalize(_y, analogRead(_y.pin));
}

uint16_t Gimbal::valueX() const { return _valX; }
uint16_t Gimbal::valueY() const { return _valY; }
int      Gimbal::rawX()   const { return analogRead(_x.pin); }
int      Gimbal::rawY()   const { return analogRead(_y.pin); }

uint16_t Gimbal::_normalize(const GimbalAxis& axis, int raw) const {
    raw = constrain(raw, axis.raw_min, axis.raw_max);

    if (axis.type == GimbalType::THROTTLE) {
        return map(raw, axis.raw_min, axis.raw_max, CHANNEL_MIN, CHANNEL_MAX);
    }

    if (abs(raw - axis.raw_mid) <= axis.deadzone) {
        return CHANNEL_MID;
    }

    if (raw < axis.raw_mid) {
        return map(raw, axis.raw_min, axis.raw_mid - axis.deadzone, CHANNEL_MIN, CHANNEL_MID - 1);
    }

    return map(raw, axis.raw_mid + axis.deadzone, axis.raw_max, CHANNEL_MID + 1, CHANNEL_MAX);
}