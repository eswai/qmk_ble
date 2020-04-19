#pragma once
#include "quantum.h"

#define LAYOUT( \
  L01, L02, L03, L04, L05, L06,            R01, R02, R03, R04, R05, R06, \
  L07, L08, L09, L10, L11, L12, L13,  R07, R08, R09, R10, R11, R12, R13, \
                 L14, L15, L16, L17,  R14, R15, R16, R17, \
  L18,                L19, L20, L21,  R18, R19, R20,                R21 \
  ) \
  { \
    { L01,   L02,   L03,   L04, L05, L06, KC_NO, KC_NO, R01, R02, R03, R04,   R05,   R06   }, \
    { L07,   L08,   L09,   L10, L11, L12, L13,   R07,   R08, R09, R10, R11,   R12,   R13   }, \
    { KC_NO, KC_NO, KC_NO, L14, L15, L16, L17,   R14,   R15, R16, R17, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, L18,   L19, L20, L21, KC_NO, KC_NO, R18, R19, R20, R21  , KC_NO, KC_NO }, \
  }

