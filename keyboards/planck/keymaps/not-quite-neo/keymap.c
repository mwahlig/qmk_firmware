/*
NQN is not-quite-neo
A layout based on the
*/


#include QMK_KEYBOARD_H
#include "nqn-keys-on-quertz-de-latin1.h"
#include "nqn-basic-layout.h"


// Automatic number generation of important keywords
enum my_keycodes{
    // Layer numbers follow the neo2 terminology, i.e. base layer = layer 1
    L01 = 0,
    /* L02, SHIFT is not (yet) implemented as a fully customizable layer */
    L03,
    L04,
    L05,
    /* L06, UNSPECIFIED not (yet) needed */
    LFN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* L01 -> default: BASE LAYER
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |                                  |                                  | ENTER|
 * |------+                                  |                                  +------|
 * | L03  |             L01_LEFT             |             L01_RIGHT            | L03  |
 * |------+                                  |                                  +------|
 * | SHIFT|                                  |                                  | SHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTLR | GUI  | ALT  | L05  | L04  | SPACE| SPACE| L04  | L05  | ALTGR| LFN  | CTLR |
 * `-----------------------------------------------------------------------------------'
 */
[L01] = LAYOUT_planck_grid(
  KC_ESC,                 L01_LEFT_01,                                 L01_RIGHT_01,                 KC_ENTER,
  MO(L03),                L01_LEFT_02,                                 L01_RIGHT_02,                 MO(L03),
  KC_LSHIFT,              L01_LEFT_03,                                 L01_RIGHT_03,                 KC_RSFT,
  KC_LCTRL,KC_LGUI, KC_LALT, MO(L05), MO(L04), KC_SPC,  KC_SPC,  MO(L04), MO(L05), KC_RALT, MO(LFN), KC_RCTRL
),


/*
L02 -> MO(L02): SHIFT (as a layer not used, not defined, not reachable)
 */


/* L03 -> MO(L03): PROGRAMMING
 * ,-----------------------------------------------------------------------------------.
 * |      |                                  |                                  |      |
 * |------+                                  |                                  +------|
 * |      |             L03_LEFT             |             L03_RIGHT            |      |
 * |------+                                  |                                  +------|
 * |      |                                  |                                  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[L03] = LAYOUT_planck_grid(
  _______,                L03_LEFT_01,                                 L03_RIGHT_01,                 _______,
  _______,                L03_LEFT_02,                                 L03_RIGHT_02,                 _______,
  _______,                L03_LEFT_03,                                 L03_RIGHT_03,                 _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* L04 -> MO(L04): NAVIGATION AND NUMBERS
 * ,-----------------------------------------------------------------------------------.
 * |      |                                  |                                  |      |
 * |------+                                  |                                  +------|
 * |      |             L04_LEFT             |             L04_RIGHT            |      |
 * |------+                                  |                                  +------|
 * |      |                                  |                                  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | 0    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[L04] = LAYOUT_planck_grid(
  _______,                L04_LEFT_01,                                 L04_RIGHT_01,                 _______,
  _______,                L04_LEFT_02,                                 L04_RIGHT_02,                 _______,
  _______,                L04_LEFT_03,                                 L04_RIGHT_03,                 _______,
  _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, _______, _______
),


/* L05 -> MO(L05): ALTERNATE
 * ,-----------------------------------------------------------------------------------.
 * |      |                                  |                                  |      |
 * |------+                                  |                                  +------|
 * |      |             L05_LEFT             |             L05_RIGHT            |      |
 * |------+                                  |                                  +------|
 * |      |                                  |                                  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[L05] = LAYOUT_planck_grid(
  _______,                L05_LEFT_01,                                 L05_RIGHT_01,                 _______,
  _______,                L05_LEFT_02,                                 L05_RIGHT_02,                 _______,
  _______,                L05_LEFT_03,                                 L05_RIGHT_03,                 _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/*
L06 -> <TBD>: UNSPECIFIED
*/


/* LFN -> MO(FN): FUNCTION
 * ,-----------------------------------------------------------------------------------.
 * | RESET|                                  |                                  | BACKS|
 * |------+                                  |                                  +------|
 * |      |             L06_LEFT             |             L06_RIGHT            |INSERT|
 * |------+                                  |                                  +------|
 * |      |                                  |                                  |DELETE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |VOICE-|VOICE+|MUS ON|MUS OF| LIGHT|      |      | VOL+ | VOL- | MUTE |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LFN] = LAYOUT_planck_grid(
  RESET,                  L06_LEFT_01,                                 L06_RIGHT_01,                 KC_BSPC,
  _______,                L06_LEFT_02,                                 L06_RIGHT_02,                 KC_INS,
  _______,                L06_LEFT_03,                                 L06_RIGHT_03,                 KC_DEL,
  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______
)
};
