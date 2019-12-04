Airpad
===

A tiny (3x4 key) bluetooth keypad using low profile mechanical keyboard switches and the Adafruit Feather 32u4 Bluefruit. [More info on github](https://github.com/daprice/ios-macropad)

Keyboard Maintainer: [Dale Price](https://github.com/daprice)
Hardware Supported: Airpad v1
Hardware Availability: [PCB and case files in Github repo](https://github.com/daprice/ios-macropad)

Make example for this keyboard (after setting up your build environment):

    make airpad/default

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.

Flashing firmware to the Adafruit Feather 32u4 using avrdude:
	
    avrdude -c avr109 -P /dev/cu.usbmodem1411 -p m32u4 -b 57600 -D -U flash:w:Keyboards/qmk_firmware/airpad_default.hex:i