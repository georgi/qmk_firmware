// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/osdr modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public L
// oiioasdZZZZ
//
//
//
//
// icense along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "keymap.h"
#include "print.h"


#define LAYOUT LAYOUT_split_3x5_3
#define __ KC_NO
#define CTL_A CTL_T(KC_A)
#define CTL_SCLN CTL_T(KC_SCLN)
#define SYM_D LT(SYM, KC_D)
#define NUM_S LT(NUM, KC_S)
#define NAV_F LT(NAV, KC_F)
#define SWAP MAGIC_SWAP_LCTL_LGUI
#define UNSWAP MAGIC_UNSWAP_LCTL_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
    CTL_A,    NUM_S,   SYM_D,   NAV_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   CTL_SCLN,
    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
    ALT_T(KC_ESC),  SFT_T(KC_BSPC), GUI_T(KC_TAB), GUI_T(KC_ENT), SFT_T(KC_SPC), ALT_T(KC_ESC)
  ),
  [NAV] = LAYOUT(
    __ ,      __ ,     __ ,     __ ,     __ ,     LSG(KC_GRV), LAG(KC_LEFT), LAG(KC_RIGHT), LGUI(KC_GRV),  SWAP,
    __ ,      __,      __ ,     __ ,     __ ,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPSLOCK,
    __ ,      __ ,     __ ,     __ ,     __ ,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  RESET,
    KC_LALT, KC_LSFT,  KC_LGUI, KC_RGUI, KC_RSFT, KC_RALT
  ),
  [NUM] = LAYOUT(
    __ ,      __ ,     __ ,     __,      __ ,      KC_UNDS,   KC_7,    KC_8,    KC_9,    UNSWAP,
    __ ,      __,      __ ,     __,      __ ,      KC_LBRC,  KC_4,    KC_5,    KC_6,    KC_RBRC,
    __ ,     __ ,      __ ,     __,      __ ,      KC_0,     KC_1,    KC_2,    KC_3,    KC_BSLS,
    KC_LALT, KC_LSFT,  KC_LGUI,  KC_EQL,  KC_MINS,  KC_PLUS
  ),
  [SYM] = LAYOUT(
    __ ,     __ ,     __ ,     __ ,     __ ,       KC_TILD,  KC_AMPR, KC_ASTR, KC_PIPE, __,
    __ ,     __ ,     __ ,     __ ,     __ ,       KC_LCBR,  KC_DLR,  KC_PERC, KC_CIRC, KC_RCBR,
    __ ,     __ ,     __ ,     __ ,     __ ,       KC_LPRN,  KC_EXLM, KC_AT,   KC_HASH, KC_RPRN,
    KC_LALT, KC_LSFT,  KC_LGUI, KC_QUOT, KC_DQT, KC_GRV
  ),
};
