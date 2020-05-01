// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "Lazout Yagdul 01.05.2020"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"
#include "Model01-Firmware.h"
#include "LEDEffectSwitchOnLayer.h"
// Support for storing the keymap in EEPROM
//#include "Kaleidoscope-EEPROM-Settings.h"
//#include "Kaleidoscope-EEPROM-Keymap.h"
#include <Kaleidoscope-LED-Wavepool.h>
// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"
#include "kaleidoscope/plugin/LEDModeInterface.h"
// Support for keys that move the mouse
//#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

//#include "Kaleidoscope-LEDEffect-BootAnimation.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
//#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
//#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"
//support for Tap'n'Hold functionality
#include "Kaleidoscope-Qukeys.h"
//#include "Kaleidoscope-LEDEffectSwitchOnLayer.h"
//#include "Kaleidoscope-LangPack-German.h"
/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
ii  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       //MACRO_ANY,
       MACRO_SMIRK,
       MACRO_FROWN,
       MACRO_SMILE,
       MACRO_PUKE,
       MACRO_TONGUE,
       MACRO_SWEAR,
       MACRO_DARN,
       MACRO_ROLL,
       MACRO_ROFL,
       MACRO_LOL,
       MACRO_SHRUG,
       MACRO_TONGUE2,
       LED_EFFECT_NEXT_NUMPADSHIFT
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { PRIMARY, NUMPAD, SPECIAL, GAME,XOY, FUNCTION }; // layers


/**
  * To change your keyboard's layout from QWERTY to DVORAK or COLEMAK, comment out the line
  *
  * #define PRIMARY_KEYMAP_QWERTY
  *
  * by changing it to
  *
  * // #define PRIMARY_KEYMAP_QWERTY
  *
  * Then uncomment the line corresponding to the layout you want to use.
  *
  */

//#define PRIMARY_KEYMAP_QWERTY
// #define PRIMARY_KEYMAP_COLEMAK
// #define PRIMARY_KEYMAP_DVORAK
// #define PRIMARY_KEYMAP_CUSTOM



/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(

 [PRIMARY] = KEYMAP_STACKED
  (Key_Escape,                Key_1, Key_2, Key_3, Key_4, Key_5, M(LED_EFFECT_NEXT_NUMPADSHIFT),
   Key_Tab,                   Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Meh,
   ShiftToLayer(SPECIAL),     Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_LeftShift, Key_Z,   Key_X, Key_C, Key_V, Key_B, MT(LeftGui,Equals),
   Key_Backspace, Key_Delete, Key_LeftControl, Key_LeftAlt,
   ShiftToLayer(FUNCTION),

   Key_RightBracket,           Key_6, Key_7, Key_8,     Key_9,         Key_0,                          Key_Minus,
   Key_Hyper,                  Key_Y, Key_U, Key_I,     Key_O,         Key_P,                          Key_LeftBracket,
                               Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon,                  Key_Quote,
   MT(RightGui,Backslash),              Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,         Key_RightShift,
   Key_RightAlt, Key_RightControl, Key_Enter, Key_Space,
   ShiftToLayer(FUNCTION)),


  [NUMPAD] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, M(MACRO_VERSION_INFO),
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
   ___,                    ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
                           ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,
   ___,                    ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),


 [SPECIAL] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   M(MACRO_VERSION_INFO),  ___, ___, ___,           ___,              ___, ___,
   ___,                     LALT(Key_7),        LALT(Key_5),      LALT(Key_6),      LALT(LSHIFT(Key_6)), LALT(LSHIFT(Key_Equals)), ___,
                          LSHIFT(Key_7),        LSHIFT(Key_8),    LSHIFT(Key_9),    LALT(Key_8),         LALT(Key_9),              ___, 
   ___,                   LALT(LSHIFT(Key_7)), Key_Backtick, LSHIFT(Key_Backtick),   ___,                 ___,                      ___, 
   ___, ___, ___, ___,
   ___),


 [GAME] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   Key_LeftControl, ___, ___, ___, ___, ___, ___,
   Key_Space, ___, ___, ___,
   Key_LeftShift,

   ___,  ___, ___, ___,           ___,              ___, ___,
   ___,                     ___,        ___,      ___,      ___, ___, ___,
                         ___,        ___,    ___,    ___,         ___,              ___, 
   ___,                   ___, ___, ___,   ___,                 ___,                      ___, 
   ___, ___, ___, ___,
   ___),

   
[XOY] =  KEYMAP_STACKED
  (___, ___, ___, ___, ___, ___, ___,
   ___, Key_X,        Key_Comma, Key_O,     Key_Period,      Key_Z,         ___,
   ___, Key_H,        Key_A,     Key_E,     Key_I,           Key_U,
   ___, CTL_T(K), Key_Q,     Key_Quote, Key_LeftBracket, Key_Semicolon, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___,    ___,    ___,    ___,   ___,          Key_Slash,
   ___,                   Key_V,   Key_G, Key_C,   Key_L, Key_J,        Key_Minus,
                          Key_D,   Key_T, Key_R,   Key_N, Key_S,        ALT_T(F), 
   ___,                   Key_B,   Key_P, Key_W,   Key_M, CTL_T(Y), ___, 
   ___, ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,         Key_F3,            Key_F4,               Key_F5,            Consumer_Mute,
   Key_Tab,  ___,              M(MACRO_PUKE),  M(MACRO_SHRUG),    M(MACRO_FROWN),      M(MACRO_ROFL),               Consumer_VolumeIncrement,
   ___,      ___,              M(MACRO_ROLL),  M(MACRO_TONGUE),   M(MACRO_SMIRK),      M(MACRO_LOL),
   ___,      ___,              M(MACRO_SWEAR), M(MACRO_TONGUE2),  M(MACRO_SMILE),      M(MACRO_DARN),               Consumer_VolumeDecrement,
   ___,      ___,              ___,         ___,
   ___, 

   Consumer_PlaySlashPause,       Key_F6,          Key_F7,                   Key_F8,         Key_F9,          Key_F10,  Key_F11,
   Consumer_ScanPreviousTrack,    ___,             Key_PageUp,               Key_UpArrow,    Key_PageDown,    ___,      Key_F12,
                                  Key_Home,        Key_LeftArrow,            Key_DownArrow,  Key_RightArrow,  Key_End,      ___,
   Consumer_ScanNextTrack,        ___,             ___,                      ___,            ___,             ___,      ___,
   ___, ___, Key_Enter, ___,
   ___)
) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Kezboardio Model 01 / Kaleidoscope ")); //Kezboardio Model 01 ß Kaleidoscope Stephans Layout 23.04.2020
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

//static void anyKeyMacro(uint8_t keyState) {
 // static Key lastKey;
  //bool toggledOn = false;
  //if (keyToggledOn(keyState)) {
    //lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);
    //toggledOn = true;
  //}
//
  //if (keyIsPressed(keyState))
    //kaleidoscope::hid::pressKey(lastKey, toggledOn);
//}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  static uint32_t start;
  static int current=0;

  if (macroIndex ==  LED_EFFECT_NEXT_NUMPADSHIFT){
	if(keyToggledOn(keyState)){
		start=millis();
        } else if (keyToggledOff(keyState)) {
		if (millis()-start < 150){
			//WavepoolEffect.activate();
			current=current+1;
			if (LEDEffectSwitchOnLayer.getPlugin(current)==NULL){
				current=0;
			}
			LEDEffectSwitchOnLayer.getPlugin(current)->activate();
			LEDEffectSwitchOnLayer.setPluginForLayer(Layer.top(),current);
		}
	}
	return MACRO_NONE;
  }
  
  if (keyToggledOn(keyState)) {
     switch (macroIndex) {
		 
	  case MACRO_VERSION_INFO:
	    versionInfoMacro(keyState);
	    break;

	  //case MACRO_ANY:
	    //anyKeyMacro(keyState);
	    //break;
	  case MACRO_SMIRK:
	    Macros.type(PSTR("</("));
	    break;
	  case MACRO_FROWN:
	    Macros.type(PSTR(">/*"));
	    break;
	  case MACRO_SMILE:
	    Macros.type(PSTR(">/("));
	    break;
	  case MACRO_PUKE:
	    Macros.type(PSTR("*puke("));
	    break;
	  case MACRO_TONGUE:
	    Macros.type(PSTR(">/P"));
	    break;
	  case MACRO_TONGUE2:
	    Macros.type(PSTR("</P"));
	    break;
	  case MACRO_SWEAR:
	    Macros.type(PSTR("*swear("));
	    break;
	  case MACRO_DARN:
	    return MACRODOWN(I(25),
			     D(LeftShift), T(Period), U(LeftShift), T(Slash), D(LeftAlt), T(E), U(LeftAlt)
			    );
	    break;
	  case MACRO_ROLL:
	    Macros.type(PSTR("*roll("));
	    break;
	  case MACRO_ROFL:
	    Macros.type(PSTR("*rofl("));
	    break;
	  case MACRO_SHRUG:
	    Macros.type(PSTR("*shrug("));
	    break;
	  case MACRO_LOL:
	    Macros.type(PSTR("*lol("));
	    break;

	  }
  }
  return MACRO_NONE;
}




/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    LEDControl.paused = true;
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 /
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
// static void toggleKeyboardProtocol(uint8_t combo_index) {
//   USBQuirks.toggleKeyboardProtocol();
// }


/**
 *  This enters the hardware test mode
 */
 static void enterHardwareTestMode(uint8_t combo_index) {
   HardwareTestMode.runTests();
 }
static void xoyMode(uint8_t combo_index){
   if (Layer.isActive(XOY)){
      Layer.move(PRIMARY);
       StalkerEffect.variant = STALKER( BlazingTrail);
   } else { 
      Layer.move(XOY);
      StalkerEffect.variant = STALKER( Haunt);
   }
}
static void gameMode(uint8_t combo_index){
 if  (Layer.isActive(GAME)){
    Layer.move(PRIMARY);
    StalkerEffect.variant=STALKER(BlazingTrail);
 } else { 
    Layer.move(GAME);
    StalkerEffect.variant = STALKER(Rainbow);
 }  
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
// USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
//                   // Left Fn + Esc + Shift
//                   .keys = { R3C6, R2C6, R3C7 }
// }
// });
USE_MAGIC_COMBOS(
   {.action=gameMode,.keys={ R3C6,R3C9,R0C9}},   //fn+fn+top left key, right half
   {.action=xoyMode,.keys={R3C6,R3C9,R0C6}},   //FN+FN+"LED"-key
   {.action=enterHardwareTestMode,.keys={R3C6,R0C0,R0C6}}   //Left Fn+Prog+LED
);


// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
//static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
//static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
//static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
//static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
//static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
//static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);


// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  //EEPROMSettings,
  //EEPROMKeymap,
  Qukeys,
  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  //FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  //FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  //BootAnimationEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // left Fn button at the same time.
  HardwareTestMode,

  // LEDControl provides support for other LED modes
  LEDControl,
  
  StalkerEffect,
  WavepoolEffect,
  
  // The rainbow effect changes the color of all of the keyboard's keys at the same time
  // running through all the colors of the rainbow.
  LEDRainbowEffect,

  // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
  // and slowly moves the rainbow across your keyboard
  LEDRainbowWaveEffect,

  // The chase effect follows the adventure of a blue pixel which chases a red pixel across
  // your keyboard. Spoiler: the blue pixel never catches the red pixel
  //LEDChaseEffect,
  // These static effects turn your keyboard's LEDs a variety of colors
  //solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,

  // The breathe effect slowly pulses all of the LEDs on your keyboard
  LEDBreatheEffect,

  // The AlphaSquare effect prints each character you type, using your
  // keyboard's LEDs as a display
  //AlphaSquareEffect,

  LEDOff,
  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  ColormapEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,
  //kaleidoscope::plugin::LEDEffectSwitchOnLayer,

  // The macros plugin adds support for macros
  Macros,
  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
//  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,
  solidRed,
  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,
  LEDEffectSwitchOnLayer,
  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks
);


/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
	QUKEYS(
	    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 6), ShiftToLayer(NUMPAD))
	)

  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;
  NumPad.color = CRGB(0, 0, 160); // a blue color
  NumPad.lock_hue = 85; // green
  // We configure the AlphaSquare effect to use RED letters
  //AlphaSquare.color = CRGB(255, 0, 0);

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  LEDRainbowEffect.brightness(150);
  LEDRainbowWaveEffect.brightness(150);

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // The LED Stalker mode has a few effects. The one we like is called
  // 'BlazingTrail'. For details on other options, see
  StalkerEffect.variant = STALKER( BlazingTrail);
  //StalkerEffect.inactive_color= CRGB(0x05, 0x30, 0x05);
  StalkerEffect.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  //EEPROMKeymap.setup(2);
  
  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(2);
  WavepoolEffect.idle_timeout = 5000;  // 5 seconds
  //WavepoolEffect.activate();
  Qukeys.activate();
  Qukeys.setHoldTimeout(155);
  Qukeys.setOverlapThreshold(85);

  LEDEffectSwitchOnLayer.setPluginForLayer(PRIMARY,StalkerEffect);
  //LEDEffectSwitchOnLayer.setPluginForLayer(XOY,StalkerEffect);
  //LEDEffectSwitchOnLayer.setPluginForLayer(SPECIAL,solidRed);
  //LEDEffectSwitchOnLayer.setPluginForLayer(GAME,WavepoolEffect);
  LEDEffectSwitchOnLayer.enable();

  LEDEffectSwitchOnLayer.setPluginOrder(0,StalkerEffect);
  LEDEffectSwitchOnLayer.setPluginOrder(1,LEDRainbowEffect);  
  LEDEffectSwitchOnLayer.setPluginOrder(2,LEDBreatheEffect);  
  LEDEffectSwitchOnLayer.setPluginOrder(3,LEDRainbowWaveEffect);  
  LEDEffectSwitchOnLayer.setPluginOrder(4,WavepoolEffect);  
  LEDEffectSwitchOnLayer.setPluginOrder(5,solidRed);  
  LEDEffectSwitchOnLayer.setPluginOrder(6,LEDOff);  
 
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}



