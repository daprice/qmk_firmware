#ifndef AIRPAD_H
#define AIRPAD_H

#include "quantum.h"
#include "adafruit_ble.h"


#define CATERINA_BOOTLOADER

#define LAYOUT_airpad_default( \
	k00, k01, k02, \
	k10, k11, k12, \
	k20, k21, k22, \
	k30, k31, k32 \
) \
{ \
	{ k00, k01, k02 }, \
	{ k10, k11, k12 }, \
	{ k20, k21, k22 }, \
	{ k30, k31, k32 } \
}

#define KEYMAP LAYOUT_airpad_default

#endif
