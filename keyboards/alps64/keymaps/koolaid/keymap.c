#include "alps64.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FUNC 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    [_BASE] = LAYOUT_aek_103( \
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS, \
        KC_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,  \
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT, \
        KC_LCTL,KC_LALT,KC_LGUI,          KC_SPC,                     MO(_FUNC),KC_RALT, KC_RCTL
    ),

    [_FUNC] = LAYOUT_aek_103( \
        KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,KC_TRNS, KC_BSPC, \
        KC_TRNS, KC_TRNS,   KC_UP,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS, \
        KC_CAPS,KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,  \
        KC_LSFT,KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS, \
        KC_LCTL,KC_LALT,KC_LGUI,          KC_SPC,                     KC_TRNS, KC_RALT, KC_RCTL
    ),
};

void matrix_init_user(void) {

}