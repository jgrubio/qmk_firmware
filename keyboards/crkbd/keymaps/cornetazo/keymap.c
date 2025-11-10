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
#define OSM_AGR  OSM(MOD_RALT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_SFT  OSM(MOD_LSFT)
#define RSE_BSP  LT(_RAISE, KC_BSPC)

// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  VIM_QUIT,
  VIM_SAVE
};

enum combos {
  DF_DASH,
  JK_ESC,
  TN_NH,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tn_combo[] = {KC_N, ES_ACUT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  // Add commonly used quote to home row
  [DF_DASH]    = COMBO(df_combo, ES_DQUO),
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
 OSM(MOD_LALT),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, ES_MINS, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, ES_COLN, OSL_FUN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LCTL, GUI_ENT, LOW_TAB,   RSE_BSP ,KC_SPC  ,OSM_SFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, ES_DIAE, ES_LBRC, ES_RBRC, ES_IQUE, ES_QUES,                         KC_7,    KC_8,    KC_9,    KC_0, ES_PERC,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, ES_IEXL, ES_EXLM, ES_LPRN, ES_RPRN,                         KC_4,    KC_5,    KC_6, ES_QUOT,  ES_GRV, OSM_AGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, ES_TILD, ES_AMPR, ES_CIRC,  ES_DLR,                         KC_1,    KC_2,    KC_3, ES_HASH,   ES_AT,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_TRNS, LOWER,    KC_TRNS, KC_TRNS, ES_DOT
                                      //`--------------------------'  `--------------------------'
    ),


  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, ES_UNDS, ES_PLUS, KC_PGUP,                      ES_ASTR, XXXXXXX, XXXXXXX, ES_SLSH, ES_PIPE,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END,  ES_BSLS,  ES_EQL, KC_PGDN,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_APP, OSM_AGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ES_LABK, ES_RABK, XXXXXXX, XXXXXXX, ES_SCLN,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM_AGR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PSCR, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

// Variables para detectar Ctrl+tecla presionado dos veces
static uint16_t ctrl_q_timer = 0;
static uint8_t ctrl_q_count = 0;
static uint16_t ctrl_g_timer = 0;
static uint8_t ctrl_g_count = 0;

// Función auxiliar para enviar comandos de Vim
static void send_vim_command(uint16_t command_key) {
    // Primero limpiamos los modificadores
    uint8_t mods = get_mods();
    clear_mods();
    send_keyboard_report();
    wait_ms(100);

    // Enviar ESC para salir del modo insert
    tap_code(KC_ESC);
    wait_ms(200);

    // Enviar comando :X!
    tap_code16(ES_COLN);  // :
    wait_ms(20);
    tap_code(command_key);
    wait_ms(20);
    tap_code16(ES_EXLM);  // !
    wait_ms(20);
    tap_code(KC_ENT);

    // Restaurar modificadores
    set_mods(mods);
}

// Función auxiliar para manejar doble pulsación de Ctrl+tecla
static bool handle_double_ctrl_key(uint16_t *timer, uint8_t *count, uint16_t command_key) {
    // Si el timer expiró, resetear contador
    if (timer_elapsed(*timer) > 500) {
        *count = 0;
    }

    (*count)++;
    *timer = timer_read();

    // Si se presionó dos veces
    if (*count >= 2) {
        *count = 0;
        send_vim_command(command_key);
    }

    // Bloquear la tecla para que no llegue a Vim
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_QUIT:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                tap_code16(ES_COLN);  // :
                tap_code(KC_Q);
                tap_code16(ES_EXLM);  // !
                tap_code(KC_ENT);
            }
            return false;

        case KC_Q:
            if (record->event.pressed && (get_mods() & MOD_MASK_CTRL)) {
                return handle_double_ctrl_key(&ctrl_q_timer, &ctrl_q_count, KC_Q);
            }
            break;

        case KC_G:
            if (record->event.pressed && (get_mods() & MOD_MASK_CTRL)) {
                return handle_double_ctrl_key(&ctrl_g_timer, &ctrl_g_count, KC_X);
            }
            break;
    }
    return true;
}

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
