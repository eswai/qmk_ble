/*
Copyright 2019 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include <stdio.h>
#include "keymap_jp.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    LOWER,                /* Layer  keycode                       */
    RAISE,                /* Layer  keycode                       */
};


extern keymap_config_t keymap_config;

enum {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Layer related keycodes
#define ADJUST  MO(_ADJUST)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _QWERTY
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |  X  |  Q  |  W  |  E  |  R  |  T  |     |     |  Y  |  U  |  I  |  O  |  P  |  .  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |  Z  |  A  |  S  |  D  |  F  |  G  |  :  |  _  |  H  |  J  |  K  |  L  |  ;  |  /  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |     |     |     |  C  |  V  |  B  |  [  |  ]  |  N  |  M  |  ,  |     |     |     |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |LCMD |     |     |     |LOWER| SPC | TAB |LALT | ENT |RAISE|     |     |     |LCTL |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
  [_QWERTY] = LAYOUT(
    KC_X   ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,JP_DOT , \
    KC_Z   ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,JP_COLN,JP_UNDS,KC_H   ,KC_J   ,KC_K   ,KC_L   ,JP_SCLN,JP_SLSH, \
                            KC_C   ,KC_V   ,KC_B   ,JP_LBRC,JP_RBRC,KC_N   ,KC_M   ,JP_COMM     , \
    KC_LCMD,                        LOWER  ,KC_SPC ,KC_TAB ,KC_LALT,KC_ENT ,RAISE  ,                        KC_LCTL
  ),

/* _LOWER
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  | ESC |  {  |  [  |  (  |  <  |  :  |     |     |  7  |  8  |  9  |  +  |  *  |  =  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |     |  }  |  ]  |  )  |  >  |  ;  |     |  .  |  4  |  5  |  6  |  -  |  /  |  ,  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |     |     |     |     |     |     |     |  0  |  1  |  2  |  3  |     |     |     |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  | __  |     |     |     | __  | __  | __  | __  | __  | __  |     |     |     | __  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
  [_LOWER] = LAYOUT(
    KC_ESC ,JP_LCBR,JP_LBRC,JP_LPRN,JP_LT  ,JP_COLN,                KC_7   ,KC_8   ,KC_9   ,JP_PLUS,JP_ASTR,JP_EQL , \
    XXXXXXX,JP_RCBR,JP_RBRC,JP_RPRN,JP_GT  ,JP_SCLN,XXXXXXX,JP_DOT ,KC_4   ,KC_5   ,KC_6   ,JP_MINS,JP_SLSH,JP_COMM, \
                            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_0   ,KC_1   ,KC_2   ,KC_3        , \
    _______,                        _______,_______,_______,_______,_______,_______,                        _______
  ),

/* _RAISE
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |  |  |  ~  |  @  |  #  |  $  |  %  |     |     |     | UP  |     |HOME |     |     |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |  _  |  ^  |  &  |  !  |  ?  |  ¥  |     |     |LEFT |DOWN |RGHT | END |     |     |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  |     |     |     |  `  |  '  |  "  |     |     |     |     |     |     |     |     |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  | __  |     |     |     | __  | __  | __  | __  | __  | __  |     |     |     | __  |
  +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
  [_RAISE] = LAYOUT(
    JP_PIPE,JP_TILD,JP_AT  ,JP_HASH,JP_DLR ,JP_PERC,                XXXXXXX,KC_UP  ,XXXXXXX,KC_HOME,XXXXXXX,XXXXXXX, \
    JP_UNDS,JP_CIRC,JP_AMPR,JP_EXLM,JP_QUES,JP_YEN ,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,XXXXXXX,XXXXXXX, \
                            JP_GRV ,JP_QUOT,JP_DQT ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX     , \
    _______,                        _______,_______,_______,_______,_______,_______,                        _______
  ),

/* _ADJUST
  +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  |ADV_ID0|ADV_ID1|ADV_ID2|       |       |BATT_LV|       |       |ENT_DFU|       |       |DEL_ID0|DEL_ID1|DEL_ID2|
  +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  |ADV_ID3|ADV_ID4|       |       |       | RESET |       |       |ENT_SLP|       |       |       |DEL_ID3|DEL_ID4|
  +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
  +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
  |  __   |       |       |       |  __   |  __   |  __   |  __   |  __   |  __   |       |       |       |  __   |
  +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
*/
  [_ADJUST] = LAYOUT(
    ADV_ID0,ADV_ID1,ADV_ID2,XXXXXXX,XXXXXXX,BATT_LV,                ENT_DFU,XXXXXXX,XXXXXXX,DEL_ID0,DEL_ID1,DEL_ID2, \
    ADV_ID3,ADV_ID4,XXXXXXX,XXXXXXX,XXXXXXX,RESET  ,XXXXXXX,XXXXXXX,ENT_SLP,XXXXXXX,XXXXXXX,XXXXXXX,DEL_ID3,DEL_ID4, \
                            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX     , \
    _______,                        _______,_______,_______,_______,_______,_______,                        _______
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;
