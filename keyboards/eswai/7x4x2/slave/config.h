#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 28

#define MATRIX_ROW_PINS { 23 }
#define MATRIX_COL_PINS { 31, 30, 29, 28, 27, 26, 25, 19, 17, 15, 13, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, 20, 22 }

#define IS_LEFT_HAND  true
#define USE_AS_I2C_SLAVE

#define CONFIG_NFCT_PINS_AS_GPIOS