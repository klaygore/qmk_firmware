/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

//Tap Dance Declarations
enum {
  WIN_CAPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [WIN_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
//


// Layer shorthand
enum layer {
  _1U,
  _FN,
  _FN2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* custom Space with Arrows
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |   6    | 7      | 8      | 9      | 0      |  -     | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    |  [     | Q      | W      | E      | R      |   T    | Y      | U      | I      | O      |  P     | ]      | GUI \  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |SFTCAPS |  DEL   | A      | S      | D      | F      |   G    | H      | J      | K      | L      |  ;:    |  '"    |SFTENT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | HOME   | PG UP  | Z      | X      | C      | V      |   B    | N      | M      | ,      | .      |  /     |PRNTSCN | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | PG DN  | LALT   |FN      |  LGUI  |      SPACE      |      SPACE      |  LEFT  | UP     | RIGHT  | DOWN   | RCTRL  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_1U] = LAYOUT_ortho_5x14(
  KC_ESC,   		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,   		KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_RBRC, RGUI_T(KC_BSLS), \
  LSFT_T(KC_CAPS),  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, RSFT_T(KC_ENT),  \
  KC_HOME,  		KC_PGUP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_PSCR, KC_END, \
  KC_LCTL,  		KC_PGDN, KC_LALT, TT(1),   KC_LGUI, KC_SPC,  KC_SPC,   KC_SPC,   KC_SPC,  KC_LEFT, KC_UP,  KC_RGHT, KC_DOWN, KC_RCTL  \
 ),

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |  F7    |   F8   |   F9   |  F10   |   F11  |  F12   | CALC   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | PRV TR |        |  UP    |        |        |        |        |        |        |    7   |   8    |   9    |  \     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |  PLAY  |  LEFT  |  DOWN  |  RIGHT |        |        |        |        |        |    4   |   5    |    6   |  *     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | NXT TR |        |        |        |        |        |        |        |        |    1   |   2    |   3    |  -     |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | MUTE   |PRNTSCN |        |        |        | PAUSE  |        | ENTER  |        |    0   |  .     |        |  +     | FN2    |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN] = LAYOUT_ortho_5x14(
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_CALC, \
  KC_MPRV, _______,  KC_UP,   _______, _______, _______, _______, _______, _______, KC_7,  KC_8,    KC_9,    KC_PSLS, _______, \
  KC_MPLY, KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_4,  KC_5,    KC_6,    KC_PAST, KC_ENT, \
  KC_MNXT, _______,  _______, _______, _______, _______, _______, _______, _______, KC_1,  KC_2,    KC_3,    KC_PMNS, _______, \
  KC_MUTE, KC_PSCR,  _______, _______, _______, KC_PAUS, _______, KC_ENT,  _______, KC_0,  KC_DOT,  _______, KC_PPLS, MO(2)  \
 ),


/* FUNCTION2
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN2] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),
 
};
