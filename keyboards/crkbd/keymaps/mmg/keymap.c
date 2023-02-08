#include "keymap.h"


enum layers { BASE, NAV, SYM, NUM  };

#define LAYOUT LAYOUT_split_3x6_3
#define __ KC_NO

#define GUI_A GUI_T(KC_A)
#define GUI_SCLN GUI_T(KC_SCLN)
#define SYM_S LT(SYM, KC_S)
#define SYM_L LT(SYM, KC_L)
#define NUM_D LT(NUM, KC_D)
#define NUM_K LT(NUM, KC_K)
#define NAV_F LT(NAV, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
			KC_ESC, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, __ ,
			__,     GUI_A,    SYM_S,   NUM_D,   NAV_F,   KC_G,    KC_H,    KC_J,    NUM_K,   SYM_L,  GUI_SCLN, __ ,
			__,     KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, __ ,
			__,     SFT_T(KC_BSPC), CTL_T(KC_TAB), CTL_T(KC_ENT), SFT_T(KC_SPC), __
		       ),
	[NAV] = LAYOUT(
			__, __ ,      __ ,     __ ,     __ ,     __ ,     __,      __,      __ ,     __,      __, __ ,
			__, __ ,      __ ,     __ ,     __ ,     __ ,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC, __ ,
			__, __ ,      __ ,     __ ,     __ ,     __ ,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  RESET, __ ,
			__ ,   KC_LSFT,  KC_LCTL, KC_RCTL, KC_RSFT, __
		      ),
	[SYM] = LAYOUT(
			__, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, __ ,
			__, __ ,     __ ,     __ ,     __ ,     __ ,      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, __ ,
			__, __ ,     __ ,     __ ,     __ ,     __ ,      KC_TILD, KC_DQT,  __,      __,      __ ,     __ ,
			__ ,   KC_LSFT,  KC_LCTL, KC_RCTL, KC_RSFT, __
		      ),
	[NUM] = LAYOUT(
			__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     __ ,
			__, __ ,      __,      __ ,     __,      __ ,     KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  __ ,
			__, __ ,      __ ,      __ ,     __,      __ ,    KC_GRV,  KC_QUOT, __ ,     __ ,     __ ,      __ ,
			__ ,   KC_LSFT,  KC_LCTL, KC_RCTL, KC_RSFT, __
		      ),
};
