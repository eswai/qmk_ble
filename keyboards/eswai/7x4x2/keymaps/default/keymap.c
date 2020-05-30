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

// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;
// 薙刀式

enum custom_keycodes {
    AD_WO_L = NG_SAFE_RANGE, /* Start advertising without whitelist  */
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
  _NAGINATA,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Layer related keycodes
#define ADJUST  MO(_ADJUST)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    KC_ESC,  KC_COMM, KC_S,    KC_R,    KC_L,    KC_B,    KC_EQL,         KC_MINS, KC_Y,    KC_BSPC, KC_I,    KC_D,    KC_COMM, KC_BSLS, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    KC_TAB,  KC_W,    KC_H,    KC_T,    KC_E,    KC_M,    KC_QUOT,        KC_GRV,  KC_P,    KC_N,    KC_A,    KC_O,    KC_K,    KC_SCLN, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_V,    KC_SLSH, KC_Z,    KC_G,    KC_C,    KC_LPRN,        KC_RPRN, KC_U,    KC_F,    KC_J,    KC_X,    KC_Q,    KC_RCTL, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LALT, KC_LWIN, XXXXXXX,  LOWER,   KC_SPC,  KC_SPC,         KC_ENT,  KC_ENT,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

  [_LOWER] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, LCTL(KC_A),LCTL(KC_Y),LCTL(KC_S),   _______, _______,        _______, KC_COMM, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_ASTR, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______,   LCTL(KC_Z),LCTL(KC_C),LCTL(KC_X), _______,        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_SLSH, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______,     LCTL(KC_V),LCTL(KC_V), _______,        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQL,  _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______ \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

  [_RAISE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    _______, JP_TILD,JP_AT    ,JP_HASH, JP_DLR , JP_PERC, _______,        _______, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, JP_CIRC, JP_AMPR, JP_EXLM, JP_QUES, JP_BSLS, _______,        _______, _______, KC_LEFT, LCTL(KC_LEFT), KC_HOME, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, KC_RGHT, LCTL(KC_RGHT), KC_END,  _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______ \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

  [_ADJUST] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    _______, ADV_ID0, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, BATT_LV,        ENT_DFU, DEL_ID0, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, RESET,          ENT_SLP, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______ \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

    [_NAGINATA] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    _______, NG_Q   , NG_W   , NG_E   , NG_R   , NG_T    , _______,        _______, NG_Y   ,NG_U   , NG_I    , NG_O   , NG_P   , _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, NG_A   , NG_S   , NG_D   , NG_F   , NG_G    , _______,        _______, NG_H   ,NG_J   , NG_K    , NG_L   , NG_SCLN , _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, NG_Z    , NG_X  , NG_C   , NG_V   , NG_B    , _______,        _______, NG_N   ,NG_M   , NG_COMM,  NG_DOT , NG_SLSH , _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, NG_SHFT, NG_SHFT,        NG_SHFT2,NG_SHFT2, _______, _______, _______, _______, _______ \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
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

  // 薙刀式
  if (!process_naginata(keycode, record))
    return false;
  // 薙刀式

  return true;
}

void matrix_init_user(void) {
  // 薙刀式
  uint16_t ngonkeys[] = {KC_P, KC_N};
  uint16_t ngoffkeys[] = {KC_E, KC_M};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
  #ifdef NAGINATA_EDIT_MAC
  set_unicode_input_mode(UC_OSX);
  #endif
  #ifdef NAGINATA_EDIT_WIN
  set_unicode_input_mode(UC_WINC);
  #endif
}

