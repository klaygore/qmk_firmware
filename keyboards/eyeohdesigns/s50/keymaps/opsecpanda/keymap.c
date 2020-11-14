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
#include "s50.h"
// #include S50_H
// Defines the keycodes used by our macros in process_record_user

#define ______ KC_NO

/*
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LT(3,KC_SPC):
      return TAPPING_TERM + 50;
    case LT(3,KC_BSPC):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}
*/

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
     * |Knob|      | Tab| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |DEL | HOME|PGUP|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |Enter| A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  | END |PGDN|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |Rase|Ctrl | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  | F2 | Up  | F5 |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *      |Lower|ESCM  | Alt | LGUI |  Backspc | SpaceMOD   | RCtrl     |LEFT|Down |RGHT|
     *      `----------------------------------------------------------------------------'
     */
				LSFT_T(KC_TAB),	 KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,RSFT_T(KC_DEL),KC_HOME, KC_PGUP , 
KC_MUTE,                                               	                                                              
				KC_ENT, 	 KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,	KC_END , KC_PGDN , 
			 TT(3), KC_LCTL,	 KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_F2,	KC_UP,   KC_F5,  
			 TT(2), KC_ESC, KC_LALT, KC_LGUI , LT(_MACROS,KC_BSPC), LT(_SPACEMOD,KC_SPC), KC_RGUI, KC_RCTL, 		  KC_LEFT, 	KC_DOWN, KC_RGHT 
),

	    [_GAME] = PANDA_iso_split_wrapper(
	/* Base Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      | Tab| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |DEL | HOME|PGUP|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |Enter| A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  | END |PGDN|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |Rase|Ctrl | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  | F2 | Up  | F5 |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *      |Lower|ESCM  |     |      |  Backspc | Space      | ENTER     |LEFT|Down |RGHT|
     *      `----------------------------------------------------------------------------'
     */
				KC_TAB,	 KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,RSFT_T(KC_DEL),KC_HOME, KC_PGUP , 
KC_MUTE,                                               	                                                              
				KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,	KC_END , KC_PGDN , 
			 TT(3), KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_F2,	KC_UP,   KC_F5,  
			 TT(2), KC_ESC,  KC_ENT,   KC_NO ,  	KC_BSPC,	 KC_SPC, 	KC_RGUI, KC_RCTL, 		   KC_LEFT, 	KC_DOWN, KC_RGHT 
),


	[_LAYER1] = PANDA_iso_split_wrapper(
	/* Layer 1
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      |    |DF 0|DF 1|    |    |    |    |    |    |    | [  | ]  |     |RST |
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |     |    |    |    |    |    |    |    | -  | +  |    |PAUS|     |    |
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |RASE|     |    |    |    |    |    |    |    |    |    |    |    |     |    |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *       LOWER|CAPS |    |    |              |         |       |      |    |     |    |
     *      `----------------------------------------------------------------------------'
     */
			         _______,DF(_BASE),DF(_GAME),_______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______ , _______, RESET,  
  _______,                                                                                                                                 
	            		 _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_PLUS, _______, KC_PAUS, _______, _______, _______,  
			 TT(3),  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  
			 TT(2),  KC_CAPS, _______,  _______,   _______, _______, _______,   _______ ,		_______, _______, _______ 
),


	[_LAYER2] = PANDA_iso_split_wrapper(
	/* Layer 2
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      |    |    |    |    |    |    |    |    |    | {  |  } |    |     |    |   14
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |     | F1 | F2 | F3 | F4 | F5 | F6 | _  | =  |    |PSCR|    |     |    |   14
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |RASE|     | F7 | F8 | F9 | F10| F11| F12|    |    |    |    |    |     |    |   15
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *       LOWER|     |         |    |                 |         |      |    |     |    |   11  = 54 total
     *      `----------------------------------------------------------------------------'
     */
				 _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, 
  _______,                                                                                                                                 
	            		 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_UNDS, KC_EQL , _______, KC_PSCR, _______, _______, _______,  
			 TT(3),  _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______,  
			 TT(2),  _______, _______,  _______,   _______, _______, _______,   _______ ,		_______, _______, _______ 
),


	[_MACROS] = PANDA_iso_split_wrapper(
	/* Macros Layer
     * ,____.      ,-----------------------------------------------------------------------.
     * |Knob|      |    |    |    |    |    |    |    | 7  | 8  | 9  |    |    |HUE+ |MODE+|
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|-----|
     *            |     | /  | *  | +  | -  |    |    | 4  | 5  | 6  |    |    |HUE- |MODE-|
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+-----|
     *       |    |     |    |    |    |    |    |    | 1  | 2  | 3  |    |    |LGHT+|     |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+-----|
     *            |      |     |     |              |   0        |   .    |    |LGHT-|     |
     *      `------------------------------------------------------------------------------'
     */
				 _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9, _______, _______, RGB_HUI, RGB_MOD,  
  _______,                                                                                                                                 
	              		 _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______, _______, KC_4, KC_5, KC_6, _______, _______, RGB_HUD, RGB_RMOD,  
			_______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, _______, RGB_VAI, _______, 
			_______, _______, _______, _______,  	 _______, 		    KC_0, 	KC_PDOT,  _______, _______, RGB_VAD, _______
),


	[_SPACEMOD] = PANDA_iso_split_wrapper(
	/* Macros Layer
     * ,____.      ,---------------------------------------------------------------------.
     * |Knob|      |    | !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  | `~ |     |    |
     * `----'     ,-----+----+----+----+----+----+----+----+----+----+----|----+-----|----|
     *            |     |    |    |PREV|PLAY|NEXT|    |    |    |    |    |    |     |    |
     *       ,----------+----+----+----+----+----+----+----+----+----+----+----+-----+----|
     *       |    |     |    |    |    |    |    |    |MUTE|    |    |    |    |     |    |
     *      ,-----+-----+---------+----+----+----+----+----+----+----+----+----+-----+----|
     *            |      |     |     |     DEL      |            |        |    |     |    |
     *      `----------------------------------------------------------------------------'
     */
				 _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV , _______, _______,  
  _______,                                                                                                                                 
	              		 _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,  
			_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, 
			_______, _______, _______,  _______,  	 KC_DEL, 		    _______, 	_______,  _______, _______, _______, _______
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
