#include QMK_KEYBOARD_H

enum custom_keycodes {
    NEXT_TAB = SAFE_RANGE,
   PREV_TAB
};


#define CTL_A   LCTL_T(KC_A)
#define SFT_Z   LSFT_T(KC_Z)
#define SFT_SLSH RSFT_T(KC_SLSH)
#define CTL_COLN  LCTL_T(KC_COLN)

#define U_NP KC_NO // key is not present
#define U_NU KC_NO // available but not used
#define __ KC_NO

enum layers { BASE, NAV, SYM };

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PREV_TAB:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_LEFT);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LALT);
            unregister_code(KC_LEFT);
        }
        break;
    case NEXT_TAB:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_RGHT);
        } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_LALT);
            unregister_code(KC_RGHT);
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    __ , KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    __ ,
    __ , KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,   KC_COLN,  __ ,
    __ , KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    __,__,__,__, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, __ ,
    __ , ALT_T(KC_TAB),  LT(NAV, KC_ESC), CMD_T(KC_ENT), __, __,    SFT_T(KC_SPC), LT(SYM, KC_BSPC), CTL_T(KC_DEL), __
  ),
  [NAV] = LAYOUT(
    __ ,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    __,
    __ ,  __ ,    __ ,    __ ,    __ ,    __ ,                 KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT, KC_CAPS, __ ,
    __ ,  __ ,    __ ,    __ ,    __ ,    __ ,    __,__,__,__, PREV_TAB,NEXT_TAB, KC_PGDN,  KC_PGUP,  __ ,   __,
    __ ,  __ ,    __ ,    __ ,    __ ,    __ ,                 KC_SPC,  KC_BSPC,  KC_DEL,   __
  ),
  [SYM] = LAYOUT(
    __ ,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,   __ ,
    __ ,  KC_TILD, KC_LCBR, KC_QUOT, KC_RCBR, KC_MINS,              __ ,    KC_EQL,    __ ,    __ ,    __ ,    __ ,
    __ ,  KC_BSLS, KC_LBRC, KC_DQT,  KC_RBRC, KC_PLUS, __,__,__,__, __ ,    __ ,    __ ,    __ ,    __ ,    __ ,
    __ ,  KC_PIPE, KC_UNDS, KC_LGUI,  __ ,                           KC_SPC,  __ ,    __ ,    __ ,    __
  ),
};


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
