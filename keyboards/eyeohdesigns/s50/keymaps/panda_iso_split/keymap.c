/* Copyright 2020 Eye Oh Designs
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
#include "opsecpanda.h"
// #include S50_H
// Defines the keycodes used by our macros in process_record_user

#define ______ KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	    [_BASE] = ANSI_Right(
	/* Base Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bksp| E  | LED|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+ n  |----|
     *            |Tb/Nm| A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  | t  |ASON|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+----+----|
     *       |   Shift  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |Ent | Up |ASOF|
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+----+----|
     *       CTL-OS | Ctrl | Alt |Raise|         Space           | Raise  |Left|Down|Rght|
     *      `----------------------------------------------------------------------------'
     */
                     ESCMACRO,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,   KC_O,   KC_P,    KC_BSPC,               BL_STEP, \
KC_MUTE,                                                                                                          KC_DEL,           \
				     KC_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,   KC_L,   KC_SCLN, KC_QUOT,                KC_ASON, \
		           KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,        KC_UP,   KC_ASOFF,\
               KC_LGUI, LCTL_T(KC_ENT) ,KC_LALT , KC_SPC ,        SPACEMOD1            ,    MO(LAYER2)   ,KC_LEFT, KC_DOWN, KC_RIGHT \
),

	[_LAYER1] = ANSI_Right(
	/* Layer 1
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | `  | 1  |  2 |  3 |    |  [ | ]  |    | Up |    |    |    | E  |PScr|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+ n  |----|
     *            | Tab | 4  |  5 |  6 |    |  = | -  |Left|Down|Rght|    |    | t  |ASUP|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+----+----|
     *       |          |  7  |  8  |  9  |    |    |    |    |    |    |  \ |Shft| Up |ASDN|
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+----+----|
     *      | OS  | Ctrl| Alt |    |                Space  |  Alt  | Ctrl|Left|Down|Rght|
     *      `----------------------------------------------------------------------------'
     */
				KC_DEL , KC_1 , KC_2 , KC_3 , KC_MINS ,   KC_EQL , KC_NO , KC_NO , KC_NO , KC_LBRC , KC_RBRC , KC_BSPC ,        KC_PSCR,\
  KC_MUTE,                                                                                                              KC_ENT,         \
	            KC_GRV , KC_4 , KC_5 , KC_6 ,  KC_0 , ______ , ______ , ______ , ______ , ______ , KC_SCLN , KC_BSLS ,          KC_ASUP,\
			    KC_LSFT , KC_7 , KC_8 , KC_9 , KC_0 , ______ , ______,   ______, KC_COMM , KC_DOT , KC_SLSH , KC_ENT ,KC_UP, KC_ASDN,\
		       KC_LGUI, KC_LALT,KC_LCTL,                 ______,                            ______,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT\
),
	[_LAYER2] = ANSI_Right(
	/* Layer 2
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11|F12 | E  |    |
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+ n  |----|
     *            | Tab | 1  | 2  | 3  | 4  | 5  | 6  | 7  |  8 | 9  | 0  |    | t  |    |
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+----+----|
     *       |          | !  | @  | #  |  $ | %  | ^  | &  |  * | (  | )  |    | Up |    |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+----+----|
     *      | OS  | Ctrl| Alt |    |             |   Space  |  Alt  | Ctrl|Left|Down|Rght|
     *      `----------------------------------------------------------------------------'
     */  
                      KC_DEL , KC_EXLM , KC_AT , KC_HASH , KC_UNDS,  ______,______,______,______, KC_LPRN , KC_RPRN , KC_BSPC ,         ______,\
KC_MUTE,                                                                                                                       KC_ENT,       \
				     ______,    ______,______, ______,______,  ______,______, ______,______, ______,______,  ______,                   ______,\
				   ______,      KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,______, KC_UP,  ______,\
		       KC_LGUI,  KC_LALT,KC_LCTL,   ______,                         ______,                       KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT\
),
	[_LAYER3] = ANSI_Right(
	/* Layer 3
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11|F12 | E  |    |
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+ n  |----|
     *            | Tab | 1  | 2  | 3  | 4  | 5  | 6  | 7  |  8 | 9  | 0  |    | t  |    |
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+----+----|
     *       |          | !  | @  | #  |  $ | %  | ^  | &  |  * | (  | )  |    | Up |    |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+----+----|
     *      | OS  | Ctrl| Alt |    |             |   Space  |  Alt  | Ctrl|Left|Down|Rght|
     *      `----------------------------------------------------------------------------'
     */  
                      TG(3) , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,   KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , ______ ,                ______,\
KC_MUTE,                                                                                                                       KC_ENT,       \
				    ______ , ______ , ______ , ______ , ______ , ______ ,    ______ , ______ , ______ , KC_F11 , KC_F12 , KC_NO ,                  ______,\
				   ______,      KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,______, KC_UP,  ______,\
		       KC_LGUI,  KC_LALT,KC_LCTL,   ______,                         ______,                       KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT\
)
};



void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
 if (index == 0) {
	 if (clockwise) {
  register_code(KC_VOLU);
  unregister_code(KC_VOLU);
 }  else{
	register_code (KC_VOLD);
	unregister_code(KC_VOLD);
 }
 }
}
