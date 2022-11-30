#include QMK_KEYBOARD_H

// create some custom keycodes for your keymap
enum custom_keycodes {
  PREV_DESKTOP = SAFE_RANGE,
  NEXT_DESKTOP
};

// define some useful send strings
#define SS_PREV_DESKTOP SS_LCTL(SS_RGUI(SS_TAP(X_LEFT)))
#define SS_NEXT_DESKTOP SS_LCTL(SS_RGUI(SS_TAP(X_RIGHT)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_2key( \
                KC_ESC,       KC_1,       KC_2,          KC_3,          KC_4,       KC_5,       KC_MINS,                KC_EQL,     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV,  \
                KC_TAB,       KC_Q,       KC_W,          KC_E,          KC_R,       KC_T,       KC_LPRN,                KC_RPRN,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_PGUP, \
                KC_CAPS,      KC_A,       KC_S,          KC_D,          KC_F,       KC_G,       KC_BSLS,                KC_QUOT,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_PGDN, \
                KC_LSFT,      KC_Z,       KC_X,          KC_C,          KC_V,       KC_B,                                           KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT, \
                KC_LCTL,      KC_LALT,    KC_RALT,       LT(1,KC_NO),   KC_LGUI,    KC_SPC,                                         KC_ENT,     KC_BSPC,    KC_DEL,     KC_RALT,    KC_RGUI,    KC_RCTL  \
                 ),
   [1] = LAYOUT_2key( \
                KC_ESC,       KC_F1,      KC_F2,         KC_F3,         KC_F4,      KC_F5,      KC_F6,                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR, \
                KC_TAB,       KC_NO,      KC_NO,         KC_END,        KC_NO,      KC_NO,      KC_LBRC,                KC_RBRC,    KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_UP,      KC_NUM, \
                KC_NO,        KC_HOME,    PREV_DESKTOP,  NEXT_DESKTOP,  KC_RGHT,    KC_NO,      KC_NO,                  KC_NO,      KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_NO,   \
                KC_LSFT,      KC_NO,      KC_NO,         KC_NO,         KC_NO,      KC_LEFT,                                        KC_DOWN,    KC_P1,      KC_P2,      KC_P3,      KC_PMNS,    KC_RSFT, \
                KC_LCTL,      KC_LALT,    KC_NO,         KC_TRNS,       KC_LGUI,    KC_SPC,                                         KC_ENT,     KC_P0,      KC_PDOT,    KC_NO,      KC_EQL,     KC_RCTL  \
                 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case NEXT_DESKTOP:
    if (record->event.pressed) {
      // do nothing on press
    } else {
      SEND_STRING(SS_NEXT_DESKTOP);
    }
    return false;
  case PREV_DESKTOP:
    if (record->event.pressed) {
      // do nothing on press
    } else {
      SEND_STRING(SS_PREV_DESKTOP);
    }
    return false;
  default:
    return true; // Process all other keycodes normally
  }
}
