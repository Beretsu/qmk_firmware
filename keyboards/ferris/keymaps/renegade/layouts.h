const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BS] = LAYOUT(
    KC_J   , KC_G   , KC_M   , KC_P   , KC_V   ,         KC_SCLN, KC_COMM, KC_DOT , KC_UNDS, KC_Q   ,
    KC_R   , KC_S   , KC_N   , KC_D   , KC_B   ,         KC_DQUO, KC_A   , KC_E   , KC_I   , KC_H   ,
    KC_X   , KC_F   , KC_L   , KC_C   , KC_W   ,         KC_QUOT, KC_U   , KC_O   , KC_Y   , KC_K   ,
                                    KC_T   , KC_BSPC, KC_ENT , KC_SPC
  ),

  [_MS] = LAYOUT(
    _______, _______, KC_MS_U, KC_WH_U, _______,         _______, KC_WH_U, KC_MS_U, KC_BTN3, _______,
    KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,         KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
    KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_D, _______,         _______, KC_WH_D, KC_ACL2, KC_ACL1, KC_ACL0,
                                    KC_BTN2, KC_BTN1, KC_BTN1, KC_BTN2
  ),

  [_NV] = LAYOUT(
    _______, WS_PREV, KC_UP  , KC_PGUP, KC_HOME,         KC_HOME, KC_PGUP, KC_UP  , KC_HOME, KC_Q   ,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,         _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
    _______, WS_NEXT, WS_FIND, KC_PGDN, KC_END ,         KC_END , KC_PGDN, _______, KC_END , _______,
                                    _______, _______, _______, _______
  ),

  [_NU] = LAYOUT(
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
    KC_6   , KC_4   , KC_0   , KC_2   , _______,         _______, KC_3   , KC_1   , KC_5   , KC_7   ,
    _______, _______, _______, KC_8   , _______,         _______, KC_9   , _______, _______, _______,
                                    _______, _______, _______, _______
  ),

  [_MC] = LAYOUT(
    KC_WSCH, KC_WBAK, KC_WFWD, KC_WSTP, KC_WREF,         KC_WHOM, KC_WFAV, _______, _______, _______,
    KC_SLCT, KC_BRIU, KC_BRID, KC_PSCR, KC_PAUS,         KC_DEL , KC_INS , KC_PWR , KC_SLEP, KC_WAKE,
    KC_EXEC, KC_HELP, KC_MENU, KC_STOP, KC_FIND,         KC_AGIN, KC_UNDO, KC_CUT , KC_COPY, KC_PSTE,
                               _______, KC_APP ,         _______, _______
  ),
};
