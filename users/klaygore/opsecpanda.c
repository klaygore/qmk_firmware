#include "opsecpanda.h"

void my_custom_function(void) {

}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// All my silly Rocket League quick chats
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	
    case QUACK:
      if (record->event.pressed) {
        // when keycode QUACK is pressed

        SEND_STRING("tQuackulated.");
	tap_code(KC_ENT);
	SEND_STRING("tQuackulated.");
	tap_code(KC_ENT);


      } else {
	
        // when keycode QUACK is released
      }
      break;

case SKIDOOSH:
      if (record->event.pressed) {
        // when keycode SKIDOOSH is pressed

        SEND_STRING("tSkidooooosh");
	tap_code(KC_ENT);


      } else {
        // when keycode SKIDOOSH is released
      }
      break;

case DUCK:
      if (record->event.pressed) {
        // when keycode DUCK is pressed

        SEND_STRING("tReally ducked that one up");
	tap_code(KC_ENT);
	//tap_code(KC_ENT);


      } else {
        
      }
      break;

case BAMBOO:
      if (record->event.pressed) {
        // when keycode BAMBOO is pressed

        SEND_STRING("tBAMBOOzled!!");
	tap_code(KC_ENT);


      } else {
        // when keycode BAMBOO is released
      }
      break;

case BEAR:
      if (record->event.pressed) {


        SEND_STRING("tWell that was unBEARable");
	tap_code(KC_ENT);

      } else {

      }
      break;

case PAULA:
      if (record->event.pressed) {
        // when keycode PAULA is pressed

        SEND_STRING("tSUCK MY PAULY D");
	tap_code(KC_ENT);


      } else {
	
        // when keycode PAULA is released
      }
      break;

case FLAVOR:
      if (record->event.pressed) {


        SEND_STRING("tWELCOME TO FLAVORTOWN");
	tap_code(KC_ENT);
	//tap_code(KC_ENT);

      } else {
      }
      break;

case LOL:
      if (record->event.pressed) {

        SEND_STRING("tLOOOOOL");
	tap_code(KC_ENT);
	SEND_STRING("tLOLOLOLOLOL");
	tap_code(KC_ENT);
	SEND_STRING("tLMAO");
	tap_code(KC_ENT);

      } else {
      }
      break;

case FLIPFLOP:
      if (record->event.pressed) {

        SEND_STRING("tPut that on a flip flop");
	tap_code(KC_ENT);

      } else {
      }
      break;

case NP:
      if (record->event.pressed) {

        SEND_STRING("yNo problem, we got this");
	tap_code(KC_ENT);

      } else {
      }
      break;


case NOWORRIES:
      if (record->event.pressed) {

        SEND_STRING("yNo worries, amigo");
	tap_code(KC_ENT);

      } else {
      }
      break;

case CRIKEY:
      if (record->event.pressed) {

        SEND_STRING("yCrikey!");
		tap_code(KC_ENT);
		SEND_STRING("yCrikey!");
		tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA1:
      if (record->event.pressed) {

        SEND_STRING("tFemale pandas ovulate only once a year. They are fertile only two or three days of the year.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA2:
      if (record->event.pressed) {

        SEND_STRING("tA panda’s bones are twice as heavy as the bones of other animals the same size.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA3:
      if (record->event.pressed) {

        SEND_STRING("tThe panda spends 14-16 hours a day eating bamboo.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA4:
      if (record->event.pressed) {

        SEND_STRING("tPandas have plantigrade feet.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA5:
      if (record->event.pressed) {

        SEND_STRING("tThe giant panda has been on the endangered species list since 1990.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA6:
      if (record->event.pressed) {

        SEND_STRING("tA panda’s entire mating process takes only about two or three days.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA7:
      if (record->event.pressed) {

        SEND_STRING("tMuch of the food that a giant panda eats is not digested.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA8:
      if (record->event.pressed) {

        SEND_STRING("tPandas have lived on Earth for two to three million years.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA9:
      if (record->event.pressed) {

        SEND_STRING("tAn adult giant panda weighs about 200-300 pounds (90-135 kg).");
	tap_code(KC_ENT);

      } else {
      }
      break;

case PANDA0:
      if (record->event.pressed) {

        SEND_STRING("tMale pandas do a handstand while peeing to mark trees.");
	tap_code(KC_ENT);

      } else {
      }
      break;

case OPSECPANDA:
      if (record->event.pressed) {

        SEND_STRING("opsecpanda");


      } else {
      }
      break;

case SNAKEDOCTOR:
      if (record->event.pressed) {

        SEND_STRING("snakedoctor93");

      } else {
      }
      break;

case CDQMK:
      if (record->event.pressed) {

        SEND_STRING("cd ..");
	tap_code(KC_ENT);
        SEND_STRING("cd ..");
	tap_code(KC_ENT);
        SEND_STRING("cd C/Users/PandaWall/Desktop/QMK/qmk_firmware");
	tap_code(KC_ENT);

      } else {
      }
      break;
	

case REGULATION:
      if (record->event.pressed) {

        SEND_STRING("tDAMNIT");
	tap_code(KC_ENT);
	SEND_STRING("tIS THAT GOAL REGULATION SIZE OR WHAT");
	tap_code(KC_ENT);
	SEND_STRING("tGEEEZ");
	tap_code(KC_ENT);

      } else {
      }
      break;
	  
case PIKACHU:
      if (record->event.pressed) {

        SEND_STRING("tsurprisedpikachu.jpg");
	tap_code(KC_ENT);
	//tap_code(KC_ENT);
		SEND_STRING("t:o");
	tap_code(KC_ENT);
	//tap_code(KC_ENT);

      } else {
      }
      break;
	  
case QUACKERS:
      if (record->event.pressed) {

        SEND_STRING("tquack quack, mother ducker");
		tap_code(KC_ENT);
		//tap_code(KC_ENT);

      } else {
      }
      break;
	  
case BILL:
      if (record->event.pressed) {

        SEND_STRING("tYou can put that on my bill");
		tap_code(KC_ENT);
		//tap_code(KC_ENT);

      } else {
      }
      break;
// this is where the case code section ends

  }
  return process_record_keymap(keycode, record);
};
