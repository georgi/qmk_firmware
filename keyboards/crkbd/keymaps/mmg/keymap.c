#include "keymap.h"


enum layers { BASE, NAV, SYM, NUM  };

#define LAYOUT LAYOUT_split_3x6_3
#define __ KC_NO
#define CTL_A CTL_T(KC_A)
#define CTL_SCLN CTL_T(KC_SCLN)
#define SYM_S LT(SYM, KC_S)
#define NUM_D LT(NUM, KC_D)
#define NAV_F LT(NAV, KC_F)
#define SWAP MAGIC_SWAP_LCTL_LGUI
#define UNSWAP MAGIC_UNSWAP_LCTL_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    __, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, __,
    __, CTL_A,    ALT_S,   KC_D,    NAV_F,   KC_G,    KC_H,    SYM_J,   NUM_K,   ALT_L,  CTL_T(KC_SCLN), __,
    __, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, __,
    KC_TAB,  KC_BSPC, GUI_T(KC_ESC), SFT_T(KC_ENT), KC_SPC, KC_TAB
  ),
  [NAV] = LAYOUT(
    __ , __ ,      __ ,     __ ,     __,      __ ,     LSG(KC_GRV), LAG(KC_LEFT), LAG(KC_RIGHT), LGUI(KC_GRV),  __, __,
    __ , KC_LCTL,  KC_LALT, __ ,     __,      __ ,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPSLOCK, __,
    __ , __ ,      __ ,     __ ,     __ ,     __ ,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  RESET, __,
    KC_TAB, KC_BSPC,  KC_LGUI, KC_RSFT, KC_SPC, KC_TAB
  ),
  [NUM] = LAYOUT(
    __ , KC_BSLS,  KC_7,    KC_8,    KC_9,    KC_EQL , __ ,      __ ,     __ ,     __,      __ ,  __,
    __ , KC_QUOT,  KC_4,    KC_5,    KC_6,    KC_PLUS, __ ,      __ ,     __ ,     KC_LALT, KC_LCTL, __,
    __ , KC_DQT,   KC_1,    KC_2,    KC_3,    KC_MINS, __ ,      __ ,     __ ,     __,      __ ,  __,
    KC_GRV,  KC_0, KC_LGUI, KC_RSFT, KC_SPC, KC_TAB
  ),
  [SYM] = LAYOUT(
    __ , KC_TILD,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN ,     __ ,   __ ,  __ ,  __ ,   __ ,__ ,
    __ , KC_LCBR,  KC_DLR,  KC_PERC, KC_CIRC, KC_RCBR ,     __ ,   __ ,  __ ,  KC_LALT, KC_LCTL, __,
    __ , KC_LBRC,  KC_EXLM, KC_AT,   KC_HASH, KC_RBRC ,     __ ,   __ ,  __ ,  __ ,   __ ,__ ,
    KC_PIPE,  KC_UNDS, KC_LGUI, KC_RSFT, KC_SPC, KC_TAB
  ),
};
