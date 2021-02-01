/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
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


// Layer shorthand
enum layer {
  _MAIN,
  _GAME,
  _LOWER,
  _RAISE,
  _SYSTEM,
  _BSMOD,
  _SPMOD
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(6,KC_SPC):
      return TAPPING_TERM + 50;
    case LT(5,KC_BSPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 /* layer 0 MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |SFT TAB |   Q    |   W    |   E    |   R    |   T    |  HOME  |   Y    |   U    |   I    |   O    |   P    |   \    |  MUTE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |  ENTER |   A    |   S    |   D    |   F    |   G    |  END   |   H    |   J    |   K    |   L    |   ;:   |   '"   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |  LCTRL |   Z    |   X    |   C    |   V    |   B    |  PGUP  |   N    |   M    |   ,    |   .    |   /    |  UP    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | ESC    | SYSTEM |  ALT   |  LGUI  | BACKSP | LOWER  |  PGDN  | RAISE  | SPACE  |  RGUI  | RCRTL  |  LEFT  |  DOWN  | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_MAIN] = LAYOUT_ortho(
        LSFT_T(KC_TAB), KC_Q, 	KC_W,  	 KC_E,    KC_R,   	 KC_T,  KC_HOME, KC_Y,  KC_U,         KC_I,    KC_O,    KC_P,    RSFT_T(KC_BSLS), KC_MUTE,
        KC_ENT,		KC_A, 	KC_S, 	 KC_D,    KC_F,    	 KC_G,  KC_END,  KC_H,  KC_J, 	      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, 	KC_Z, 	KC_X, 	 KC_C, 	  KC_V,    	 KC_B,  KC_PGUP, KC_N,  KC_M, 	      KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
        KC_ESC, 	MO(4), 	KC_LALT, KC_LGUI, LT(5,KC_BSPC), MO(2), KC_PGDN, MO(3), LT(6,KC_SPC), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, 	  KC_RGHT
    ),

 /* layer 1 GAME
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |  TAB   |   Q    |   W    |   E    |   R    |   T    |  HOME  |   Y    |   U    |   I    |   O    |   P    |   \    |  MUTE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |  SHIFT |   A    |   S    |   D    |   F    |   G    |  END   |   H    |   J    |   K    |   L    |   ;:   |   '"   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |  LCTRL |   Z    |   X    |   C    |   V    |   B    |  PGUP  |   N    |   M    |   ,    |   .    |   /    |  UP    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | ESC    | SYSTEM |  ALT   |  LGUI  | BACKSP | LOWER  |  PGDN  | RAISE  | SPACE  |  RGUI  | RCRTL  |  LEFT  |  DOWN  | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_GAME] = LAYOUT_ortho(
        KC_TAB,  KC_Q, 	KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME, KC_Y,  KC_U,   KC_I,    KC_O,    KC_P,    RSFT_T(KC_BSLS), KC_MUTE,
        KC_LSFT, KC_A, 	KC_S, 	 KC_D,    KC_F,    KC_G,    KC_END,  KC_H,  KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z, 	KC_X, 	 KC_C, 	  KC_V,    KC_B,    KC_PGUP, KC_N,  KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
        KC_ESC,  MO(4), KC_LALT, KC_LGUI, KC_BSPC, MO(2),   KC_PGDN, MO(3), KC_SPC, KC_RGUI, KC_ENT,  KC_LEFT, KC_DOWN,		KC_RGHT
    ),

 /* layer 2 LOWER
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |   [    |   ]    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_LOWER] = LAYOUT_ortho(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

 /* layer 3 RAISE
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |   {    |   }    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_RAISE] = LAYOUT_ortho(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

 /* layer 4 SYSTEM
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        | LYR 0  | LYR 1  |        |        |        |        |RGBHUE+ |RGBMODE+|BRIGHT+ |        | PRINT  | RESET  |RGB TOG |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |RGBHUE- |RGBMODE-|BRIGHT- |        | PAUSE  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |  CAPS  |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_SYSTEM] = LAYOUT_ortho(
        _______, DF(0),   DF(1),   _______, _______, _______, _______, RGB_HUI, RGB_MOD, RGB_VAI, _______, KC_PSCR, RESET, RGB_TOG,
        _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_RMOD,RGB_VAD, _______, KC_PAUS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

 /* layer 5 BACKSPACE MOD
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |  F1    |        |   7    |   8    |   9    |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |    /   |   *    |   -    |   +    |        |  F2    |        |   4    |   5    |   6    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |        |        |        |        |        |        |  F4    |        |   1    |   2    |   3    |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |  F5    |        |   0    |   .    |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_BSMOD] = LAYOUT_ortho(
        _______, _______, _______, _______, _______, _______, KC_F1,   _______, KC_7,    KC_8,    KC_9,    _______, _______, _______,
        _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______, KC_F2,   _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F4,   _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, KC_F5,   _______, KC_0,    KC_DOT,  _______, _______, _______, _______
    ),

 /* layer 6 SPACE MOD
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |   (    |   )    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |  PREV  | PLAY   |  NEXT  |        |        |   -    |   +    |   _    |   =    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |  DEL   |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

    [_SPMOD] = LAYOUT_ortho(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,  _______,
        _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_MINS, KC_PLUS, KC_UNDS, KC_EQL,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};


layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
