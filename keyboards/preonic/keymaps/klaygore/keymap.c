/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


//Tap Dance Declarations
enum {
	
  PRV_NXT = 0,
  ESC_CAP,
  DBL_MOUS
  
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	
// Declarations for tap dance actions would go here, separated by commas, if you have them

[PRV_NXT] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
[ESC_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
[DBL_MOUS] = ACTION_TAP_DANCE_DOUBLE(KC_BTN1,KC_BTN2)
};


enum preonic_layers {
	
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _SPMOD
  
};

enum preonic_keycodes {
	
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
  
};


uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(7,KC_SPC):
      return TAPPING_TERM + 50;
    case LT(6,KC_BSPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty - layer 0
 * ,-----------------------------------------------------------------------------------.
 * |ESCCAP|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |DELETE|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |SFTENT|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | UP   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SEARCH|NUMPAD| Alt  | GUI  |BKSpc |Lower |Raise |Space | RCTL | LEFT | RIGHT| DOWN |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  TD(ESC_CAP),    KC_1,    KC_2,    KC_3,    KC_4,          KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    KC_DEL, \
  LSFT_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_Y,    KC_U,          KC_I,    KC_O,    KC_P,    RSFT_T(KC_BSLS),  \
  KC_ENT,         KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_H,    KC_J,          KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTL,        KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,    KC_N,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_UP,  \
  KC_WSCH,        TT(6),   KC_LALT, KC_LGUI, LT(6,KC_BSPC), LOWER,   RAISE,   LT(7,KC_SPC),  KC_RCTL, KC_LEFT, KC_RGHT, KC_DOWN  \
),

/* Colemak - layer 1
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |BACKSP|LOWER |Raise |SPACE | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,          KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,    KC_J,    KC_L,          KC_U,    KC_Y,    KC_SCLN, KC_DEL,  \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,          KC_D,    KC_H,    KC_N,          KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,    KC_K,    KC_M,          KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LT(6,KC_BSPC), LOWER,   RAISE,   LT(6,KC_SPC),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* not Dvorak anymore, now it is a gaming layer - layer 2
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |BACKSP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |SFTCAP|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SFTENT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DEL  |NUMPAD| Alt  | GUI  |Space |Lower |Raise |Space | Left | Down |  Up  |CT-RHT|
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid( \
  TD(ESC_CAP),    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RSFT_T(KC_BSLS),  \
  KC_SFTENT,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTL,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(DBL_MOUS),  \
  KC_WSCH,        TT(6),   KC_LALT, KC_LGUI, KC_BSPC, LOWER,   RAISE,   KC_SPC,  KC_RCTL, KC_LEFT, KC_RGHT, KC_DOWN  \
),

/* Lower - layer 3
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |  [   |  ]   |GRAVE |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |PAUSE |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  -   |   +  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      | PGUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | HOME | END  | PGDN |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_GRV, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS, _______, _______, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_PGUP, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_PGDN \
),

/* Raise - layer 4
 * ,-----------------------------------------------------------------------------------.
 * | VOL+ |      |      |      |      |      |      |      |      |  {   |  }   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PREV |      |      |      |      |      |      |      |      |      |PRTSCR|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PLAY |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  _   |   =  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | NEXT |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 | MUTE |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VOL- |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
  KC_MPRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,  \
  KC_MPLY, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_UNDS, KC_EQL,  _______, _______, _______, \
  KC_MNXT, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MUTE, _______, _______, _______, _______, \
  KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise) - layer 5
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |AudTog|      |MusCyc|      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Voice+|Aud on|MidiOn|Mus on|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Voice-|AudOff|MidOff|MusOff|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  _______, QWERTY, COLEMAK,  DVORAK,  _______, _______, _______, _______, _______, _______, _______, RESET,  \
  _______, _______, _______, _______, _______, AU_TOG,  _______, MU_MOD,  _______, _______, _______, _______, \
  _______, _______, _______, _______, MUV_IN,  AU_ON,   MI_ON,   MU_ON,   _______, _______, _______, _______, \
  _______, _______, _______, _______, MUV_DE,  AU_OFF,  MI_OFF,  MU_OFF,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* NUMPAD - layer 6
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   7  |   8  |  9   |  /   |NUMLCK|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |  6   |  *   |CALC  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |  3   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   .  |      |  +   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_NLCK,  \
  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_CALC, \
  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, KC_PPLS, _______  \
),

/* SPACE MODIFIER - layer 7
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | DEL  |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPMOD] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
