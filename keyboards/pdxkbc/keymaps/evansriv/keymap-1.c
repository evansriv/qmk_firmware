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

enum custom_keycodes {
    CHSPACE = SAFE_RANGE,
    DIMENSION,
    PASTEORIG,
    POLYLINE,
    ZOOMEXT,
    ZOOMOBJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      SWIN(KC_S), ZOOMEXT,
      KC_PGUP, KC_PGDOWN,
      LT(1,KC_HOME), LT(2,KC_END)
    ),
    [1] = LAYOUT(
      DIMENSION, ZOOMOBJ,
      CHSPACE, PASTEORIG,
      KC_NO, POLYLINE
    ),
    [2] = LAYOUT(
      KC_BRID, KC_BRIU,
      KC_VOLD, KC_VOLU,
      KC_MUTE, KC_NO
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CHSPACE:
      if (record->event.pressed) {
        SEND_STRING("chsp" SS_TAP(X_ENTER));
      }
      break;
    case DIMENSION:
      if (record->event.pressed) {
        SEND_STRING("di" SS_TAP(X_ENTER));
      }
      break;
    case PASTEORIG:
      if (record->event.pressed) {
        SEND_STRING("pasteorig" SS_TAP(X_ENTER));
      }
      break;
    case POLYLINE:
      if (record->event.pressed) {
        SEND_STRING("pl" SS_TAP(X_ENTER));
      }
      break;
    case ZOOMEXT:
      if (record->event.pressed) {
        SEND_STRING("z e" SS_TAP(X_ENTER));
      }
      break;
    case ZOOMOBJ:
      if (record->event.pressed) {
        SEND_STRING("z o" SS_TAP(X_ENTER));
      }
      break;
  }

  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
