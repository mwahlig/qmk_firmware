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
#define NAVSPC  LT(_NAV, KC_SPC)
#define HYPENT  LT(_HYPER, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer: Default typing layer
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Ctrl  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn  |       |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     *
     *         |------+------+-----------------------+------+------|
     *         | LAlt | LGUI | ******* Space ******* | RGUI | Code |
     *         |------+------+-----------------------+------+------|
     */
    [_QWERTY] = LAYOUT_60_hhkb(
        KC_GRV,  KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSLS, KC_DEL,
        KC_TAB,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,     KC_BSPC,
        KC_CESC, KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,     HYPENT,
        KC_LSFT, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_RSFT,     MO(_FN),
                 KC_LALT,     KC_LGUI,                                               NAVSPC,                                              KC_RGUI,     MO(_CODE)),

    /* Game Layer: same layout with a dedicated left Control
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Ctrl  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     * | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn  |       |   |
     * |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     *
     *         |------+------+-----------------------+------+------|
     *         | LAlt | LGUI | ******* Space ******* | RGUI | Code |
     *         |------+------+-----------------------+------+------|
     */
    [_GAME] = LAYOUT_60_hhkb(
        KC_ESC,  KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,     KC_BSPC,
        KC_LCTL, KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,     HYPENT,
        KC_LSFT, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_RSFT,     MO(_FN),
                 KC_LALT,     KC_LGUI,                                               KC_SPC,                                              KC_RGUI,     MO(_CODE)),

    /* Navigation Layer
     * |-------+-----+------+-----+-----+-----+-----+------+------+------+-------+-----+-----+-----+-----|
     * |       |     |      |     |     |     |     |      |      |      |       |     |     |     |     |
     * |-------+-----+------+-----+-----+-----+-----+------+------+------+-------+-----+-----+-----+-----|
     * |       |     | PgUp |     |     |     |     |      |      |      |       |     |     |     |     |
     * |-------+-----+------+-----+-----+-----+-----+------+------+------+-------+-----+-----+-----+-----|
     * |       |     | PgDn |     |     |     |     | Left | Down | Up   | Right |     |     |     |     |
     * |-------+-----+------+-----+-----+-----+-----+------+------+------+-------+-----+-----+-----+-----|
     * |       |     |      |     |     |     |     |      |      |      |       |     |     |     |     |
     * |-------+-----+------+-----+-----+-----+-----+------+------+------+-------+-----+-----+-----+-----|
     */
    [_NAV] = LAYOUT_60_hhkb(
        _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______, _______,
        _______, _______,     KC_PGUP,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
        _______, _______,     KC_PGDN,     _______,     _______,     _______,     _______,     KC_LEFT,     KC_DOWN,     KC_UP,       KC_RGHT,     _______,     _______,
        _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
                 _______,     _______,                                               _______,                                              _______,     _______),

    /* Function Layer
     * |-------+------+------+------+------+------+------+------+------+------+------+------+------+-------+-----|
     * |       | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  |       |     |
     * |-------+------+------+------+------+------+------+------+------+------+------+------+------+-------+-----|
     * |       | Mute | VoD  | VoU  |      |      |      |      |      |      |      | Up   |      |       |     |
     * |-------+------+------+------+------+------+------+------+------+------+------+------+------+-------+-----|
     * | Esc   | Prev | Play | Next |      |      |      |      |      |      | Left | Right|      |       |     |
     * |-------+------+------+------+------+------+------+------+------+------+------+------+------+-------+-----|
     * |       |      |      |      |      |      |      |      |      |      | Down |      |      |       |     |
     * |-------+------+------+------+------+------+------+------+------+------+------+------+------+-------+-----|
     */
    [_FN] = LAYOUT_60_hhkb(
        _______, KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      _______, _______,
        _______, KC_MUTE,     KC_VOLD,     KC_VOLU,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     KC_UP,       _______,     _______,
        KC_ESC,  KC_MPRV,     KC_MPLY,     KC_MNXT,     _______,     _______,     _______,     _______,     _______,     _______,     KC_LEFT,     KC_RGHT,     _______,
        _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     KC_DOWN,     _______,     _______,
                 _______,     _______,                                               _______,                                              _______,     _______),

    /* Hyper Layer
     * Hyper+F1..F24 are arranged across the alphas; bootloader remains on the left thumb key.
     */
    [_HYPER] = LAYOUT_60_hhkb(
        _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______, _______,
        _______, HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), _______,     _______,     _______,     _______,     _______,
        KC_ESC,  HYPR(KC_F9), HYPR(KC_F10), HYPR(KC_F11), HYPR(KC_F12), HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), _______,     _______,     _______,     _______,
        _______, HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20), HYPR(KC_F21), HYPR(KC_F22), HYPR(KC_F23), HYPR(KC_F24), _______,     _______,     _______,     _______,
                 _______,     _______,                                               KC_SPC,                                                _______,     _______),

    /* Code Layer
     * Encoder/lighting controls plus persistent default-layer selection.
     */
    [_CODE] = LAYOUT_60_hhkb(
        QK_BOOT, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX,
        XXXXXXX, QWERTY,      GAME,        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,
        XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
                 XXXXXXX,     XXXXXXX,                                              XXXXXXX,                                             XXXXXXX,     XXXXXXX)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
    }
    return true;
}
