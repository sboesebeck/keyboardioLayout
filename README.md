# Stephans Layout

This is a layout / firmware for the Keyboardio Model100. Thanks to the opensource nature of the keyboard and it's software, I was able to just take the default Firmware and adapt it to my needs and ideas. This will change over time, as I will experiment with other features, that might be useful for my work and my typing skills.

**ATTENTION**: THIS BRANCH IS FOR THE MODEL100 - if you need a layout working for Model01,
switch to branch `master`.

## Features of the Firmware

The firmware does have a couple of layers defined, for certain use cases:

- PRIMARY: is now set as standard QWERTZ Layout for a German OSX usage... I hope to change that to a ADNW-XOY layout at some point
- FUNCTION: this is the key layout enabled by pressing one of the palm keys, here I implemented an "inversed T" Cursor Cluster on the left side. This works astonishingly well for me. I removed all mouse keys in this layout, and the plugin is not included here. I added a couple of Macros instead, for creating emojis as ASCII-Strings. But those will be replaced by the OS to the corresponding emoji.
- XOY: an alternative layout for typing. Should be more efficient and ergonomic, but I still struggle to get fast with it
- GAME: well, for Egoshooter or something, this is a useful layer 😉
- SPECIAL: The Special Layer creates all kinds of Braces on the home row for the left hand. Very easy to type!
- NUMPAD: get a numpad on the right hand side

I tried to reduce the number of plugins for this firmware, so I removed everything, I did not need. The eeprom support was disabled (I do not use Chrysalis, so i am fine) and removed the mouse plugin etc.

I use a couple of LED Effects on this layout, but that might change in Future to something else.

Qukeys is used for a couple of double assigned keys, so the Left and right CMD-Key (GUI for windows users) is also # and ´

## programmed extensions

There are 2 things implemented in code:

- I added a custom plugin, that switches to a different LED Effect depending on the currently active layer. That means, when I am switching to GAME layer, the LEDs light up differently for example. This plugin also handles its own kind of LEDNExt-Key, in order to keep the active effect for each layer. That is necessary when shifting to a different layer
- right now, I use MagicCombos to switch between PRIMARY, XOY and GAME layers. This code at the moment also changes the Effect on the StalkerEffect-Plugin. So if you have Stalker enabled on each layer, you get a different effect.

My Idea is to have also some own coded LED Effects, to use in this firmware.

- combining base color and having a certain Effect on certain keys. Like a blue basecolor, but red glowing WSAD-Keys for Game mode...
- having F-Keys light up differently, when in FN-Mode...
- having an easy stalker like effect on thos...

just thinking. It is more important to get essential feedback with those LEDs - as it is now, it is more a gimmick than useful.

Another plan is to use the Focus-Serial-Plugin in combination with tools like Keyboard Maestro or maybe just the onboard automation on MacOS, to automatically switch to a certain Layout / LED-effect when working in a specific application. For Example, when in your favourite IDE, enable a less distracting LED Theme, having certain control sequences highlighted... something like that.

## Screensaver LEDs
I added a Plugin from Andrew as described [here](https://community.keyboard.io/t/do-these-plugins-exist/5772/2) as a kind of "Screensaver" for LEDs
it kicks in after some predefined time and shows a specific LED-Effect (Digital Rain in my case).


