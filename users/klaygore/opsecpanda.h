#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"


#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

#define SPACEMOD1 	LT(_LAYER1, 	KC_SPC)
#define SPACEMOD2 	LT(_LAYER2, 	KC_SPC)
#define ESCMACRO 	LT(_MACROS, 	KC_ESC)
#define BSPCMOD1 	LT(_LAYER1, 	KC_BSPC)
#define BSPCMOD2 	LT(_LAYER2, 	KC_BSPC)
#define DELMOD2 	LT(_LAYER2, 	KC_DEL)
#define ALTMOD1 	LT(_LAYER1, 	KC_LALT)
#define ALTMOD2 	LT(_LAYER2, 	KC_LALT)

#define ALTF4 LALT(KC_F4)
#define TSKMGR LCTL(LSFT(KC_ESC))
#define ALTTAB LALT(KC_TAB)
#define CTLTAB LCTL(KC_TAB)
#define CSFTTAB LCTL(LSFT(KC_TAB))

// Layer names
enum userspace_layers {
  _BASE = SAFE_RANGE,
  _GAME,
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _RGB,
  _MACROS,
  _SPACEMOD,
};

#define  _BASE 		0
#define  _GAME		1
#define  _LAYER1 	2
#define  _LAYER2 	3
#define  _LAYER3 	4
#define  _RGB 		5
#define  _MACROS 	6
#define  _SPACEMOD	7

// Wrappers for layouts
#define LAYOUT_ortho_5x12_wrapper(...)       	LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_ergodash_wrapper(...)         	LAYOUT_ergodash(__VA_ARGS__)
#define PANDA_layout_wrapper(...)         		PANDA_layout(__VA_ARGS__)
#define PANDA_iso_split_wrapper(...)         	PANDA_iso_split(__VA_ARGS__)
#define PANDA_iso_left_wrapper(...)         	PANDA_iso_left(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)         	LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_rebound_wrapper(...)         	LAYOUT_rebound(__VA_ARGS__)
#define LAYOUT_ortho2_wrapper(...)         		LAYOUT_ortho2(__VA_ARGS__)
#define LAYOUT_levinson_wrapper(...)         	LAYOUT_levinson(__VA_ARGS__)
#define LAYOUT_launch_wrapper(...)         		LAYOUT_launch(__VA_ARGS__)
#define LAYOUT_big_boy_wrapper(...)         	LAYOUT_big_boy(__VA_ARGS__)


// Shortcuts for layer sections
#define BLANK_3   	KC_NO,   KC_NO,   KC_NO
#define BLANK_5   	KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO

#define ARROWS_1   	KC_LEFT,  KC_DOWN , KC_UP   , KC_RGHT
#define ARROWS_2   	KC_WBAK , KC_PGDN , KC_PGUP , KC_WFWD
#define ARROWS_3   	KC_WBAK , KC_END  , KC_HOME , KC_WFWD

#define QWERTY_L1 	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2 	KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3 	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define QWERTY_R1 	KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define QWERTY_R2 	KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define QWERTY_R3 	KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define NUMBER_L  	KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define NUMBER_R  	KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define SYM_L1    	KC_EXLM ,   KC_AT ,     KC_HASH ,   KC_DLR,     KC_PERC
#define SYM_R1    	KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN

#define SYM_L2    	KC_UNDS ,   KC_MINS  ,  KC_EQL ,    KC_PLUS,    KC_RALT
#define SYM_R2    	KC_LBRC ,   KC_RBRC  ,  KC_COMM ,   KC_DOT ,    KC_SLSH

#define FUNC_L     	KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5
#define FUNC_R     	KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10
#define FUNC_X     	KC_MUTE,  KC_MUTE,   KC_NO,   KC_F11,  KC_F12

#define MACRO_L1   	QUACK , QUACK , 	KC_NO , REGULATION , 	KC_NO
#define MACRO_L2   	KC_NO , SKIDOOSH , 	DUCK , 	FLAVOR , 	FLIPFLOP
#define MACRO_L3   	NP , 	NOWORRIES , CRIKEY, KC_NO , 	BAMBOO

#define MACRO_R1   	PIKACHU , 	BEAR , 	KC_NO , LOL , 	PAULA 
#define MACRO_R2   	PANDA1 , 	PANDA2 ,PANDA3, PANDA4, PANDA5  
#define MACRO_R3   	PANDA6 , 	PANDA7 ,PANDA8, PANDA9, PANDA0 

#define RGB_ROW_L1   	KC_NO , RGB_VAD , RGB_VAI , KC_NO , RGB_RMOD , RGB_MOD  
#define RGB_ROW_L2   	KC_NO , RGB_HUD , RGB_HUI , KC_NO , RGB_TOG , RGB_TOG

#define RGB_ROW_R1   	RGB_SPD , RGB_SPD , RGB_M_P , RGB_M_SW , RGB_M_G , RGB_M_R
#define RGB_ROW_R2   	RGB_RMOD , RGB_MOD , RGB_M_B , RGB_SAD , RGB_SAI , RGB_M_X

// Definition combinations for non-split boards
#define QWERTY_1 	QWERTY_L1, 	QWERTY_R1  	// Q - P
#define QWERTY_2 	QWERTY_L2, 	QWERTY_R2	// A - :
#define QWERTY_3	QWERTY_L3, 	QWERTY_R3	// Z - ?
#define NUM_ROW  	NUMBER_L , 	NUMBER_R	// 1 - 0
#define SYM_ROW1  	SYM_L1   , 	SYM_R1		// ! - )
#define SYM_ROW2	SYM_L2   , 	SYM_R2
#define FUNC_ROW1   FUNC_L   , 	FUNC_R		// F1 - F10
#define FUNC_ROW2   BLANK_5  ,  FUNC_X		// _____ - F12
#define MACRO_1		MACRO_L1 , 	MACRO_R1
#define MACRO_2		MACRO_L2 , 	MACRO_R2
#define MACRO_3		MACRO_L3 , 	MACRO_R3
#define RGB_ROW_1	RGB_ROW_L1, RGB_ROW_R1
#define RGB_ROW_2	RGB_ROW_L2, RGB_ROW_R2


// Custom keycodes
enum custom_keycodes {
  BASE = PLACEHOLDER_SAFE_RANGE,
  QUACK,
  SKIDOOSH,
  BAMBOO,
  BEAR,
  FLAVOR,
  DUCK,
  PAULA,
  LOL,
  FLIPFLOP,
  NP,
  NOWORRIES,
  CRIKEY,
  PANDA1,
  PANDA2,
  PANDA3,
  PANDA4,
  PANDA5,
  PANDA6,
  PANDA7,
  PANDA8,
  PANDA9,
  PANDA0,
  OPSECPANDA,
  SNAKEDOCTOR,
  CDQMK,
  REGULATION,
  PIKACHU,
  QUACKERS,
  BILL,
  NEW_SAFE_RANGE
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
