/* Copyright 2018 Jumail Mundekkat
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

// Establishes tap dance keys
enum {
  SPC_ENT = 0,
  SP_PUNC,
  NXT_PRV,
  ENT_EQL,
  CAP_ESC,
  MIN_GRV,
  NML_PLS,
  DBL_Y,
  DBL_MOUS,
  TRI_P,
  TRI_Y,
  QUAD_HOME,
  QUAD_PLUS,
  QUAD_F22
};


void TRI_P_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_P);
	}
    if (state->count == 2) {
        register_code (KC_LSFT);
        register_code (KC_P);
	}
     if (state->count == 3) {
        register_code (KC_LCTRL);
		register_code (KC_P);
    } else {}
}

void TRI_P_reset (qk_tap_dance_state_t *state, void *user_data) {
        unregister_code (KC_P);
        unregister_code (KC_LSFT);
        unregister_code (KC_LCTL);
}

void TRI_Y_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_Y);
	}
    if (state->count == 2) {
        register_code (KC_LSFT);
        register_code (KC_Y);
	}
     if (state->count == 3) {
        register_code (KC_LCTRL);
		register_code (KC_Y);
    } else {}
}

void TRI_Y_reset (qk_tap_dance_state_t *state, void *user_data) {
        unregister_code (KC_Y);
        unregister_code (KC_LSFT);
        unregister_code (KC_LCTL);
}

void QUAD_HOME_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_HOME);
	}
    if (state->count == 2) {
        register_code (KC_LSFT);
        register_code (KC_HOME);
	}
    if (state->count == 3) {
        register_code (KC_LCTRL);
		register_code (KC_HOME);
    }
    if (state->count == 4) {
        register_code (KC_LALT);
		register_code (KC_HOME);
    }
	if (state->count == 5) {
        register_code (KC_LSFT);
		register_code (KC_LCTRL);
		register_code (KC_HOME);
    }
	else {}
}

void QUAD_HOME_reset (qk_tap_dance_state_t *state, void *user_data) {

        unregister_code (KC_HOME);
        unregister_code (KC_LSFT);
        unregister_code (KC_LCTL);
		unregister_code (KC_LALT);
}

void QUAD_F22_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_F22);
	}
    if (state->count == 2) {
        register_code (KC_LSFT);
        register_code (KC_F22);
	}
    if (state->count == 3) {
        register_code (KC_LCTRL);
		register_code (KC_F22);
    }
    if (state->count == 4) {
        register_code (KC_LALT);
		register_code (KC_F22);
    }
	if (state->count == 5) {
        register_code (KC_LSFT);
		register_code (KC_LCTRL);
		register_code (KC_F22);
    }
	else {}
}

void QUAD_F22_reset (qk_tap_dance_state_t *state, void *user_data) {

        unregister_code (KC_F22);
        unregister_code (KC_LSFT);
        unregister_code (KC_LCTL);
		unregister_code (KC_LALT);
}

void QUAD_PLUS_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_PPLS);
	}
    if (state->count == 2) {
        register_code (KC_LSFT);
        register_code (KC_PPLS);
	}
    if (state->count == 3) {
        register_code (KC_LCTRL);
		register_code (KC_PPLS);
    }
    if (state->count == 4) {
        register_code (KC_LALT);
		register_code (KC_PPLS);
    }
	if (state->count == 5) {
        register_code (KC_LSFT);
		register_code (KC_LCTRL);
		register_code (KC_PPLS);
    }
	else {}
}

void QUAD_PLUS_reset (qk_tap_dance_state_t *state, void *user_data) {

        unregister_code (KC_PPLS);
        unregister_code (KC_LSFT);
        unregister_code (KC_LCTL);
		unregister_code (KC_LALT);
}



qk_tap_dance_action_t tap_dance_actions[] = {
  [SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [SP_PUNC] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [NXT_PRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT,KC_MPRV),
  [ENT_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_ENT,KC_EQL),
  [CAP_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC,KC_CAPS),
  [MIN_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_GRV),
  [NML_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,KC_NLCK),
  [DBL_Y] = ACTION_TAP_DANCE_DOUBLE(KC_Y,LSFT(KC_Y)),
  [DBL_MOUS] = ACTION_TAP_DANCE_DOUBLE(KC_BTN1,KC_BTN2),
  [TRI_P] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TRI_P_finished, TRI_P_reset),
  [TRI_Y] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TRI_Y_finished, TRI_Y_reset),
  [QUAD_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, QUAD_HOME_finished, QUAD_HOME_reset),
  [QUAD_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, QUAD_PLUS_finished, QUAD_PLUS_reset),
  [QUAD_F22] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, QUAD_F22_finished, QUAD_F22_reset)
};

enum custom_keycodes {
// Defines the keycodes used by our macros in process_record_user

  QMKBEST = SAFE_RANGE,
  QMKURL
};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(6,KC_BSPC):
      return TAPPING_TERM + 50;
    case LT(5,KC_SPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* [0] BASE
 * ,---------------------------------------------------------------------------------------------------------------,
 * | ESC  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | ` ~  | NMLK | PLAY | NEXT |  /   |
 * | CAPS |      |      |      |      |      |      |      |      |      |      |      | = +  |      | PREV |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  \   |  7   |  8   |  9   |  *   |
 * |      |      |      |      |      |      |      |      |      |      |      |      | HOME | UP   |PGUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | ENTER|  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |      | ' "  |  4   |  5   |  6   |  -   |
 * | SHIFT|      |      |      |      |      |      |      |      |      |  ;:  |SHIFT | LEFT |      | RIGHT|  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  Up  |  1   |  2   |  3   |  +   |
 * | CTRL |      |      |      |      |      |      |      |      |      |      |      | END  | DOWN |PGDN  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CTRL |      |      |BSPACE|LOWER |RAISE |Space | RCTL | RGUI | Left | Down | Right|  0   |  .   |      |
 * | DEL  |  F   | Alt  | GUI  |      |      |      |      |      |      |      |      |      |INSERT| DEL  |ENTER |
 * `---------------------------------------------------------------------------------------------------------------'
 */

  [0] = LAYOUT(
    TD(CAP_ESC),    KC_1,       KC_2,    KC_3,    KC_4,          KC_5,   KC_6,  KC_7,         KC_8,    KC_9,    KC_0,    KC_GRV,           KC_NLCK,  KC_MPLY,  TD(NXT_PRV), KC_PSLS,
    LSFT_T(KC_TAB), KC_Q,       KC_W,    KC_E,    KC_R,          KC_T,   KC_Y,  KC_U,         KC_I,    KC_O,    KC_P,    RSFT_T(KC_BSLS),  KC_P7,    KC_P8,    KC_P9,       KC_PAST,
    KC_ENT,         KC_A,       KC_S,    KC_D,    KC_F,          KC_G,   KC_H,  KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_P4,    KC_P5,    KC_P6,       KC_PMNS,
    KC_LCTL,        KC_Z,       KC_X,    KC_C,    KC_V,          KC_B,   KC_N,  KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_UP,            KC_P1,    KC_P2,    KC_P3,       KC_PPLS,
    KC_DEL,  	    LCTL(KC_F), KC_LALT, KC_LGUI, LT(6,KC_BSPC), TT(3),  TT(4), LT(5,KC_SPC), KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN,          KC_RIGHT, KC_P0,    KC_PDOT,     KC_PENT
  ),

/* [1] OVERWATCH
 * ,---------------------------------------------------------------------------------------------------------------,
 * | ESC  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | ` ~  | NMLK | PLAY | NEXT |  /   |
 * | CAPS |      |      |      |      |      |      |      |      |      |      |      |      |      | PREV |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | RSFT |  7   |  8   |  9   |  *   |
 * |      |      |      |      |      |      |      |      |      |      |      |  \|  | HOME | UP   |PGUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |      | ' "  |  4   |  5   |  6   |  -   |
 * | SHIFT|      |      |      |      |      |      |      |      |      |  ;:  |      | LEFT |      | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  UP  |  1   |  2   |  3   | QUAD |
 * | Ctrl |      |      |      |      |      |      |      |      |      |      |      | END  | DOWN |PGDN  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |BSpace|LOWER |RAISE |Space | RCTL |      | Left | Down | Right|  0   |  .   | ENTER|
 * | DEL  |      |  Alt |      |      |      |      |      |      |      |      |      |      |INSERT| DEL  |  =   |
 * `---------------------------------------------------------------------------------------------------------------'
 */

  [1] = LAYOUT(
    TD(CAP_ESC),    KC_1,       KC_2,     KC_3,     KC_4,    KC_5,    KC_6,      KC_7,    KC_8,     KC_9,       KC_0,      KC_GRV,          KC_NLCK,    KC_MPLY,   TD(NXT_PRV), KC_PSLS,
    KC_TAB,         KC_Q,       KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,     KC_O,       KC_P,      RSFT_T(KC_BSLS), KC_P7,      KC_P8,     KC_P9,       KC_PAST,
    KC_LSFT,        KC_A,       KC_S,     KC_D,     KC_F,    KC_G,    KC_H,      KC_J,    KC_K,     KC_L,       KC_SCLN,   KC_QUOT,         KC_P4,      KC_P5,     KC_P6,       KC_PMNS,
    KC_LCTL,  	    KC_Z,       KC_X,     KC_C,     KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM,  KC_DOT,     KC_SLSH,   KC_UP,           KC_P1,      KC_P2,     KC_P3,       TD(QUAD_PLUS),
    KC_DEL,         KC_NO,      KC_LALT,  KC_NO,    KC_BSPC, TT(3),   TT(4),     KC_SPC,  KC_RCTL,  KC_NO,      KC_LEFT,   KC_DOWN,         KC_RIGHT,   KC_P0,     KC_PDOT,     TD(ENT_EQL)
  ),


/* [2] WOW
 * ,---------------------------------------------------------------------------------------------------------------,
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | ` ~  | NMLK | PLAY | NEXT |  /   |
 * | CAPS |      |      |      |      |      |      |      |      |      |      |      |      |      | PREV |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  \   |  7   |  8   |  9   |  *   |
 * |      |      |      |      |      |      |      |      |      |      |      |      | HOME | UP   |PGUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |      | ' "  |  4   |  5   |  6   |  -   |
 * | SHIFT|      |      |      |      |      |      |      |      |      |  ;:  |SHIFT | LEFT |      | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |MOUSEB|  1   |  2   |  3   | QUAD |
 * | Ctrl |      |      |      |      |      |      |      |      |      |      | 1/2  | END  | DOWN |PGDN  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TD   |      |      |BSpace|LOWER |RAISE |Space | RCTL | CALT | Left | Down | Right|  0   |  .   | ENTER|
 * | DEL  | TRI_P|  Alt | GUI  |      |      |      |      |      |  F   |      |      |      |INSERT| DEL  |  =   |
 * `---------------------------------------------------------------------------------------------------------------'
 */

  [2] = LAYOUT(
    TD(CAP_ESC),    KC_F1,      KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,    KC_F9,      KC_F10,    KC_GRV,          KC_NLCK,    KC_MPLY,   TD(NXT_PRV), KC_PSLS,
    LSFT_T(KC_TAB), KC_Q,       KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,     KC_O,       KC_P,      RSFT_T(KC_BSLS), KC_P7,      KC_P8,     KC_P9,       KC_PAST,
    KC_ENT,         KC_A,       KC_S,     KC_D,     KC_F,    KC_G,    KC_H,      KC_J,    KC_K,     KC_L,       KC_SCLN,   KC_QUOT,         KC_P4,      KC_P5,     KC_P6,       KC_PMNS,
    KC_LCTL,  	    KC_Z,       KC_X,     KC_C,     KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM,  KC_DOT,     KC_SLSH,   TD(DBL_MOUS),    KC_P1,      KC_P2,     KC_P3,       TD(QUAD_PLUS),
    KC_DEL,         TD(TRI_P),  KC_LALT,  KC_LGUI,  KC_BSPC, TT(3),   TT(4),     KC_SPC,  KC_RCTL,  LCA(KC_F),  KC_LEFT,   KC_DOWN,         KC_RIGHT,   KC_P0,     KC_PDOT,     TD(ENT_EQL)
  ),


/* [3] LOWER
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |      |      |      |      |      |      |      |      |  [   |   ]  |      | CALC |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |PAUSE |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  -   |  +   |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | TD   |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      | TRI_Y|      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[3] = LAYOUT(
    _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  KC_CALC,  _______,  _______,  _______,
    _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PAUS,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F1,      KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_MINS,  KC_PLUS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F7,      KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  TD(TRI_Y),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

/* [4] RAISE
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |      |      |      |      |      |      |      |      |  {   |  }   |      |SCROLL|      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |LOCK  |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |PRINT |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |SCREEN|      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  _   |  =   |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 | MUTE | VOL- | VOL+ |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | MO   |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |SYSTEM|      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[4] = LAYOUT(
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, KC_LCBR,  KC_RCBR,  _______,  KC_SLCK,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______, _______,  KC_PSCR,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,  KC_F17,   KC_F18,   KC_UNDS,  KC_EQL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F19,   KC_F20,   KC_F21,   KC_F22,  KC_F23,   KC_F24,   KC_MUTE,  KC_VOLD, KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______, MO(7),    _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),


/* [5] SPACE MODIFIERS
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | DEL  |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[5] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  KC_DEL,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  /* [6] NUMPAD
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[6] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P7,     KC_P8,     KC_P9,    KC_PSLS,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P4,     KC_P5,     KC_P6,    KC_PAST,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P1,     KC_P2,     KC_P3,    KC_PMNS,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P0,     KC_PDOT,   KC_PENT,  KC_PPLS,  _______,  _______,  _______,  _______,  _______
  ),

/* [7] SYSTEM
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |RESET |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |DFAULT|DFAULT|      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      | OW   | WOW  |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |DFAULT|      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      | BASE |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[7] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(1),    DF(2),    _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(0),    _______,  _______
  ),

};
