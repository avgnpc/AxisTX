#pragma once

#include "../../config.h"

#ifdef HAS_OLED

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
public:
    DisplayManager();

    bool begin();
    void showSplash();
    void clear();
    void update();
    void printLine(uint8_t row, const char* label, int value);

private:
    Adafruit_SSD1306 _oled;
    void _drawCenteredText(const char* text, int16_t y, uint8_t size = 1);
};

#endif