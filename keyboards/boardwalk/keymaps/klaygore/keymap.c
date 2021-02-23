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
  ESC_CAPS = 0,
  NXT_PRV
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [NXT_PRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT,KC_MPRV)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
//


// Layer shorthand
enum layer {
  _MAIN,
  _GAME,
  _LOWER,
  _RAISE,
  _BSPMOD,
  _SPMOD,
  _SYSTEM
};


enum custom_keycodes {
  RUN_RDP = SAFE_RANGE,
  RUN_CMD,
  RUN_CPM,
  RUN_CTP,
  RUN_NET
};


#define WRUN KC_LGUI(KC_R)



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(5,KC_SPC):
      return TAPPING_TERM + 50;
    case LT(4,KC_BSPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* custom Space with Arrows - layer 0 - this should be klaygore2 keymap
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |ESC/CAPS|   1    |   2    |   3    |   4    |   5    |  HOME  |   6    |   7    |   8    |   9    |   0    | GRAVE  | DELETE |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | SFTTAB |   Q    |   W    |   E    |   R    |   T    |  END   |   Y    |   U    |   I    |   O    |   P    |   \    | SHIFT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |  ENTER |   A    |   S    |   D    |   F    |   G    |  MUTE  |   H    |   J    |   K    |   L    |   ;:   |   '"   | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |  LCTRL |   Z    |   X    |   C    |   V    |   B    |  PGUP  |   N    |   M    |   ,    |   .    |   /    |  UP    | RCTRL  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | SEARCH |  FIND  |  ALT   |  LGUI  | BACKSP | LOWER  |  PGDN  | RAISE  | SPACE  |TERMINAL|  LGUI  |  LEFT  |  DOWN  | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_MAIN] = LAYOUT_ortho_5x14(
  TD(ESC_CAPS),   KC_1,       KC_2,    KC_3,    KC_4,          KC_5,    KC_HOME,  KC_6,  KC_7,          KC_8,       KC_9,    KC_0,    KC_GRV,  KC_DEL, \
  LSFT_T(KC_TAB), KC_Q,       KC_W,    KC_E,    KC_R,          KC_T,    KC_END,   KC_Y,  KC_U,          KC_I,       KC_O,    KC_P,    KC_BSLS, KC_RSFT, \
  KC_ENT,         KC_A,       KC_S,    KC_D,    KC_F,          KC_G,    KC_MUTE,  KC_H,  KC_J,          KC_K,       KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
  KC_LCTL,        KC_Z,       KC_X,    KC_C,    KC_V,          KC_B,    KC_PGUP,  KC_N,  KC_M,          KC_COMM,    KC_DOT,  KC_SLSH, KC_UP,   KC_RCTL, \
  KC_WSCH,        LCTL(KC_F), KC_LALT, KC_LGUI, LT(4,KC_BSPC), TT(2),   KC_PGDN,  TT(3), LT(5,KC_SPC),  LGUI(KC_T), KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT\
 ),

/* custom gaming - layer 1
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |ESC/CAPS|   1    |   2    |   3    |   4    |   5    |  HOME  |   6    |   7    |   8    |   9    |   0    | GRAVE  | DELETE |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |  TAB   |   Q    |   W    |   E    |   R    |   T    |  END   |   Y    |   U    |   I    |   O    |   P    |   \    | RSFT   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |SFTENTER|   A    |   S    |   D    |   F    |   G    |  MUTE  |   H    |   J    |   K    |   L    |   ;:   |   '"   | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |  LCTRL |   Z    |   X    |   C    |   V    |   B    |  PGUP  |   N    |   M    |   ,    |   .    |   /    |  UP    | RCTRL  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        | BACKSP | LOWER  |  PGDN  | RAISE  | SPACE  |  LALT  |  LGUI  |  LEFT  |  DOWN  | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_GAME] = LAYOUT_ortho_5x14(
  TD(ESC_CAPS),   KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,  KC_6,    KC_7,    KC_8,       KC_9,    KC_0,    KC_GRV,  KC_DEL, \
  KC_TAB, 	  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_END,   KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,    KC_BSLS, KC_RSFT, \
  KC_LSFT,        KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_MUTE,  KC_H,    KC_J,    KC_K,       KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
  KC_LCTL,        KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP,  KC_N,    KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_UP,   KC_RCTL, \
  KC_NO,          KC_NO,      KC_NO,   KC_NO,   KC_BSPC, TT(2),   KC_PGDN,  TT(3),   KC_SPC,  KC_LALT,    KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT\
 ),


/* LOWER - layer 2
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |   [    |   ]    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        | PAUSE  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |  F1    |  F2    |  F3    |  F4    |  F5    |  F6    |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |  F7    |  F8    |  F9    |  F10   |  F11   |  F12   |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_LOWER] = LAYOUT_ortho_5x14(
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______, _______, \
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* RAISE - layer 3
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |   {    |   }    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |PRINTSCR|        |SCRLLOCK|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |  F13   |  F14   |  F15   |  F16   |  F17   |  F18   |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |  F19   |  F20   |  F21   |  F22   |  F23   |  F24   |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | SYSTEM |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_RAISE] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, KC_SLCK, \
  _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, MO(6),   _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* BACKSPACE MOD - layer 4
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |    7   |   8    |   9    |        |        |NUMLOCK |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |    /   |   *    |   -    |   +    |        |        |        |    4   |   5    |   6    |        |        | CALC   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
 * |        |        |        |        |        |        |        |        |    1   |   2    |   3    |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+-----------------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |    0   |   .    |  NO    |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_BSPMOD] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______, _______, _______, _______,   \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,    KC_P8,     KC_P9,   _______, _______, KC_NLCK, \
  _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______, _______, _______, KC_P4,    KC_P5,     KC_P6,   _______, _______, KC_CALC, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,    KC_P2,     KC_P3,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,    KC_PDOT,   KC_NO,   _______, _______, _______ \
 ),

/* SPACE MODIFIER - layer 5
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |  VOL+  |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |  PREV  |  PLAY  |  NEXT  |        |        |   -    |   +    |   _    |   =    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
 * |        |        |        |        |  VOL-  |        |        |        |  MUTE  |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+-----------------+--------+--------+--------|
 * |        |        |        |        |  DEL   |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_SPMOD] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   \
  _______, _______, _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_MINS, KC_PLUS, KC_UNDS, KC_EQL,  _______, _______, \
  _______, _______, _______, _______, KC_VOLD, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),
 
 /* SYSTEM - layer 6
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |DefLayr1|        |        |        |        |        |        |        |        |        |DefLayr0|        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |RGBHUE+ |RGBMODE+|BRIGHT+ |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |RGBHUE- |RGBMODE-|BRIGHT- |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_SYSTEM] = LAYOUT_ortho_5x14(
  _______, DF(1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(0),    _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_MOD,  RGB_VAI, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_RMOD, RGB_VAD, _______ \
 )

 
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    
   case RUN_CMD:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(250);
        SEND_STRING("cmd");
        wait_ms(150);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
   case RUN_RDP:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(250);
        SEND_STRING("mstsc");
        wait_ms(150);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
   case RUN_CPM:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(250);
        SEND_STRING("compmgmt.msc");
        wait_ms(150);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
   case RUN_CTP:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(250);
        SEND_STRING("control");
        wait_ms(150);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;

   case RUN_NET:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(250);
        SEND_STRING("ncpa.cpl");
        wait_ms(150);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
   
    }
  }
  return true;
}
