/* Copyright 2019 Franklin Harding
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      KC_KP_PLUS,        KC_KP_MINUS,
      KC_KP_ASTERISK,    KC_KP_SLASH,
      LT(1,KC_KP_EQUAL), LT(2,KC_KP_ENTER)
   ),
    [1] = LAYOUT(
      KC_END, KC_HOME,
      KC_PGDOWN, KC_PGUP,
      _______, KC_INS
   ),
    [2] = LAYOUT(
      KC_BRID, KC_BRIU,
      KC_VOLD, KC_VOLU,
      KC_MUTE, _______
      
   ),
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
