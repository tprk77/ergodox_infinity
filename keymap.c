/* Copyright (c) 2017 Tim Perkins */

#include QMK_KEYBOARD_H

#define KEYMAP LAYOUT_ergodox

#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum tprk77_layers {
  LR_CLMK = 0,  /* COLEMAK (BASE) */
  LR_LWR  = 1,  /* LOWER */
  LR_RSE  = 2,  /* RAISE */
  LR_NAV  = 3,  /* NAV */
  LR_GMNG = 4,  /* GAMING */
  LR_GS   = 5   /* GAME SHIFT */
};

enum tprk77_fns {
  MO_NAV  = KC_FN0,
  TG_GMNG = KC_FN1,
};

enum tprk77_mod_keys {
  MD_HYPR = ALL_T(KC_NO),
  MD_MEH  = MEH_T(KC_NO),
  MD_CSPC = LCTL(KC_SPC),
  MD_CENT = LCTL(KC_ENT),
  MD_CBSP = LCTL(KC_BSPC),
  MD_MX   = LALT(KC_X),
  MD_CG   = LCTL(KC_G),
  MD_MW   = LALT(KC_W),
  MD_CW   = LCTL(KC_W),
  MD_CY   = LCTL(KC_Y),
  MD_CS   = LCTL(KC_S),
  MD_CR   = LCTL(KC_R),
  MD_CL   = LCTL(KC_L),
  MD_CK   = LCTL(KC_K),
  MD_CQUE = LCTL(KC_QUES),
  MD_CSLS = LCTL(KC_SLSH),
};

#define SR SAFE_RANGE

enum tprk77_keys {
  MO_LLWR = SR, /* Left Lower */
  MO_RLWR,      /* Right Lower */
  MO_LRSE,      /* Left Raise */
  MO_RRSE,      /* Right Raise */
  MC_0P0,       /* 0.0 */
  MC_PI,        /* 3.14159265358979323846 (As defined in "math.h") */
  MC_CXO,       /* C-x o   (Next window) */
  MC_CXCO,      /* C-x C-o (Previous window) */
  MC_CXCF,      /* C-x C-f (Open file) */
  MC_CXCS,      /* C-x C-s (Save file) */
  MC_CXB,       /* C-x b   (Switch buffer) */
  MC_CXK,       /* C-x k   (Kill buffer) */
  MC_CCO        /* C-c o   (Jump to window) */
};

#undef SR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * COLEMAK (BASE) LAYER:
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |  Esc   |   1  |   2  |   3  |   4  |   5  |  =   |
   * |--------+------+------+------+------+------+------|
   * |  Tab   |   Q  |   W  |   F  |   P  |   G  |  [   |
   * |--------+------+------+------+------+------|      |
   * |  Ctrl  |   A  |   R  |   S  |   T  |   D  |------|
   * |--------+------+------+------+------+------| Hyper|
   * |  Shift |   Z  |   X  |   C  |   V  |   B  |      |
   * `--------+------+------+------+------+-------------'
   *   | GUI  | Ins  | App  | Left | Right|
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        | Ctrl | Alt  |
   *                                 ,------|------|------|
   *                                 |      |      | Raise|
   *                                 | Bspc | Nav  |------|
   *                                 |      |      | Lower|
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   ,--------------------------------------------------.
   *   |  -   |   6  |   7  |   8  |   9  |   0  |  Bspc  |
   *   |------+------+------+------+------+------+--------|
   *   |  ]   |   J  |   L  |   U  |   Y  |   ;  |   \    |
   *   |      |------+------+------+------+------+--------|
   *   |------|   H  |   N  |   E  |   I  |   O  |   '    |
   *   | Meh  |------+------+------+------+------+--------|
   *   |      |   K  |   M  |   ,  |   .  |   /  | Shift  |
   *   `-------------+------+------+------+------+--------'
   *                 |  Up  | Down | Gmng |   `  | GUI  |
   *                 `----------------------------------'
   * ,-------------.
   * | Alt  | Ctrl |
   * |------|------|------.
   * | Raise|      |      |
   * |------| Space| Enter|
   * | Lower|      |      |
   * `--------------------'
   */
  [LR_CLMK] = KEYMAP(
      /* LEFT: */
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MD_HYPR,
      KC_LGUI, KC_INS,  KC_APP,  KC_LEFT, KC_RGHT,
                                                   KC_LCTL, KC_LALT,
                                                            MO_LRSE,
                                          KC_BSPC, MO_NAV,  MO_LLWR,
      /* RIGHT: */
      KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      MD_MEH,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_UP,   KC_DOWN, TG_GMNG, KC_GRV,  KC_RGUI,
      KC_LALT, KC_LCTL,
      MO_RRSE,
      MO_RLWR, KC_SPC,  KC_ENT
  ),

  /*
   * LOWER LAYER:
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |  Esc   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |--------+------+------+------+------+------+------|
   * |  Tab   |  F1  |  F2  |  F3  |  F4  |  F5  | XXXX |
   * |--------+------+------+------+------+------|      |
   * |  Ctrl  |  1   |  2   |  3   |  4   |  5   |------|
   * |--------+------+------+------+------+------| Hyper|
   * |  Shift |  U   |  L   |  F   |  E   |  Pi  |      |
   * `--------+------+------+------+------+-------------'
   *   | GUI  | Ins  | App  | Left | Right|
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        | Ctrl | Alt  |
   *                                 ,------|------|------|
   *                                 | Ctrl |      | XXXX |
   *                                 | Bspc | XXXX |------|
   *                                 |      |      | Lower|
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   ,--------------------------------------------------.
   *   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  Del   |
   *   |------+------+------+------+------+------+--------|
   *   | XXXX |  F6  |  F7  |  F8  |  F9  |  F10 |  XXXX  |
   *   |      |------+------+------+------+------+--------|
   *   |------|  6   |  7   |  8   |  9   |  0   |  XXXX  |
   *   | Meh  |------+------+------+------+------+--------|
   *   |      |  +   |  -   |  ,   |  .   | 0.0  | Shift  |
   *   `-------------+------+------+------+------+--------'
   *                 |  Up  | Down | XXXX | XXXX | GUI  |
   *                 `----------------------------------'
   * ,-------------.
   * | Alt  | Ctrl |
   * |------|------|------.
   * | XXXX |      |      |
   * |------| Space| Enter|
   * | Lower|      |      |
   * `--------------------'
   */
  [LR_LWR] = KEYMAP(
      /* LEFT: */
      KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,
      KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
      KC_LSFT, KC_U,    KC_L,    KC_F,    KC_E,    MC_PI,   MD_HYPR,
      KC_LGUI, KC_INS,  KC_APP,  KC_LEFT, KC_RGHT,
                                                   KC_LCTL, KC_LALT,
                                                            XXXXXXX,
                                          MD_CBSP, XXXXXXX, MO_LLWR,
      /* RIGHT: */
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
      XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
      MD_MEH,  KC_PLUS, KC_MINS, KC_COMM, KC_DOT,  MC_0P0,  KC_RSFT,
                        KC_UP,   KC_DOWN, XXXXXXX, XXXXXXX, KC_RGUI,
      KC_RALT, KC_RCTL,
      XXXXXXX,
      MO_RLWR,  KC_SPC,  KC_ENT
  ),

  /*
   * RAISE LAYER:
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |  Esc   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |--------+------+------+------+------+------+------|
   * |  Tab   |  \   |  =   |  <   |  >   |  `   | XXXX |
   * |--------+------+------+------+------+------|      |
   * |  Ctrl  |  !   |  -   |  (   |  )   |  "   |------|
   * |--------+------+------+------+------+------| Hyper|
   * |  Shift |  $   |  @   |  /   |  *   |  +   |      |
   * `--------+------+------+------+------+-------------'
   *   | GUI  | Ins  | App  | Left | Right|
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        | Ctrl | Alt  |
   *                                 ,------|------|------|
   *                                 | Ctrl |      | Raise|
   *                                 | Bspc | XXXX |------|
   *                                 |      |      | XXXX |
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   ,--------------------------------------------------.
   *   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  Del   |
   *   |------+------+------+------+------+------+--------|
   *   | XXXX |  ?   |  [   |  ]   |  :   |  ;   |  XXXX  |
   *   |      |------+------+------+------+------+--------|
   *   |------|  '   |  {   |  }   |  _   |  #   |  XXXX  |
   *   | Meh  |------+------+------+------+------+--------|
   *   |      |  ~   |  &   |  |   |  ^   |  %   | Shift  |
   *   `-------------+------+------+------+------+--------'
   *                 |  Up  | Down | XXXX | XXXX | GUI  |
   *                 `----------------------------------'
   * ,-------------.
   * | Alt  | Ctrl |
   * |------|------|------.
   * | Raise|      |      |
   * |------| Space| Enter|
   * | XXXX |      |      |
   * `--------------------'
   */
  [LR_RSE] = KEYMAP(
      /* LEFT: */
      KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TAB,  KC_BSLS, KC_EQL,  KC_LABK, KC_RABK, KC_GRV,  XXXXXXX,
      KC_LCTL, KC_EXLM, KC_MINS, KC_LPRN, KC_RPRN, KC_DQT,
      KC_LSFT, KC_DLR,  KC_AT,   KC_SLSH, KC_ASTR, KC_PLUS, MD_HYPR,
      KC_LGUI, KC_INS,  KC_APP,  KC_LEFT, KC_RGHT,
                                                   KC_LCTL, KC_LALT,
                                                            MO_LRSE,
                                          MD_CBSP, XXXXXXX, XXXXXXX,
      /* RIGHT: */
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
      XXXXXXX, KC_QUES, KC_LBRC, KC_RBRC, KC_COLN, KC_SCLN, XXXXXXX,
               KC_QUOT, KC_LCBR, KC_RCBR, KC_UNDS, KC_HASH, XXXXXXX,
      MD_MEH,  KC_TILD, KC_AMPR, KC_PIPE, KC_CIRC, KC_PERC, KC_RSFT,
                        KC_UP,   KC_DOWN, XXXXXXX, XXXXXXX, KC_RGUI,
      KC_RALT, KC_RCTL,
      MO_RRSE,
      XXXXXXX, KC_SPC,  KC_ENT
  ),

  /*
   * NAV LAYER:
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |  Esc   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |--------+------+------+------+------+------+------|
   * |  Tab   | C-?  |C-xC-o| C-x o| M-x  | C-g  | C-x  |
   * |--------+------+------+------+------+------| C-s  |
   * |  Ctrl  | C-l  | C-w  | M-w  | C-y  | Del  |------|
   * |--------+------+------+------+------+------| Hyper|
   * |  Shift | C-/  | C-r  | C-s  | C-x b| C-x k|      |
   * `--------+------+------+------+------+-------------'
   *   | GUI  | Ins  | App  | Left | Right|
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        | Ctrl | Alt  |
   *                                 ,------|------|------|
   *                                 |      |      | Alt  |
   *                                 | Bspc | Nav  |------|
   *                                 |      |      | Ctrl |
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   ,--------------------------------------------------.
   *   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  Del   |
   *   |------+------+------+------+------+------+--------|
   *   | XXXX | PgUp | Home |  Up  |  End | XXXX |  XXXX  |
   *   |      |------+------+------+------+------+--------|
   *   |------| PgDn | Left | Down | Right| XXXX |  XXXX  |
   *   | Meh  |------+------+------+------+------+--------|
   *   |      | C-k  | XXXX | XXXX | XXXX | XXXX | Shift  |
   *   `-------------+------+------+------+------+--------'
   *                 |  Up  | Down | XXXX | XXXX | GUI  |
   *                 `----------------------------------'
   * ,-------------.
   * | Alt  | Ctrl |
   * |------|------|------.
   * | XXXX | Ctrl | Ctrl |
   * |------| Space| Enter|
   * | XXXX |      |      |
   * `--------------------'
   */
  [LR_NAV] = KEYMAP(
      /* LEFT: */
      KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TAB,  MD_CQUE, MC_CXCO, MC_CXO,  MD_MX,   MD_CG,   MC_CXCS,
      KC_LCTL, MD_CL,   MD_CW,   MD_MW,   MD_CY,   KC_DEL,
      KC_RSFT, MD_CSLS, MD_CR,   MD_CS,   MC_CXB,  MC_CXK,  MD_HYPR,
      KC_LGUI, KC_INS,  KC_APP,  KC_LEFT, KC_RGHT,
                                                   KC_LCTL, KC_LALT,
                                                            KC_LALT,
                                          KC_BSPC, MO_NAV,  KC_LCTL,
      /* RIGHT: */
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
      XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
               KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      MD_MEH,  MD_CK,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
                        KC_UP,   KC_DOWN, XXXXXXX, XXXXXXX, KC_LGUI,
      KC_RALT, KC_RCTL,
      XXXXXXX,
      XXXXXXX, MD_CSPC, MD_CENT
  ),

  /*
   * GAMING LAYER:
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |   F1   |   1  |   2  |   3  |   4  |   5  |   6  |
   * |--------+------+------+------+------+------+------|
   * |   F2   | Tab  |   Q  |   W  |   E  |   R  |   7  |
   * |--------+------+------+------+------+------|      |
   * |   F3   | Ctrl |   A  |   S  |   D  |   F  |------|
   * |--------+------+------+------+------+------|   8  |
   * |   F4   | Shift|   Z  |   X  |   C  |   G  |      |
   * `--------+------+------+------+------+-------------'
   *   |  Bs  | Alt  |   J  |   M  |   I  |
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        |   9  |   0  |
   *                                 ,------|------|------|
   *                                 |      |      | PgUp |
   *                                 | Esc  | Space|------|
   *                                 |      |      | PgDn |
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   (ALL KEYS TOGGLE OUT OF LAYER.)
   */
  [LR_GMNG] = KEYMAP(
      /* LEFT: */
      KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
      KC_F2,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_7,
      KC_F3,   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,
      KC_F4,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_G,    KC_8,
      KC_BSPC, KC_LALT, KC_J,    KC_M,    KC_I,
                                                   KC_9,    KC_0,
                                                            KC_PGUP,
                                          KC_ESC,  KC_SPC,  KC_PGDN,
      /* RIGHT: */
      TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG,
      TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG,
               TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG,
      TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG,
                        TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG, TG_GMNG,
      TG_GMNG, TG_GMNG,
      TG_GMNG,
      TG_GMNG, TG_GMNG, TG_GMNG
  ),

  /* TODO */
  /* [LR_GS] = KEYMAP( */
  /* ) */
};

const uint16_t PROGMEM fn_actions[] = {
  /* MO_NAV  */ [0] = ACTION_LAYER_MOMENTARY(LR_NAV),
  /* TG_GMNG */ [1] = ACTION_LAYER_TOGGLE(LR_GMNG),
};

#define LEFT_KEY_STATE  (1U << 0)
#define RIGHT_KEY_STATE (1U << 1)

void update_left_right_layer(const uint16_t keycode, const keyrecord_t* const record,
                             const uint16_t left_keycode, const uint16_t right_keycode,
                             const uint8_t layer, uint8_t* keys_state_ptr)
{
  const uint32_t layer_mask = (1UL << layer);
  const uint16_t old_keys_state = *keys_state_ptr;
  /* Update the state of the left and right keys */
  if (record->event.pressed) {
    if (keycode == left_keycode) {
      *keys_state_ptr |= LEFT_KEY_STATE;
    } else if (keycode == right_keycode) {
      *keys_state_ptr |= RIGHT_KEY_STATE;
    }
  } else {
    if (keycode == left_keycode) {
      *keys_state_ptr &= ~LEFT_KEY_STATE;
    } else if (keycode == right_keycode) {
      *keys_state_ptr &= ~RIGHT_KEY_STATE;
    }
  }
  /* Update the layer if the state has transitioned */
  if (*keys_state_ptr && !old_keys_state) {
    layer_state_set(layer_state | layer_mask);
  } else if (!*keys_state_ptr && old_keys_state) {
    layer_state_set(layer_state & ~layer_mask);
  }
}

uint8_t lower_keys_state = 0;
uint8_t raise_keys_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  /* Update the left/right layer keys */
  update_left_right_layer(keycode, record, MO_LLWR, MO_RLWR, LR_LWR, &lower_keys_state);
  update_left_right_layer(keycode, record, MO_LRSE, MO_RRSE, LR_RSE, &raise_keys_state);
  /* Process macro keys */
  if (record->event.pressed) {
    switch (keycode) {
      case MC_0P0:
        SEND_STRING("0.0");
        return false;
      case MC_PI:
        SEND_STRING("3.14159265358979323846");
        return false;
      case MC_CXO:
        SEND_STRING(SS_LCTRL("x") "o");
        return false;
      case MC_CXCO:
        SEND_STRING(SS_LCTRL("xo"));
        return false;
      case MC_CXCF:
        SEND_STRING(SS_LCTRL("xf"));
        return false;
      case MC_CXCS:
        SEND_STRING(SS_LCTRL("xs"));
        return false;
      case MC_CXB:
        SEND_STRING(SS_LCTRL("x") "b");
        return false;
      case MC_CXK:
        SEND_STRING(SS_LCTRL("x") "k");
        return false;
      case MC_CCO:
        SEND_STRING(SS_LCTRL("c") "o");
        return false;
    }
  }
  return true;
}

void set_leds_by_layer(const uint8_t layer_ind)
{
  /* If each LED is a bit, we can indicate up to seven layers (at least one LED is on) */
  const uint8_t adj_layer_ind = layer_ind < 7 ? layer_ind + 1 : 0;
  /* Layers over seven will just blank the LEDs */
  const bool led_1_is_on = (adj_layer_ind >> 0) & 0x01;
  const bool led_2_is_on = (adj_layer_ind >> 1) & 0x01;
  const bool led_3_is_on = (adj_layer_ind >> 2) & 0x01;
  /* Set all LEDs */
  led_1_is_on ? ergodox_right_led_1_on() : ergodox_right_led_1_off();
  led_2_is_on ? ergodox_right_led_2_on() : ergodox_right_led_2_off();
  led_3_is_on ? ergodox_right_led_3_on() : ergodox_right_led_3_off();
}

void matrix_init_user(void)
{
  ergodox_led_all_set(LED_BRIGHTNESS_LO);
}

void matrix_scan_user(void)
{
  uint8_t layer = biton32(layer_state);
  set_leds_by_layer(layer);
}

  /*
   * LAYER TEMPLATE
   *
   * LEFT:
   *
   * ,--------------------------------------------------.
   * |  Esc   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |--------+------+------+------+------+------+------|
   * |  Tab   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
   * |--------+------+------+------+------+------|      |
   * |  Ctrl  | XXXX | XXXX | XXXX | XXXX | XXXX |------|
   * |--------+------+------+------+------+------| Hyper|
   * |  Shift | XXXX | XXXX | XXXX | XXXX | XXXX |      |
   * `--------+------+------+------+------+-------------'
   *   | GUI  | Ins  | App  | Left | Right|
   *   `----------------------------------'
   *                                        ,-------------.
   *                                        | Home | End  |
   *                                 ,------|------|------|
   *                                 |      |      | Alt  |
   *                                 | Bspc | Nav  |------|
   *                                 |      |      | Lower|
   *                                 `--------------------'
   *
   * RIGHT:
   *
   *   ,--------------------------------------------------.
   *   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  Bspc  |
   *   |------+------+------+------+------+------+--------|
   *   | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |  XXXX  |
   *   |      |------+------+------+------+------+--------|
   *   |------| XXXX | XXXX | XXXX | XXXX | XXXX |  XXXX  |
   *   | Meh  |------+------+------+------+------+--------|
   *   |      | XXXX | XXXX | XXXX | XXXX | XXXX | Shift  |
   *   `-------------+------+------+------+------+--------'
   *                 |  Up  | Down | Gmng | XXXX | GUI  |
   *                 `----------------------------------'
   * ,-------------.
   * | PgUp | PgDn |
   * |------|------|------.
   * | Ctrl |      |      |
   * |------| Space| Enter|
   * | Raise|      |      |
   * `--------------------'
   */

/* (setq tab-stop-list '(6 15 24 33 42 51 60 69)) */
