#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 4
#define THIS_DEVICE_COLS 14

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { 19, 17, 15, 13 }
#define MATRIX_COL_PINS { 25, 26, 27, 28, 29, 30, 31, 10, 11, 12, 14, 16, 18, 20 }

#define IS_LEFT_HAND  true
//#define USE_AS_I2C_SLAVE

#define CONFIG_NFCT_PINS_AS_GPIOS