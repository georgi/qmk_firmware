#include "keymap.h"
#include "print.h"


#define LAYOUT LAYOUT_split_3x5_3
#define __ KC_NO


#define MOD_A GUI_T(KC_A)
#define MOD_SCLN GUI_T(KC_SCLN)
#define MOD_S ALT_T(KC_S)
#define MOD_L ALT_T(KC_L)
#define MOD_D CTL_T(KC_D)
#define MOD_K CTL_T(KC_K)
#define MOD_F SFT_T(KC_F)
#define MOD_J SFT_T(KC_J)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
    MOD_A,    MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,  MOD_SCLN,
    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
    __,  LT(SYM, KC_BSPC), LT(NAV, KC_TAB), LT(NAV, KC_ENT), LT(SYM, KC_SPC), __
  ),
  [NAV] = LAYOUT(
    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_ESC,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC,
    KC_CAPS, __,      __,      __,      QK_BOOT,  __,      __,      __,      __,      KC_CAPS,
    __ , LT(SYM, KC_BSPC), KC_TAB, KC_ENT, LT(SYM, KC_SPC), __
  ),
  [SYM] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_TILD, KC_GRV,  KC_LCBR,  KC_RCBR, KC_QUOT, KC_DQT,  KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS,
    __,      __,      __,       __,      __,      KC_UNDS, KC_MINS, KC_PLUS,   KC_EQL,    __,
    __,  KC_BSPC, LT(NAV, KC_TAB), LT(NAV, KC_ENT), KC_SPC, __
  ),
};
