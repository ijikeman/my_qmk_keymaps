#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    M_LANG = SAFE_RANGE,
    M_BRC,
    M_QUOT,
    M_MINUS,
    M_S_MINUS,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
* ,-----------------------------------------------------------------------------------.
* | TAB |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [/] |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Ctr |  A   |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
* |------+------+------+------+------+-----|------+------+------+------+------+------|
* | Sft |  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /  | '/\   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | ESC | IME |  ALT | GUI  |Mouse|Spc/Lower|Bs/Raise|   | LEFT | DOWN |  UP  | RIGHT |
* `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BRC,
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, M_QUOT,
   KC_ESC,  M_LANG, KC_LALT, KC_LGUI, ADJUST, LT(_LOWER,KC_SPC),LT(_RAISE, KC_BSPC),KC_NO, KC_NO, KC_NO, KC_NO,KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _/+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      | LEFT | DOWN |  UP  | RGHT |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      |      |      | Del  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  S(KC_GRV),S(KC_1),S(KC_2), S(KC_3), S(KC_4),S(KC_5),S(KC_6), S(KC_7), S(KC_8), S(KC_9),S(KC_0), M_S_MINUS,
  KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
  QK_BOOT, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   M_MINUS,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static uint16_t pressed_time = 0; // キーが押されてからの時間
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_LANG: // 日本語切り替え
        if (record->event.pressed) {
            register_code(KC_LALT);
            tap_code(KC_GRAVE);
            unregister_code(KC_LALT);
        } else {
        }
        break;

    case M_BRC:
        if (record->event.pressed) { // when keycode is pressed
            pressed_time = record->event.time;
        } else { // when keycode is released
            if (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM) {
              tap_code(KC_LBRC);
              pressed_time = 0;
            } else {
              tap_code(KC_RBRC);
              pressed_time = 0;
            }
        }
        break;
    case M_QUOT:
        if (record->event.pressed) { // when keycode is pressed
            pressed_time = record->event.time;
        } else { // when keycode is released
            if (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM) {
              tap_code(KC_QUOT);
              pressed_time = 0;
            } else {
              tap_code(KC_BSLS);
              pressed_time = 0;
            }
        }
        break;
    case M_MINUS:
        if (record->event.pressed) { // when keycode is pressed
            pressed_time = record->event.time;
        } else { // when keycode is released
            if (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM) {
              tap_code(KC_MINUS);
              pressed_time = 0;
            } else {
              tap_code(KC_EQL);
              pressed_time = 0;
            }
        }
        break;
    case M_S_MINUS:
        if (record->event.pressed) { // when keycode is pressed
            pressed_time = record->event.time;
        } else { // when keycode is released
            if (TIMER_DIFF_16(record->event.time, pressed_time) < TAPPING_TERM) {
              register_code(KC_LSFT);
              tap_code(KC_MINUS);
              unregister_code(KC_LSFT);
              pressed_time = 0;
            } else {
              register_code(KC_LSFT);
              tap_code(KC_EQL);
              unregister_code(KC_LSFT);
              pressed_time = 0;
            }
        }
        break;
    }
    return true;
};
