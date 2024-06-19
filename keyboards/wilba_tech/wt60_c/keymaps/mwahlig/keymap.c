#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _GAME,
    _NAV,
    _FN,
    _HYPER,
    _CODE
};

enum keycodes {
	QWERTY = SAFE_RANGE,
	GAME
};

#define KC_CESC CTL_T(KC_ESC)
#define NAVSPC LT(_NAV, KC_SPC)
#define HYPENT LT(_HYPER, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_all(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,
      KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  HYPENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, MO(_FN),
      XXXXXXX, KC_LALT, KC_LGUI,                          NAVSPC,                          KC_RGUI, MO(_CODE), XXXXXXX),

  [_GAME] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  HYPENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, MO(_FN),
      XXXXXXX, KC_LALT, KC_LGUI,                          KC_SPC,                          KC_RGUI, MO(_CODE), XXXXXXX),

  [_NAV] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    \
      _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   \
      _______, _______, KC_PGDN, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,    \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     \
      XXXXXXX, _______, _______,                          _______,                          _______, XXXXXXX, XXXXXXX),

  [_FN] = LAYOUT_all(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______,    \
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______,   \
      KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______,    \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DOWN, _______, _______,     \
      XXXXXXX, _______, _______,                          _______,                          _______, XXXXXXX, XXXXXXX),

  [_HYPER] = LAYOUT_all(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    \
      _______, HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), _______, _______, _______, _______, _______,   \
      KC_ESC, HYPR(KC_F9), HYPR(KC_F10), HYPR(KC_F11), HYPR(KC_F12), HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), _______, _______, _______, _______,    \
      _______, HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20), HYPR(KC_F21), HYPR(KC_F22), HYPR(KC_F23), HYPR(KC_F24), _______, _______, _______, _______,     \
      XXXXXXX, QK_BOOT, _______,                          KC_SPC,                          _______, XXXXXXX, XXXXXXX),

  [_CODE] = LAYOUT_all(
      QK_BOOT, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, BR_DEC,  BR_INC,  XXXXXXX,  XXXXXXX,    \
      XXXXXXX, QWERTY, GAME, S1_DEC,  S1_INC,  S2_DEC,  S2_INC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ES_DEC,  ES_INC, XXXXXXX,   \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     \
      XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case (GAME):
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
    }
    return true;
}