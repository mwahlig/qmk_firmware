// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RS 1
#define _LW 2
#define _FN 3
#define _MD 4

#define _______ KC_TRNS
#define KC_SFTZ MT(MOD_LSFT, KC_Z)
#define KC_SFTS MT(MOD_RSFT, KC_SLSH)
#define KC_SFTB SFT_T(KC_BSPC)
#define KC_SFTC SFT_T(KC_SPC)
#define LOWER MO(_LW)
#define RAISE MO(_RS)
#define FUNCT MO(_FN)
#define KC_MDES LT(_MD, KC_ESC)
#define KC_FNTB LT(_FN, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Qwerty */
    KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,                        KC_Y,     KC_U,   KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,     KC_F,   KC_G,                        KC_H,     KC_J,   KC_K,     KC_L,     KC_SCLN,
    KC_SFTZ,  KC_X,     KC_C,     KC_V,   KC_B,                        KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SFTS,
    KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,  KC_BSPC,  KC_MDES,  KC_FNTB, KC_SPC,   RAISE,  KC_FNTB,    KC_QUOT,  KC_ENT
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_GRV,   KC_BSLS,  _______,  _______,  _______,                      _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4  e  F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    KC_TILD,  KC_PIPE,  _______,  _______,  _______,                      _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN] = LAYOUT(
    RESET,    KC_F9,    KC_F10 ,  KC_F11 ,  KC_F12 ,                      _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,
    _______,  KC_F5,    KC_F6  ,  KC_F7  ,  KC_F8  ,                      _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
    _______,  KC_F1,    KC_F2  ,  KC_F3  ,  KC_F4  ,                      _______,  KC_F1,    KC_F2,    KC_F3,    KC_F12,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_MD] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,                      _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  _______,
    _______,  _______,  _______,  _______,  _______,                      KC_MUTE,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_MPLY,
    _______,  _______,  _______,  _______,  _______,                      KC_MUTE,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
