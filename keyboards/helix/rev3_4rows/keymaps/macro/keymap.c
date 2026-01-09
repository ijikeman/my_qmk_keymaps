/* Copyright 2020 yushakobo
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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  ADJUST = SAFE_RANGE
// MACRO
  ,
  M_BRC,
  M_QUOT,
  M_MINUS,
  M_S_MINUS,
  M_ESC,

// WINDOWS_LAYER
  WIN_TAB,
  WIN_LEFT,
  WIN_RGHT,
};

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)
#define LOWER  LT(_LOWER, KC_SPC)
#define RAISE  LT(_RAISE, KC_BSPC)
#define MLCTL  LCTL_T(KC_TAB)
#define MLANG1 LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  [/] |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | '/\  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      | ALT  |  GUI | LOWER|Space |Space | RAISE| LANG |ADJUST|      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BRC,
      MLCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, M_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_NO,  KC_NO,   KC_NO, KC_LALT, KC_LGUI,   LOWER,    KC_SPC,  KC_SPC, RAISE,  MLANG1,  ADJUST,   KC_NO,    KC_NO,   KC_NO
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  _/+ |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Caps |      | WIN_L| WIN_T| WIN_R|      |             | LEFT | DOWN |  UP  | RGHT |WHEELD|WHEELU|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |M-LEFT|M-DOWN| M-UP |M-RGHT|L-CLCK|R-CLCK|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      | DEL  |      |      |      |      |RESET |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, M_S_MINUS,
      KC_CAPS, KC_NO, WIN_LEFT, WIN_TAB,WIN_RGHT, KC_NO,                    KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, MS_WHLD, MS_WHLU,
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    MS_LEFT, MS_DOWN,  MS_UP,  MS_RGHT, MS_BTN1, MS_BTN2,
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_DEL,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  QK_BOOT
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | -/=  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    M_MINUS,
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, 
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, 
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, 
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, 
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
      )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// --- 長押し新規実装
// user_mt(record, ホールド時キーコードー, タップ時のキーコード, モディファイアキー押下判定のための変数, trueならTAPPING_TERMより長押ししたときにタップと判定する)
static bool pressed = false;
static uint16_t pressed_time = 0;
static void user_mt(keyrecord_t *record, uint16_t modcode, uint16_t keycode, uint16_t layer_code, bool *pressed, uint16_t *pressed_time) {
    if (record->event.pressed) {
        *pressed = true;
        *pressed_time = record->event.time;
    } else {
        if (!*pressed) {
            unregister_code(modcode);
        } else {
            if (timer_elapsed(*pressed_time) < TAPPING_TERM) {
                if (layer_code != 0) register_code(layer_code);
                tap_code16(modcode);
                if (layer_code != 0) unregister_code(layer_code);
            } else {
                if (layer_code != 0) register_code(layer_code);
                tap_code16(keycode);
                if (layer_code != 0) unregister_code(layer_code);
            }
            *pressed = false;
            *pressed_time = 0;
        }
    }
}
// --- 新規長押し実装関数

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      break;
    // Original Macro
    case WIN_TAB:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            unregister_code(KC_LGUI);
        }
        break;
    case WIN_LEFT:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LEFT);
            unregister_code(KC_LEFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
        }
        break;
    case WIN_RGHT:
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_RGHT);
            unregister_code(KC_RGHT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
        }
        break;

    // --- 新実装
    // 長押しマクロ([ or ])
    case M_BRC:
        user_mt(record, KC_LBRC, KC_RBRC, 0, &pressed, &pressed_time);
        return false;
        break;
    // 長押しマクロ(' or \)
    case M_QUOT:
        user_mt(record, KC_QUOT, KC_BSLS, 0, &pressed, &pressed_time);
        return false;
        break;
    // 長押しマクロ(- or =)
    case M_MINUS:
        user_mt(record, KC_MINUS, KC_EQL, 0, &pressed, &pressed_time);
        return false;
        break;
    // 長押しマクロ(_ or +)
    case M_S_MINUS:
        user_mt(record, KC_MINUS, KC_EQL, KC_LSFT, &pressed, &pressed_time);
        return false;
        break;
    // 長押しマクロ(ESC or CAPS)
    case M_ESC:
        user_mt(record, KC_ESC, KC_CAPS, 0, &pressed, &pressed_time);
        return false;
        break;
    }
    return true;
}
