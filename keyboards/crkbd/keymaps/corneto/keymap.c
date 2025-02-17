// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
};

// For _QWERTY layer
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define OSL_FUN  OSL(_FUNC)
//#define OSM_AGR  OSM(MOD_RALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_SFT  OSM(MOD_LSFT)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define ACN_AGR  MT(MOD_RALT, ES_ACUT)

// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
  DF_DASH,
  JK_ESC,
  TN_NH,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tn_combo[] = {KC_N, ACN_AGR, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Add commonly used dash to home row
  [DF_DASH]    = COMBO(df_combo, KC_MINS),
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),
  // Add ñ character
  [TN_NH]    = COMBO(tn_combo, ES_NTIL),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LALT),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_SLSH, ACN_AGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT,   ES_AT, OSL_FUN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LCTL, GUI_ENT, LOW_TAB,   RSE_BSP ,KC_SPC  ,OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, ES_LBRC, ES_RBRC, ES_IQUE, ES_QUES,                         KC_7,    KC_8,    KC_9,    KC_0, ES_PERC,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, ES_IEXL, ES_EXLM, ES_LPRN, ES_RPRN,                         KC_4,    KC_5,    KC_6, ES_DQUO, ES_QUOT,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ES_DIAE, ES_TILD, ES_AMPR, ES_CIRC,  ES_DLR,                         KC_1,    KC_2,    KC_3, ES_HASH, ES_SCLN,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, LOWER,    KC_TRNS, KC_TRNS, KC_COLON
                                      //`--------------------------'  `--------------------------'
    ),


  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_DEL , XXXXXXX, ES_UNDS, ES_UNDS, KC_PGUP,                      ES_ASTR, XXXXXXX, XXXXXXX, KC_BSLS, ES_PIPE,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END,  ES_MINS,  ES_EQL, KC_PGDN,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_APP,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ES_LABK, ES_RABK, KC_COPY, KC_PSTE, ES_SCLN,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}
