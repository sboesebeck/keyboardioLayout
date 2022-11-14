# Stephans Layout

This is a layout / firmware for the Keyboardio Model01. Thanks to the opensource nature of the keyboard and it's software, I was able to just take the default Firmware and adapt it to my needs and ideas. This will change over time, as I will experiment with other features, that might be useful for my work and my typing skills.

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



# Original Readme of the Model 01 Firmware

# Keyboardio Model 01 Firmware

_The default firmware for the Keyboardio Model 01_

<h3>This is a quick start guide for folks who are familiar with Arduino and prefer to use the command line. For everyone else:

- [Check out the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Keyboardio-Model-01-Introduction) for a more in depth introduction to how the Model 01 keyboard and the Kaleidoscope firmware work.

- If you have questions, [The community forums are happy to help!](https://community.keyboard.io/)</h3>

# Download and install

## Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6.10, since older version may not support all required features.

### macOS

On macOS, install the Arduino IDE using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

### Linux

On Linux, your distribution's package manager probably includes the Arduino IDE, but it may be an out of date version. If your distribution installs a version of Arduino before 1.6.10, you'll need to install the Arduino IDE following the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Install-Arduino-support-on-Linux).

If you install Arduino into some place that's /not/ `/usr/local/arduino`, you'll need to set the `$ARDUINO_PATH` environment variable to the directory containing the `arduino` and `arduino-builder` binaries.

## Create and navigate to the Arduino Sketchbook directory

### MacOS

```sh
mkdir -p $HOME/Documents/Arduino
cd $HOME/Documents/Arduino
```

### Linux

```sh
mkdir -p $HOME/Arduino
cd $HOME/Arduino
```

## Download hardware platform, including library source code

```sh
mkdir -p hardware

## then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/keyboardio/Kaleidoscope-Bundle-Keyboardio.git hardware/keyboardio
```

## Download the Model 01 Firmware

```sh
git clone https://github.com/keyboardio/Model01-Firmware.git
```

# Build and flash the firmware

Before you begin, make sure your Model 01 is connected to your computer.

### Option 1: From the command line

```sh
cd Model01-Firmware
make flash
```

When the builder tells you to hit Enter to continue, hold down "Prog" in the top left corner of your keyboard and hit Enter.

### Option 2: From the Arduino IDE

Open the sketch you wish to flash (for example, `Model01-Firmware.ino`).

Click the Upload button or press `Ctrl-U`.

Hold down the "Prog" key in the top left corner of your keyboard, until the compile finishes and the upload begins.

# Start to customize the firmware

You can customize your keyboard's key layout and LED effects by modifying the `Model01-Firmware.ino` file in the same directory as this README. Model01-Firmware.ino is a computer program written in 'Arduino C'. You can find documentation about Arduino C at https://arduino.cc.

# Updating the firmware and libraries

From time to time, you may want to pull the latest version of this firmware from GitHub. To do that, navigate to the Model01-Firmware directory in your shell and pull the latest code.

```sh
cd Model01-Firmware
git pull
```

After that, you'll want to update the Kaleidoscope libraries.

### MacOS

```sh
cd $HOME/Documents/Arduino/hardware/keyboardio
make update-submodules
```

### Linux

```sh
cd $HOME/Arduino/hardware/keyboardio
make update-submodules
```

# Getting help

As you start to explore customization of your keyboard's firmware, the community at https://community.keyboard.io can often be a valuable resource.

# Thanks!

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
