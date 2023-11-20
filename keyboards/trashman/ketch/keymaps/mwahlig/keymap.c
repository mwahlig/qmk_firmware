/* 
Copyright 2021 Evan Sailer, Jetpacktuxedo, & QMK Firmware

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_RAISE,
	_LOWER,
	_NAV, 
	_HYPER
};

#define KC_CESC CTL_T(KC_ESC)
#define LOWERSP LT(_LOWER, KC_SPC)
#define RAISESP LT(_RAISE, KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAVSPC LT(_NAV, KC_SPC)
#define HYPENT LT(_HYPER, KC_ENT)
#define NAV MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_all( /* Qwerty */
     KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    KC_CESC,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   HYPENT,
    KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_BSLS, MOD_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,   MO(1),            LOWER,  NAVSPC,            RAISE, KC_TRNS, KC_TRNS,  KC_TRNS
  ),
  [_LOWER] = LAYOUT_all( /* Number+Symbol Layer */
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,  KC_END
  ),
  [_RAISE] = LAYOUT_all( /* Shifted Layer */
    KC_GRV ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
    QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12, KC_TRNS, KC_LCBR, KC_RCBR, KC_QUOT, KC_PIPE,
    KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_HOME, KC_PGDN,  KC_END
  ),
  [_NAV] = LAYOUT_all( /* Shifted Layer */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_HOME,  KC_PGDN,  KC_END
  ),
  [_HYPER] = LAYOUT_all( /* Shifted Layer */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    QK_BOOT, KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_DQUO, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PGUP, KC_PIPE,
    KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_HOME, KC_PGDN,  KC_END
  )
};
