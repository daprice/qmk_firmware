#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

//Mine isn't an Ergodox EZ
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    ErgoDox
#define PRODUCT         ErgoDox
#define DESCRIPTION     QMK keyboard firmware for Ergodox
#undef USB_MAX_POWER_CONSUMPTION
#define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(100)

#undef IGNORE_MOD_TAP_INTERRUPT // the behavior described as "bad" in the ergodox config.h is actually what I want since I'm using mod-tap for the command key

#endif
