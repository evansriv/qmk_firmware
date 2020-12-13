/* Copyright 2019 COSEYFANNITUTTI
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

#define _BL 0

// Tap Dance declarations
enum {
	TD_AST_CIRC,
	TD_DOT_CALC,
	TD_MNS_BSPC,
	TD_PLS_TAB
};

void dance_calc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_PDOT);
    } else {
        register_code(KC_CALC);
    }
}

void dance_calc_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_PDOT);
    } else {
        unregister_code(KC_CALC);
    }
}

void dance_bspc_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_PMNS);
    } else if (state->count == 2) {
        register_code(KC_BSPC);
    } else {
		register_code(KC_DEL);
	}
}

void dance_bspc_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_PMNS);
    } else if (state->count == 2) {
        unregister_code(KC_BSPC);
    } else {
		unregister_code(KC_DEL);
	}
}

void dance_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_PPLS);
    } else if (state->count == 2) {
        register_code(KC_TAB);
    } else {
		register_mods(MOD_BIT(KC_LSFT));
		register_code(KC_TAB);
	}
}

void dance_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_PPLS);
    } else if (state->count == 2) {
        unregister_code(KC_TAB);
    } else {
		unregister_mods(MOD_BIT(KC_LSFT));
		unregister_code(KC_TAB);
	}
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for asterisk, twice for circumflex (power)
	[TD_AST_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_PAST,KC_CIRC),
	// Tap once for dot, twice to launch calculator
	[TD_DOT_CALC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_calc_finished, dance_calc_reset),
	// Tap once for plus, twice for tab, three times for shift-tab
	[TD_PLS_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_tab_finished, dance_tab_reset),
	// Tap once for minus, twice for backspace, three times for forward delete
	[TD_MNS_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_bspc_finished, dance_bspc_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_numpad_5x4(
      //TO(1),   KC_PSLS, TD(TD_AST_CIRC), KC_PMNS, 
      TO(1),   KC_PSLS, TD(TD_AST_CIRC), TD(TD_MNS_BSPC), 
      //TO(1), KC_PSLS, KC_PAST, KC_PMNS,
      KC_P7,   KC_P8,   KC_P9,            
      //KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
      KC_P4,   KC_P5,   KC_P6,   TD(TD_PLS_TAB), 
      KC_P1,   KC_P2,   KC_P3,            
      //KC_P0,   KC_PDOT,      KC_PENT  ),
      KC_P0,   TD(TD_DOT_CALC),      KC_PENT  ),
  [1] = LAYOUT_numpad_5x4(
      TO(2),   KC_NO, KC_NO,    KC_NO,
      KC_HOME, KC_UP, KC_PGUP,
      KC_LEFT, KC_NO, KC_RIGHT, KC_NO,
      KC_END,  KC_DOWN, KC_PGDN,
      KC_SPC,         KC_DEL,   KC_ENT    ),
  [2] = LAYOUT_numpad_5x4(
      TO(0), KC_NO, KC_NO, KC_NO,
      KC_F2, KC_F3, KC_F4,
      KC_F5, KC_F6, KC_F7, KC_NO,
      KC_F8, KC_F9, KC_F10,
      KC_NO,        KC_NO, KC_NO          )
};
