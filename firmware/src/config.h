#pragma once

#ifndef FIRMWARE_VERSION
    #define FIRMWARE_VERSION "0.1.0"
#endif

#ifdef BOARD_PROMICRO
    #define PIN_JS_LEFT_X   A0
    #define PIN_JS_LEFT_Y   A1
    #define PIN_JS_RIGHT_X  A2
    #define PIN_JS_RIGHT_Y  A3
#endif

#ifdef HAS_OLED
    #define OLED_WIDTH     128
    #define OLED_HEIGHT    64
    #define OLED_I2C_ADDR  0x3C
    #define OLED_RESET_PIN -1
#endif

#define CHANNEL_COUNT  4
#define CHANNEL_MIN    0
#define CHANNEL_MID    500
#define CHANNEL_MAX    1000

#define GIMBAL_RAW_MIN  0
#define GIMBAL_RAW_MID  512
#define GIMBAL_RAW_MAX  1023
#define GIMBAL_DEADZONE 10