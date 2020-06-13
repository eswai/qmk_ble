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

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_EQL,         KC_MINS, KC_Y,    KC_I,    KC_U,    KC_O,    KC_P,    KC_BSPC, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    MT(MOD_LCTL,KC_TAB),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    JP_QUOT,        KC_GRV,  KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN,    KC_ENT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    JP_LPRN,        JP_RPRN, KC_M,    KC_N,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_LALT, KC_LWIN, XXXXXXX,  LOWER,XXXXXXX,LSFT_T(KC_SPC),LSFT_T(KC_ENT),XXXXXXX,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

  [_LOWER] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    _______, _______, LCTL(KC_A),LCTL(KC_Y),LCTL(KC_S),   _______, _______,        _______, KC_COMM, KC_7,    KC_8,    KC_9,    JP_PLUS, JP_ASTR, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______,   LCTL(KC_Z),LCTL(KC_C),LCTL(KC_X), _______,        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    JP_MINS, JP_SLSH, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______,     LCTL(KC_V),LCTL(KC_V), JP_LBRC,         JP_RBRC, KC_0,    KC_1,    KC_2,    KC_3,    JP_EQL,  _______, \
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
    _______, _______, _______, _______, _______, _______, JP_LCBR,        JP_LCBR, _______, KC_RGHT, LCTL(KC_RGHT), KC_END,  _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______ \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
  ),

  [_ADJUST] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------+
    AD_WO_L, ADV_ID0, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, BATT_LV,        ENT_DFU, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    DELBNDS, DEL_ID0, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, RESET,          ENT_SLP, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______ \
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

  return true;
}

