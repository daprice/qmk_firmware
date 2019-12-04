/* Copyright 2018 Dale Price <daprice@mac.com>
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

#include "airpad.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum airpad_layers {
  _NAVIGATION,
  _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main (Navigation layer)
 * ,--------------------.
 * | Eject| Media|Search|
 * |------+------+------|
 * | Shift| Up   | Tab  |
 * |------+------+------|
 * | Left | Down | Right|
 * |------+------+------|
 * | Ctrl | Opt  | Cmd  |
 * `--------------------'
 */
[_NAVIGATION] = {
  {KC_EJCT,  KC_MPLY,    LGUI(KC_SPC)},
  {KC_LSFT,  KC_UP,    KC_TAB},
  {KC_LEFT, KC_DOWN,    KC_RGHT},
  {KC_LCTL, KC_LALT, KC_LGUI}
},

/* Numeric keypad
 * ,--------------------.
 * | Eject| Media| 0    |
 * |------+------+------|
 * | 7    | 8    | 9    |
 * |------+------+------|
 * | 4    | 5    | 6    |
 * |------+------+------|
 * | 1    | 2    | 3    |
 * `--------------------'
 */
[_NUMPAD] = {
  {KC_EJCT,  KC_TRNS,    KC_0},
  {KC_7,  KC_8,    KC_9},
  {KC_4, KC_5,    KC_6},
  {KC_1, KC_2, KC_3}
}


};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         print("mode just switched to qwerty and this is a huge string\n");
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//       break;
//     case COLEMAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_COLEMAK);
//       }
//       return false;
//       break;
//     case DVORAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_DVORAK);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case BACKLIT:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//         #ifdef BACKLIGHT_ENABLE
//           backlight_step();
//         #endif
//         PORTE &= ~(1<<6);
//       } else {
//         unregister_code(KC_RSFT);
//         PORTE |= (1<<6);
//       }
//       return false;
//       break;
//     case PLOVER:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//           PLAY_SONG(plover_song);
//         #endif
//         layer_off(_RAISE);
//         layer_off(_LOWER);
//         layer_off(_ADJUST);
//         layer_on(_PLOVER);
//         if (!eeconfig_is_enabled()) {
//             eeconfig_init();
//         }
//         keymap_config.raw = eeconfig_read_keymap();
//         keymap_config.nkro = 1;
//         eeconfig_update_keymap(keymap_config.raw);
//       }
//       return false;
//       break;
//     case EXT_PLV:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_PLOVER);
//       }
//       return false;
//       break;
//   }
//   return true;
// }
