#include QMK_KEYBOARD_H

#include "keymap.h"

enum layers { BASE, NAV, SYM, NUM};

#define __ KC_NO
#define CTL_A CTL_T(KC_A)
#define CTL_SCLN CTL_T(KC_SCLN)
#define NUM_S LT(NUM, KC_S)
#define SYM_D LT(SYM, KC_D)
#define NAV_F LT(NAV, KC_F)
#define SWAP MAGIC_SWAP_LCTL_LGUI
#define UNSWAP MAGIC_UNSWAP_LCTL_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    __ , KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  __,
    __ , CTL_A,    NUM_S,   SYM_D,   NAV_F,   KC_G,                KC_H,    KC_J,    KC_K,    KC_L,   CTL_SCLN, __,
    __ , KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,  __,__,__,__,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, __,
    __ , ALT_T(KC_ESC),  SFT_T(KC_BSPC), GUI_T(KC_TAB),  __, __,   GUI_T(KC_ENT), SFT_T(KC_SPC), ALT_T(KC_ESC), __
  ),
  [NAV] = LAYOUT(
    __ , __ ,      __ ,     __ ,     __ ,     __ ,                 KC_WWW_HOME, KC_WWW_BACK, KC_WWW_FORWARD, KC_WWW_FAVORITES,  SWAP, __,
    __ , __ ,      __,      __ ,     __ ,     __ ,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPSLOCK, __,
    __ , __ ,      __ ,     __ ,     __ ,     __ ,   __,__,__,__,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  __, __,
    __ , KC_LALT, KC_LSFT,  KC_LGUI,  __, __,   KC_RGUI, KC_RSFT, KC_RALT, __
  ),
  [SYM] = LAYOUT(
    __ , __ ,     __ ,     __ ,     __ ,     __ ,                   KC_TILD,  KC_AMPR, KC_ASTR, KC_PIPE, __, __,
    __ , __ ,     __ ,     __ ,     __ ,     __ ,                   KC_LPRN,  KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN, __,
    __ , __ ,     __ ,     __ ,     __ ,     __ ,    __,__,__,__,   KC_LCBR,  KC_EXLM, KC_AT,   KC_HASH, KC_RCBR, __,
    __ , KC_LALT, KC_LSFT,  KC_LGUI,  __, __,   KC_DQT, KC_QUOT, KC_GRV, __
  ),
  [NUM] = LAYOUT(
    __ , __ ,      __ ,     __ ,     __,      __ ,                  KC_EQL,   KC_7,    KC_8,    KC_9,    UNSWAP, __,
    __ , __ ,      __,      __ ,     __,      __ ,                  KC_LBRC,  KC_4,    KC_5,    KC_6,    KC_RBRC, __,
    __ , __ ,     __ ,      __ ,     __,      __ ,   __,__,__,__,   KC_0,     KC_1,    KC_2,    KC_3,    KC_BSLS, __,
    __ , KC_LALT, KC_LSFT,  KC_LGUI,   __, __,  KC_MINS, KC_UNDS, KC_PLUS, __
  ),
};

/*
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case NAV:
                oled_write_P(PSTR("NAV\n"), false);
                break;
            case SYM:
                oled_write_P(PSTR("SYM\n"), false);
                break;
            case NUM:
                oled_write_P(PSTR("NUM\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

*/
