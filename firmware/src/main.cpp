#include <Arduino.h>
#include "config.h"
#include "modules/input/gimbal.h"

#ifdef HAS_OLED
    #include "modules/display/display.h"
    DisplayManager display;
#endif

Gimbal leftStick(
    { PIN_JS_LEFT_X,  GimbalType::THROTTLE, GIMBAL_RAW_MIN, GIMBAL_RAW_MID, GIMBAL_RAW_MAX, 0 },
    { PIN_JS_LEFT_Y,  GimbalType::THROTTLE, GIMBAL_RAW_MIN, GIMBAL_RAW_MID, GIMBAL_RAW_MAX, 0 }
);
 
Gimbal rightStick(
    { PIN_JS_RIGHT_X, GimbalType::CENTERED, GIMBAL_RAW_MIN, GIMBAL_RAW_MID, GIMBAL_RAW_MAX, GIMBAL_DEADZONE },
    { PIN_JS_RIGHT_Y, GimbalType::CENTERED, GIMBAL_RAW_MIN, GIMBAL_RAW_MID, GIMBAL_RAW_MAX, GIMBAL_DEADZONE }
);

void setup() {
    Serial.begin(115200);

#ifdef HAS_OLED
    if (!display.begin()) {
        pinMode(LED_BUILTIN, OUTPUT);
        while (true) {
            digitalWrite(LED_BUILTIN, HIGH); delay(200);
            digitalWrite(LED_BUILTIN, LOW);  delay(200);
        }
    }
    display.showSplash();
    delay(2500);
#endif
}

void loop() {
        leftStick.read();
    rightStick.read();
 
    Serial.print("L:");
    Serial.print(leftStick.valueX());  Serial.print(",");
    Serial.print(leftStick.valueY());  Serial.print("  R:");
    Serial.print(rightStick.valueX()); Serial.print(",");
    Serial.println(rightStick.valueY());
 
    delay(50);
}