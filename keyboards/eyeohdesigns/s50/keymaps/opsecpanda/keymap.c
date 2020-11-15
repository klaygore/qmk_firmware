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
#include "S50.h"
// #include S50_H
// Defines the keycodes used by our macros in process_record_user

#define ______ KC_NO

/*
PANDA_layout( \
             k31, k00, k01, k02, k03, k04, k05, k06, k07, k60, k61, k52, k57, k47,\
   k30,                                                                           \
            k32,  k10, k11, k12, k13, k14, k15, k16, k17, k62, k63, k51, k54, k56,\
          k34,    k20, k21, k22, k23, k24, k25, k26, k27, k64, k65, k50, k55, k46,\
        k35, k36, k37,                k67,           k41,      k42, k43, k44, k45 \
) \
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	    [_BASE] = PANDA_iso_split_wrapper(
	/* Base Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bksp|Del  |Bksp|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            | Tab | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |BLCYC|BRTH|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |Shft|Shift| Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |Ent | Up  |Ent |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *      |Ctl/Ent| Ctrl | Alt | TG 1 | Spacemod1  | Spacemod2   | TG 2 | <- |Down | -> |
     *      `----------------------------------------------------------------------------'
     */
                     ESCMACRO,				QWERTY_1 , 						KC_BSPC,		KC_DEL,		KC_BSPC , 
KC_MUTE,                                                                                                             
				     KC_TAB,				QWERTY_2 ,						KC_QUOT,		BL_STEP ,	BL_BRTG , 
		          KC_LSFT , KC_LSFT,		QWERTY_3 ,						KC_ENT,			KC_UP,   	KC_ENT,  
LCTL_T(KC_ENT), LCTL_T(KC_ENT) ,KC_LALT , TG(1) ,  SPACEMOD1    ,    SPACEMOD2   , TG(2),  KC_MUTE , KC_LEFT, KC_DOWN, KC_RGHT 
),


	[_LAYER1] = PANDA_iso_split_wrapper(
	/* Layer 1
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  |Bksp|Del  | TG3|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            | Tab | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | \  | IDK |ASON|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |  \ |Shift| _  | -  | =  | (  | )  | [  | ]  | ,  | .  | /  |Ent | Up  |ASOF|
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *         OS | Ctrl | Alt |Space|  Space    /   TG            | Raise| <- |Down | -> |
     *      `----------------------------------------------------------------------------'
     */
				KC_DEL , 					SYM_ROW1 , 						KC_BSPC , KC_DEL , KC_BSPC ,  
  KC_MUTE,                                                                                                                                 
	            KC_GRV , 					NUM_ROW , 						KC_BSLS ,  ______ , BL_INC,  
			   KC_LSFT , KC_LSFT, 			SYM_ROW2 , 						KC_ENT ,   KC_PGUP, BL_DEC,  
KC_LGUI, KC_LCTL, KC_LALT,  TG(1), 		        KC_SPC ,    TG(1),  TG(2) ,   KC_MUTE , KC_LEFT, KC_PGDN, KC_RGHT 
),


	[_LAYER2] = PANDA_iso_split_wrapper(
	/* Layer 2
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10|Bksp|Del  |TG(3|   14
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            | Tab |    |    |    |    |    |    |    |    | F11| F12| \  |     |BL+ |   14
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |Shft|Shift| _  | -  | =  | (  | )  | [  | ]  | ,  | .  | /  |Ent |PGUP |BL- |   15
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *       CTL-OS | Ctrl | Alt |     |  Toggle layer 3  |        |      |BACK|PGDN |FWD |   11  = 54 total
     *      `----------------------------------------------------------------------------'
     */
				KC_DEL , 					FUNC_ROW1 , 						KC_BSPC , KC_DEL , TG(_LAYER3) ,  
  KC_MUTE,                                                                                                                                 
	            KC_GRV , 					FUNC_ROW2 , 						KC_BSLS ,  ______ , BL_INC,  
			   KC_CAPS , KC_LSFT, 			SYM_ROW2 , 							KC_ENT ,   KC_PGUP, BL_DEC,  
KC_LGUI, KC_LCTL, KC_LALT,  TG(1) ,		         TG(2),   KC_SPC ,       TG(2) ,      KC_MUTE , KC_WBAK, KC_PGDN, KC_WFWD 
),


	[_MACROS] = PANDA_iso_split_wrapper(
	/* Macros Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |Bksp|Del  | LED|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            | Tab | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  | IDK |ASON|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |  \ |Shift| Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |Ent | Up  |ASOF|
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *       CTL-OS | Ctrl | Alt |Space|  Spacemod1  /   Spacemod2 | Raise| <- |Down | -> |
     *      `----------------------------------------------------------------------------'
     */
                 ______  , 					MACRO_1 , 					______ ,   ______ ,     LALT(KC_F4) ,   
KC_MUTE,                                                                                                                                        
				    ______ , 				MACRO_2 , 							______ ,   ______ , RESET ,   
				   KC_LSFT , KC_LSFT,      	MACRO_3,					   		BLANK_3 ,   
KC_MUTE,  ______, ______, CDQMK ,		        SNAKEDOCTOR , OPSECPANDA , 		BLANK_5  
)
};

// Normally my third layer is toggled on for RGB control, saving this here in case I want it later
/*
	[_LAYER3] = PANDA_layout_wrapper(
	 F Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Esc| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10|    |     |TG(3|   14
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |     |    |    |    |    |    |    |    |    | F11| F12|    |     |    |   14
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |Shft|Shift| _  | -  | =  | (  | )  | [  | ]  | ,  | .  | /  |    |     |    |   15
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *       CTL-OS | Ctrl | Alt |  MSYS2   | snakedoctor  / opsecpanda |      |    |     |    |   11  = 54 total
     *      `----------------------------------------------------------------------------'
     
                TG(3) , 				FUNC_ROW1 , 						______ ,   ______ ,     TG(_LAYER3) ,   
KC_MUTE,                                                                                                                                        
				______ , 					FUNC_ROW2 , 						BLANK_3 ,   
				KC_LSFT , KC_LSFT,      	SYM_ROW2,					   		BLANK_3 ,   
KC_LGUI,  KC_LCTL, KC_LALT, CDQMK ,		        SNAKEDOCTOR , OPSECPANDA , 		BLANK_5  
), 
*/

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
 if (index == 0) {
	 if (clockwise) {
    register_code (KC_VOLD);
	unregister_code(KC_VOLD);
 }  else{
	register_code(KC_VOLU);
    unregister_code(KC_VOLU);
 }
 }
}
