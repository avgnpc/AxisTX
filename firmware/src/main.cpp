#include <Arduino.h>
#include "config.h"

#ifdef HAS_OLED
    #include "modules/display/display.h"
    DisplayManager display;
#endif

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
}