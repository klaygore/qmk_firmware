#include QMK_KEYBOARD_H
#include "version.h"

#define BASE  0 // default layer
#define GAME  1 // gaming layer
#define SYMB  2 // symbols
#define SYMB2 3 // symbols2
#define NUML  4 // numlock
#define MDIA  5 // media keys
#define SPMOD 6 // space modifier

enum custom_keycodes {
RUN_CMD = SAFE_RANGE,
RUN_RDP,
RUN_CTP,
RUN_CPM,
RUN_NET,

#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM,
#endif
  VRSN,
  RGB_SLD
};



uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(SPMOD,KC_SPC):
      return TAPPING_TERM + 50;
    case LT(NUML,KC_BSPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |MEH(F)|           | `~   |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | SFTTAB |   Q  |   W  |   E  |   R  |   T  | CAPS |           | NUM  |   Y  |   U  |   I  |   O  |   P  |  SFT \ |
 * |--------+------+------+------+------+------| LOCK |           | LOCK |------+------+------+------+------+--------|
 * | ENTER  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |  '"    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  RCTRL |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | FIND | Alt  | LGUI |BSPACE|                                       |SPACE |      | RGUI |SEARCH|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        | HOME | END  |       | LEFT |RIGHT|
 *                                 ,------|------|------|       |------+-----+------.
 *                                 |      |      | PGUP |       | UP   |     |      |
 *                                 |LAYER |LAYER |------|       |------|ENTER|LAYER |
 *                                 |SYMB  |MDIA  | PGDN |       | DOWN |     |SYMB2 |
 *                                 `--------------------'       `-------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,         KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    MEH(KC_F),
  LSFT_T(KC_TAB), KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,    KC_CAPS,
  KC_ENT,         KC_A,          KC_S,    KC_D,    KC_F,    KC_G,
  KC_LCTL,        KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
  KC_NO,          LCTL(KC_F),    KC_LALT, KC_LGUI, LT(NUML,KC_BSPC),
                                                                      KC_HOME,  KC_END,
                                                                                KC_PGUP,
                                                            TT(SYMB), TT(MDIA), KC_PGDN,
  // right hand
  KC_GRV,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_DEL,
  KC_NLCK,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           RSFT_T(KC_BSLS),
  KC_H,             KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_NO,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
  LT(SPMOD,KC_SPC), KC_NO,   KC_RGUI, KC_WSCH, KC_NO,
  KC_LEFT, KC_RIGHT,
  KC_UP,
  KC_DOWN, KC_ENT, TT(SYMB2)
),

/* Keymap 1: Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | LBRC |           | RBRC |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | CAPS |           | NUM  |   Y  |   U  |   I  |   O  |   P  |  SFT \ |
 * |--------+------+------+------+------+------| LOCK |           | LOCK |------+------+------+------+------+--------|
 * | LSHIFT |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |  '"    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  RCTRL |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |SEARCH| FN   | Alt  | LGUI |BSPACE|                                       |SPACE |      | RGUI |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        | HOME | END  |       | LEFT |RIGHT|
 *                                 ,------|------|------|       |------+-----+------.
 *                                 |      |      | PGUP |       | UP   |     |      |
 *                                 |LAYER |LAYER |------|       |------|ENTER|LAYER |
 *                                 |SYMB  |MDIA  | PGDN |       | DOWN |     |SYMB2 |
 *                                 `--------------------'       `-------------------'
 */
[GAME] = LAYOUT_ergodox(
  // left hand
  KC_ESC,         KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,
  KC_TAB,         KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,    KC_CAPS,
  KC_LSFT,        KC_A,          KC_S,    KC_D,    KC_F,    KC_G,
  KC_LCTL,        KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
  KC_WSCH,        LCTL(KC_F),    KC_LALT, KC_LGUI, KC_BSPC,
                                                                      KC_HOME,  KC_END,
                                                                                KC_PGUP,
                                                            TT(SYMB), TT(MDIA), KC_PGDN,
  // right hand
  KC_RBRC,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_DEL,
  KC_NLCK,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           RSFT_T(KC_BSLS),
  KC_H,             KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_NO,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
  KC_SPC,           KC_NO,   KC_RGUI, KC_NO,   KC_NO,
  KC_LEFT, KC_RIGHT,
  KC_UP,
  KC_DOWN, KC_ENT, TT(SYMB2)
),


/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |   [  |  ]   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      | PAUSE|        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------| F6   |  -   |  +   |      |      |        |
 * |---------+------+------+------+------+------|      |           |COMP  |------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  |  F10 |  F11 |      |           |MGMT  | F12  |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |RUNNET|      |      |RUNCMD|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
  KC_SLCK, _______, _______, _______, _______, KC_PAUS, _______,
  KC_F6,   KC_MINS, KC_PLUS, _______, _______, _______,
  RUN_CPM, KC_F12, _______, _______, _______, _______, _______,
  _______, RUN_NET, _______, _______, RUN_CMD,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 3: Symbol Layer 2
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |  {   |  }   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      | PSCR |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F13 |  F14    F15 |  F16 |  F17 |------|           |------| F18  |  _   |  =   |      |      |        |
 * |---------+------+------+------+------+------|CTRL  |           |      |------+------+------+------+------+--------|
 * |         |  F19 |  F20 |  F21 |  F22 |  F23 |PANEL |           |      | F24  |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RUN_RDP|      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|DELETE|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB2] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,
  _______, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  RUN_CTP,
  RUN_RDP, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______,
  _______, _______, _______, _______, _______, KC_PSCR, _______,
  KC_F18,  KC_UNDS, KC_EQL,  _______, _______, _______,
  _______, KC_F24,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, KC_DEL,  _______
),

/* Keymap 4: NUMLOCK Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |  /     |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |  *     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |  -     |
 * |---------+------+------+------+------+------|      |           | CALC |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |  +     |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   .  | ENTER|      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUML] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, KC_PSLS,
  _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, KC_PAST,
  _______, KC_P4,   KC_P5,   KC_P6,   _______, KC_PMNS,
  KC_CALC, _______, KC_P1,   KC_P2,   KC_P3,   _______, KC_PPLS,
  KC_P0,   KC_PDOT, KC_PENT, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),


/* Keymap 5: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |DFGAME|      |      |      |      |      |           |      |      |      |      |      |DFBASE|        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| RCLK |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | LCLK |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | PREV | NEXT |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | VOL+ |      |      |
 *                                 |      |      |------|       |------| MUTE | PLAY |
 *                                 |      |      |      |       | VOL- |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  _______, DF(GAME), _______, _______, _______, _______, _______,
  _______, _______,  _______, KC_MS_U, _______, _______, KC_BTN2,
  _______, _______,  KC_MS_L, KC_MS_D, KC_MS_R, _______,
  _______, _______,  _______, _______, _______, _______, KC_BTN1,
  _______, _______,  _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, DF(BASE), _______,
  _______, _______, _______, _______, _______, _______,  _______,
           _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______, _______,  _______,
                    _______, _______, _______, _______,  _______,
  KC_MPRV, KC_MNXT,
  KC_VOLU,
  KC_VOLD, KC_MUTE, KC_MPLY
),

/* Keymap 6: Space Modifier
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | DEL  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SPMOD] = LAYOUT_ergodox(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_DEL,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
)
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {

      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
   
      case RUN_CMD:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(100);
        SEND_STRING("cmd");
        wait_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
      case RUN_RDP:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(100);
        SEND_STRING("mstsc");
        wait_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
      case RUN_CPM:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(100);
        SEND_STRING("compmgmt.msc");
        wait_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;
        
    case RUN_CTP:
        SEND_STRING(SS_LGUI("r"));
        wait_ms(100);
        SEND_STRING("control");
        wait_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        return false;

   case RUN_NET:
	SEND_STRING(SS_LGUI("r"));
	wait_ms(100);
	SEND_STRING("ncpa.cpl");
	wait_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));
	return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
