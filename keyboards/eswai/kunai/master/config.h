#pragma once

#include "../board/custom_board.h"

#define THIS_DEVICE_ROWS 1
#define THIS_DEVICE_COLS 24

#define ENABLE_STARTUP_ADV_NOLIST

#define MATRIX_ROW_PINS { 0 }
#define MATRIX_COL_PINS { 30, 31, 19, 17, 15, 13, \
		                       7,  6,  5,  4,  3,  2, \
		                      14, 12, 11, 10,  9,  8, \
		                      24, 23, 22, 20, 18, 16 }

#define IS_LEFT_HAND  true
//#define USE_AS_I2C_SLAVE
