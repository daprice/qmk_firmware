/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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
#include "phantom.h"

// Helpful defines
#define _______ KC_TRNS

enum planck_keycodes {
	DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NumL 0
#define _ClusterL 1
#define _FL 2


/* How to use dynamic macros with this keymap:
 	Press the upper right key (normally Pause/break) to begin recording, then press any sequence of up to 256(?) keys.
 	Then press fn+upper right key to stop recording.
 	
 	Press fn+F1 to play back the recording at any time.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NumL] = KEYMAP_PHOBOS(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, DF(_ClusterL), DYN_REC_START1,  \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_KP_7,  KC_KP_8, KC_KP_9, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_KP_4,  KC_KP_5,  KC_KP_6, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, KC_KP_1, KC_KP_2, KC_KP_3,                                  \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                KC_KP_0, KC_UP, KC_KP_DOT,            \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             TT(_FL), KC_RGUI, KC_RALT, KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
	[_ClusterL] = KEYMAP_PHOBOS(
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, DF(_NumL), _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_INS, KC_HOME, KC_PGUP, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_DEL, KC_END, KC_PGDN, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_NO, KC_NO, KC_NO,                                 \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               KC_NO, _______, KC_NO,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______,      _______, _______,  _______  \
		),
	//Function layer, performs the following functions:
	// - Power on Esc
	// - Media keys on function keys
	// - number keys select RGB light mode
	// - arrows and surrounding keys adjust RGB lights
	// - vim-like arrows for left and right hands
	// - backspace acts as delete
	// - numpad toggler key acts as num lock
	// - numpad 9 puts teensy into DFU mode
    [_FL] = KEYMAP_PHOBOS(
        KC_PWR,          DYN_MACRO_PLAY1, _______, _______, _______,  _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, KC_MUTE, KC_VOLD, KC_VOLU,      _______, KC_NLCK, DYN_REC_STOP, \
        RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, _______, _______, _______, _______, KC_DEL,      _______, _______, RESET, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,          _______,RGB_TOG,RGB_MOD,_______,                                 \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               RGB_SAD,RGB_VAI,RGB_SAI,          \
        _______, _______, _______,                            RGB_MOD,                            _______, _______, _______, _______,      RGB_HUD, RGB_VAD,  RGB_HUI  \
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
		return false;
	}
	return true;
}

void led_set_user(uint8_t usb_led) {

}
