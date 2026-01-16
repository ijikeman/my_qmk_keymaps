#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  LT(_LOWER, KC_SPC)
#define RAISE  LT(_RAISE, KC_BSPC)
// #define ADJUST MO(_ADJUST)
#define MLCTL  LCTL_T(KC_TAB)
#define MLANG1 LALT(KC_GRV)
#define MLANG2 LCTL(KC_SPC)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ADJUST = SAFE_RANGE,
    M_BRC,
    M_MINUS,
    M_QUOT,
    M_S_MINUS,
    M_ESC,
    WIN_TAB,
    WIN_LEFT,
    WIN_RGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
* ,-----------------------------------------------------------------------------------.
* | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [/] |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |TAB/CTL|  A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | '/\  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Caps |      |      | ALT  |  GUI | LOWER| RAISE| LANG |ADJUST|      |      |      |
* `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    M_BRC,
  MLCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, M_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_CAPS,  KC_NO,  KC_NO, KC_LALT, KC_LGUI,   LOWER,   RAISE,    MLANG1,    ADJUST,  KC_NO,   KC_NO,   KC_NO
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _/+ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  | RGHT |WHEELD|WHEELU|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | DEL  |      |      |      |      |RESET |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, M_S_MINUS,
  _______, _______, _______, _______, _______,_______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, MS_WHLD, MS_WHLU,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, QK_BOOT 
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | -/=  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   M_MINUS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |WIN_L |WIN_T |WIN_R |      |左CLCK|M-LEFT| M-UP |M-DOWN|M-RGHT|右CLCK|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
  _______, _______, WIN_LEFT,WIN_TAB, WIN_RGHT, _______,MS_BTN1, MS_LEFT,  MS_UP, MS_DOWN,  MS_RGHT,  MS_BTN2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
                tap_code(modcode);
                if (layer_code != 0) unregister_code(layer_code);
            } else {
                if (layer_code != 0) register_code(layer_code);
                tap_code(keycode);
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
        // Window切り替え機能(on Windows)
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
};
