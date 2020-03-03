#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 24

#define MATRIX_ROW_PINS { 0 }
#define MATRIX_COL_PINS {  9, 10, 11, 12, 14, 16, \
                           8,  7,  6,  5,  4,  3, \
                           2, 13, 15, 17, 16, 19, \
                          25, 26, 28, 27, 29, 30 }
#define IS_LEFT_HAND  true
#define USE_AS_I2C_SLAVE
