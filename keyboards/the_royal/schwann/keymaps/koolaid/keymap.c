#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN,
  _NAV,
  _HYPER
};

enum schwann_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE
};

//Tap Dance Declarations
enum {
  TD_RST
};

void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset)
};


#define XXXXX KC_TRNS
#define HYPER MO(_HYPER)
#define NAV MO(_NAV)
#define FN MO(_FN)
#define CESC CTL_T(KC_ESC)
#define MEDIA_KEY_DELAY 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │Tab │ Q  │ W  │ E  │ R  │ T  │ Y  │ U  │ I  │ O  │ P  │BkSp│
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │LCtl│ A  │ S  │ D  │ F  │ G  │ H  │ J  │ K  │ L  │ ;  │ '  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │LSft│ Z  │ X  │ C  │ V  │ B  │ N  │ M  │ ,  │ .  │ /  │Entr│
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │Del │Gui │Alt │Lwr │         │Rse │Alt │Menu│Ctrl│
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */

  [_QWERTY] = LAYOUT_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
             KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   NAV,     FN,      HYPER
  ),

  /* Game
	* ,-----------------------------------------------------------------------------------.
	* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_GAME] = LAYOUT_mit(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
             KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   NAV,     FN,      HYPER
	),

  /* Lower Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │Esc │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │ 0  │    │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │ ~  │ !  │ @  │ #  │ $  │ %  │ ^  │ &  │ *  │ (  │ )  │ "  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │    │    │    │    │    │    │    │    │ `  │ [  │ ]  │ .  │
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │    │    │    │
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_LOWER] = LAYOUT_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    CESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
             _______, _______, _______, _______,      _______,     _______,    _______,    _______, _______
  ),

  /* Raise Layer
   * ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐
   * │    │    │    │    │    │    │    │    │    │    │ -  │    │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │CAPS│    │    │    │    │    │    │    │    │    │ _  │ \  │
   * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
   * │PrSc│    │    │    │    │    │    │    │    │ UP │    │ =  │
   * └────┼────┼────┼────┼────┼────┴────┼────┼────┼────┼────┼────┘
   *      │    │    │    │    │         │    │Left│Down│Rght│
   *      └────┴────┴────┴────┴─────────┴────┴────┴────┴────┘
   */
  [_RAISE] = LAYOUT_mit(
			KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
			CESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
			_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
               _______, _______, _______, _______,      _______,     _______, _______, _______, _______
  ),

  /* fn
	* ,-----------------------------------------------------------------------------------.
	* |DelWrd|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |      | ROLL |      |      |      |      |      |      |      | SHRUG| Enter|
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |    Space    |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_FN] = LAYOUT_mit(
			RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
			CESC,  KC_F11,  KC_F12,  KC_F13,  KC_F14,   KC_F15,   KC_F16,   KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
			_______,  RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
			          _______, _______, _______, _______,  _______,  _______, _______, _______, _______
	),

	/* Adjust (Lower + Raise)
	* ,-----------------------------------------------------------------------------------.
	* |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_ADJUST] = LAYOUT_mit(
			RESET  ,  QWERTY,    GAME,  _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
			_______, _______, _______,  _______, _______,  _______, _______, _______,  _______, _______,  _______,  _______,
			_______, _______, _______,  _______, _______,  _______, MU_MOD,  MU_TOG, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______
	),

	/* Navigation
	* ,-----------------------------------------------------------------------------------.
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_NAV] = LAYOUT_mit(
			_______,  KC_BTN1, KC_MS_U,  KC_BTN2, KC_WH_U,  KC_PGUP,  _______,  _______, _______, _______, _______, _______,
			CESC,  KC_MS_L, KC_MS_D,  KC_MS_R, KC_WH_D,  KC_PGDN, _______, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  _______,
			_______,  _______, _______, _______, _______,  _______,  _______,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,
			_______, _______, _______, _______,  _______,  _______, _______, _______, _______
	),

	/* Hyper (Lower + Raise)
	* ,-----------------------------------------------------------------------------------.
	* |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |             |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
	[_HYPER] = LAYOUT_mit(
			_______, HYPR(KC_F1), HYPR(KC_F2), HYPR(KC_F3), HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6), HYPR(KC_F7), HYPR(KC_F8), _______, _______, _______,
			_______, HYPR(KC_F9), HYPR(KC_F10), HYPR(KC_F11), HYPR(KC_F12), HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), _______, _______, _______,
			_______, HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20), HYPR(KC_F21), HYPR(KC_F22), HYPR(KC_F23), HYPR(KC_F24), _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______
	),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
  }
  return true;
};
