#include "display.h"

#ifdef HAS_OLED

DisplayManager::DisplayManager()
    : _oled(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET_PIN)
{}

bool DisplayManager::begin() {
    if (!_oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
        return false;
    }
    _oled.clearDisplay();
    _oled.display();
    return true;
}

void DisplayManager::showSplash() {
    _oled.clearDisplay();

    _oled.drawFastHLine(0, 0, OLED_WIDTH, SSD1306_WHITE);
    _oled.setTextColor(SSD1306_WHITE);

    _oled.setTextSize(3);
    _drawCenteredText("AXIS", 8);

    _oled.setTextSize(2);
    _drawCenteredText("TX", 36);

    _oled.drawFastHLine(0, 54, OLED_WIDTH, SSD1306_WHITE);
    _oled.setTextSize(1);
    _drawCenteredText("v" FIRMWARE_VERSION, 56);

    _oled.display();
}

void DisplayManager::clear() {
    _oled.clearDisplay();
    _oled.display();
}

void DisplayManager::update() {
    _oled.display();
}

void DisplayManager::printLine(uint8_t row, const char* label, int value) {
    _oled.setTextSize(1);
    _oled.setTextColor(SSD1306_WHITE);
    _oled.setCursor(0, row * 10);
    _oled.print(label);
    _oled.print(": ");
    _oled.print(value);
}

void DisplayManager::_drawCenteredText(const char* text, int16_t y, uint8_t size) {
    int16_t x1, y1;
    uint16_t w, h;
    _oled.setTextSize(size);
    _oled.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
    _oled.setCursor((OLED_WIDTH - w) / 2, y);
    _oled.print(text);
}

#endif