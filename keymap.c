#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }
#define JA_ANP S(KC_6)  // &
#define JA_EQL S(KC_MINS)  // =
#define JA_SQUOT S(KC_7)  // '

#define JA_HENK  KC_INT4  // =
#define JA_MHEN  KC_INT5  // =


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE  
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   Q  |   W  |   E  |   R  |  T   | Del  |   | Bksp |  Y   |   U  |   I  |   O  |   P  |  \ | |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |  G   | Meta |   |  :   |  H   |   J  |   K  |   L  |Enter |  [   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LSft | LCTL |   Z  |   X  |   C  |  V   | Symb |   |  /   |  B   |   N  |   M  |   ,  |   .  |  ]   |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      | LALT | LGUI | Eisu | Kana |   |Space |  @   |   `  |   '  |   -  |   =  | _ \  |
   * `------------------------------------------------'   `------------------------------------------------'
   */   
  [BASE] = LAYOUT( \
    KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,     KC_DELT,         KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,      JA_ENVL,  \
    KC_TAB,  KC_A,     KC_S,    KC_D,    KC_F,     KC_G,     MO(META),          JA_CLON, KC_H,    KC_J,    KC_K,    KC_L,   KC_ENT,    JA_LBRC,  \
    KC_LSFT,  KC_LCTL,	KC_Z,     KC_X,    KC_C,    KC_V,     MO(SYMB),        KC_SLSH, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    JA_RBRC, \
    /* XXXXXXX, XXXXXXX,  XXXXXXX, KC_LALT, KC_LGUI,  KC_LANG1, KC_LANG2,        KC_SPC,  JA_AT,   KC_GRV,  JA_SQUOT, KC_MINS, JA_EQL,  JA_ENUN   \  for MAC */
    XXXXXXX, XXXXXXX,  XXXXXXX, KC_LALT, KC_LGUI,  JA_HENK, JA_MHEN,        KC_SPC,  JA_AT,   KC_GRV,  JA_SQUOT, KC_MINS, JA_EQL,  JA_ENUN   \
  ),

  /* MET
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |  0   |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | LEFT | DOWN |  UP  |RIGHT |Enter |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |  F2  |  F3  |  F4  |  F5  |  F6  |      |   |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |PrtSc |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,       XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,   \
    XXXXXXX, KC_F1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,       XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |  ESC |   !  |   "  |   #  |   $  |   %  |  Del |   | Home |   &  |   ^  |   *  |  (   |   )  | Inst |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | LCtrl|      |      |      |      |      |  Meta|   | End  | PrvD |      |      | NxtD |Enter | Menu |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |  LSft|      |      |      |      |      |  Symb|   |  /   |      |      |      |      |      | PrtSc|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |  Tab | LCtrl|      | LALT | LGUI | Eisu |  Kana|   |Space |  @   |   `  |   '  |   -  |   =  |  _ \ |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, S(KC_1), KC_AT, S(KC_3), S(KC_4), S(KC_5),   _______,     KC_HOME, JA_ANP, JA_HAT, S(KC_QUOT), S(KC_8), S(KC_9), KC_INSERT, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     KC_END, LGUI(LCTL(KC_LEFT)), XXXXXXX, XXXXXXX, LGUI(LCTL(KC_RGHT)),  _______,  S(KC_F10), \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSCREEN, \
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  _______ \
  )

};

