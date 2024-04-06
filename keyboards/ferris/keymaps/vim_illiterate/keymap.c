
#include QMK_KEYBOARD_H
#include "keydef.h"
#include "features/select_word.h"
#include "g/keymap_combo.h"

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    // I have a dedicated underscore key, so no need to shift KC_MINS.
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}


bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_R:
        case HOME_S:
        case HOME_N:
        case HOME_D:
        case HOME_A:
        case HOME_E:
        case HOME_I:
        case HOME_H:
        case KC_SPC:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_SPC:
            register_code16((!shifted) ? KC_SPC: KC_TAB);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_SPC:
            unregister_code16((!shifted) ? KC_SPC : KC_TAB);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void shiftedkey_back_to_base(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(keycode);
        layer_clear();
    } else {
	unregister_code(keycode);
        unregister_code(KC_LSFT);
    }
}

void key_back_to_base(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(keycode);
        layer_clear();
    } else {
        unregister_code(keycode);
    }
}

void key_back_to_vim(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
	register_code(keycode);
	layer_move(_VIM);
    } else {
	unregister_code(keycode);
    }
}

void shiftedkey_back_to_vim(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(keycode);
        layer_move(_VIM);
    } else {
	unregister_code(keycode);
        unregister_code(KC_LSFT);
    }
}

uint8_t mod_code = KC_NO;
bool is_mod_tab_active = false;
uint16_t mod_tab_timer = 0;

void mod_tab(uint16_t mod_key, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (!is_mod_tab_active) {
            is_mod_tab_active = true;
            register_code(mod_key);
        }
        mod_code = mod_key;
        mod_tab_timer = timer_read();
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record, SELWORD)) { return false; }
    switch (keycode) {
    case W_VIM:
	if (record->event.pressed) {
	    SEND_STRING(":w\n");
	}
	return false;
    case WQ_VIM:
	if (record->event.pressed) {
	    SEND_STRING(":wq\n");
	    layer_clear();
	}
	return false;
    case Q_VIM:
        if (record->event.pressed) {
            SEND_STRING(":q!\n");
            layer_clear();
        }
        return false;
    case VIM_GG:
	if (record->event.pressed) {
	    SEND_STRING("gg");
	}
	return false;
    case BS_CC:
	if (record->event.pressed) {
	    SEND_STRING("cc");
	    layer_clear();
	}
	return false;
    case CB_DD:
	if (record->event.pressed) {
	    SEND_STRING("dd");
	}
	return false;
    case VI_ESC:
        if (record->event.pressed) {
            register_code(KC_ESC);
            layer_on(_VIM);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
    case BS_I:
        key_back_to_base(KC_I, record);
        return false;
    case BS_O:
        key_back_to_base(KC_O, record);
        return false;
    case OSL_R:
        key_back_to_base(KC_R, record);
        return false;
    case BS_A:
        key_back_to_base(KC_A, record);
        return false;
    case BS_SLS:
	key_back_to_base(KC_SLSH, record);
	return false;
    case BS_QUE:
	shiftedkey_back_to_base(KC_QUES, record);
	return false;
    case BS_COL:
        shiftedkey_back_to_base(KC_SCLN, record);
        return false;
    case BS_RC:
        shiftedkey_back_to_base(KC_R, record);
        return false;
    case BS_OC:
        shiftedkey_back_to_base(KC_O, record);
        return false;
    case BS_AC:
        shiftedkey_back_to_base(KC_A, record);
        return false;
    case AU_V:
        if (record->event.pressed) {
            register_code(KC_V);
            layer_on(_VISUAL);
        } else {
            unregister_code(KC_V);
        }
        return false;
    case AU_C:
        if (record->event.pressed) {
            register_code(KC_C);
            layer_on(_VCHGE);
        } else {
            unregister_code(KC_C);
        }
        return false;
    case AU_D:
        if (record->event.pressed) {
            register_code(KC_D);
            layer_on(_VNUM);
        } else {
            unregister_code(KC_D);
        }
        return false;
    case AU_Y:
        if (record->event.pressed) {
            register_code(KC_Y);
            layer_on(_VNUM);
        } else {
            unregister_code(KC_Y);
        }
        return false;
    case AT_GG:
	if (record->event.pressed) {
	    SEND_STRING("gg");
	    layer_move(_VIM);
	}
	return false;
    case AT_CAPG:
	shiftedkey_back_to_vim(KC_G, record);
	return false;
    case AT_LEFT:
	key_back_to_vim(KC_LEFT, record);
	return false;
    case AT_RGHT:
	key_back_to_vim(KC_RGHT, record);
	return false;
    case AT_UP:
	key_back_to_vim(KC_UP, record);
	return false;
    case AT_DOWN:
	key_back_to_vim(KC_DOWN, record);
	return false;
    case AT_B:
	key_back_to_vim(KC_B, record);
	return false;
    case AT_PERC:
	shiftedkey_back_to_vim(KC_PERC, record);
	return false;
    case AT_DLR:
	shiftedkey_back_to_vim(KC_DLR, record);
	return false;
    case AT_CIRC:
	shiftedkey_back_to_vim(KC_CIRC, record);
	return false;
    case AT_E:
	key_back_to_vim(KC_E, record);
	return false;
    case AT_W:
	key_back_to_vim(KC_W, record);
	return false;
    case AT_D:
	key_back_to_vim(KC_D, record);
	return false;
    case AT_Y:
	key_back_to_vim(KC_Y, record);
	return false;
    case AT_P:
	key_back_to_vim(KC_P, record);
	return false;
    case AT_ESC:
	key_back_to_vim(KC_ESC, record);
	return false;
    case BS_C:
	key_back_to_base(KC_C, record);
	return false;
    case BS_GG:
	SEND_STRING("GG");
	layer_clear();
	return false;
    case BS_CAPG:
	shiftedkey_back_to_base(KC_G, record);
	return false;
    case BS_LEFT:
	key_back_to_base(KC_LEFT, record);
	return false;
    case BS_UP:
	key_back_to_base(KC_UP, record);
	return false;
    case BS_RGHT:
	key_back_to_base(KC_RGHT, record);
	return false;
    case BS_DOWN:
	key_back_to_base(KC_DOWN, record);
	return false;
    case BS_B:
	key_back_to_base(KC_B, record);
	return false;
    case BS_PERC:
	shiftedkey_back_to_base(KC_PERC, record);
	return false;
    case BS_DLR:
	shiftedkey_back_to_base(KC_DLR, record);
	return false;
    case BS_CIRC:
	shiftedkey_back_to_base(KC_CIRC, record);
	return false;
    case BS_E:
	key_back_to_base(KC_E, record);
	return false;
    case BS_W:
	key_back_to_base(KC_W, record);
	return false;
    case ALT_TAB:
        mod_tab(KC_LALT, KC_TAB, record);
        break;
    case CTL_TAB:
        mod_tab(KC_LCTL, KC_PGDN, record);
        break;
    case UP_DIR:
        if (record->event.pressed) {
            SEND_STRING("../");
        }
        return false;
    case SB_AND:
        if (record->event.pressed) {
	    SEND_STRING("&&");
	}
	return false;
    case SB_NEQL:
	if (record->event.pressed) {
	    SEND_STRING("!=");
	}
	return false;
    case SB_OR:
        if (record->event.pressed) {
            SEND_STRING("||");
        }
        return false;
    case SB_GT:
        if (record->event.pressed) {
            SEND_STRING(">=");
        }
        return false;
    case SB_EQL:
        if (record->event.pressed) {
            SEND_STRING("==");
        }
        return false;
    case SB_LT:
        if (record->event.pressed) {
            SEND_STRING("<=");
        }
        return false;
    case SB_SLEQ:
        if (record->event.pressed) {
            SEND_STRING("/=");
        }
        return false;
    case SB_PLPL:
        if (record->event.pressed) {
            SEND_STRING("++");
        }
        return false;
    case SB_MNMN:
        if (record->event.pressed) {
            SEND_STRING("--");
        }
        return false;
    case SB_ASEQ:
        if (record->event.pressed) {
            SEND_STRING("*=");
        }
        return false;
    case SB_PLEQ:
        if (record->event.pressed) {
            SEND_STRING("+=");
        }
        return false;
    case SB_MNEQ:
        if (record->event.pressed) {
            SEND_STRING("-=");
        }
        return false;
    case SB_LRBR:
        if (record->event.pressed) {
            SEND_STRING("[]");
        }
        return false;
    case SB_RARR:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        return false;
    case SB_DBAS:
        if (record->event.pressed) {
            SEND_STRING("**");
        }
        return false;
    case SB_EQ0:
        if (record->event.pressed) {
            SEND_STRING("= 0;");
        }
        return false;
    case SB_LRPN:
        if (record->event.pressed) {
            SEND_STRING("()");
        }
        return false;
    case SB_PNCB:
        if (record->event.pressed) {
            SEND_STRING(") {");
        }
        return false;
    case SB_CLCM:
        if (record->event.pressed) {
            SEND_STRING("*/");
        }
        return false;
    case SB_DBSL:
        if (record->event.pressed) {
            SEND_STRING("//");
        }
        return false;
    case SB_OPCM:
        if (record->event.pressed) {
            SEND_STRING("/*");
        }
        return false;
    }
    return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_mod_tab_active) {
    if (timer_elapsed(mod_tab_timer) > 900) {
      unregister_code(mod_code);
      is_mod_tab_active = false;
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_J   , KC_G   , KC_M   , KC_P   , KC_V   ,         KC_DQUO, KC_COMM, KC_DOT , KC_UNDS, KC_SLSH,
    HOME_R , HOME_S , HOME_N , HOME_D , KC_B   ,         KC_SCLN, HOME_A , HOME_E , HOME_I , HOME_H ,
    KC_X   , KC_F   , KC_L   , KC_C   , KC_W   ,         KC_MINS, KC_U   , KC_O   , KC_Y   , KC_K   ,
                                    KC_T   , KC_BSPC, KC_ENT , KC_SPC
  ),
  
  [_VIM] = LAYOUT(
    KC_CIRC, KC_B   , KC_UP  , KC_PGUP, VIM_GG ,         VIM_RDO, KC_U   , BS_OC  , KC_X   , OSL_R  ,
    KC_0   , KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR ,         KC_P   , AU_V   , BS_I   , BS_A   , BS_AC  ,
    KC_PERC, BS_SLS , CTL_G  , KC_PGDN, CAP_G  ,         AU_Y   , AU_D   , BS_O   , AU_C   , BS_RC  ,
                                    KC_E   , KC_W   , BS_COL , KC_DOT
  ),

  [_VIM2] = LAYOUT(
    _______, _______, _______, _______, _______,         CTL_RBR, CAP_U  , KC_N   , CTL_O  , _______,
    _______, _______, _______, _______, _______,         CTL_W  , KC_P   , KC_ESC , KC_Y   , _______,
    _______, _______, _______, _______, _______,         BS_QUE , W_VIM  , CAP_N  , CTL_I  , _______,
                                    TG_VIM2, _______, _______, _______
  ),

  [_VNUM] = LAYOUT(
    AT_CIRC, AT_B   , AT_UP  , KC_8   , AT_GG  ,         _______, KC_9   , _______, _______, _______,
    KC_6   , KC_4   , KC_0   , KC_2   , AT_DLR ,         _______, KC_3   , KC_1   , KC_5   , KC_7   ,
    AT_PERC, AT_LEFT, AT_DOWN, AT_RGHT, AT_CAPG,         AT_Y   , AT_D   , _______, _______, _______,
                                    AT_E   , AT_W   , _______, _______
  ),

  [_VISUAL] = LAYOUT(
    KC_CIRC, KC_B   , KC_UP  , KC_8   , VIM_GG ,         _______, KC_9   , _______, _______, _______,
    KC_6   , KC_4   , KC_0   , KC_2   , KC_DLR ,         AT_P   , KC_3   , KC_1   , KC_5   , KC_7   ,
    KC_PERC, KC_LEFT, KC_DOWN, KC_RGHT, CAP_G  ,         AT_Y   , AT_D   , _______, BS_C   , _______,
                                    KC_E   , KC_W   , _______, _______
  ),

  [_VCHGE] = LAYOUT(
    BS_CIRC, BS_B   , BS_UP  , KC_8   , BS_GG  ,         _______, KC_9   , _______, _______, _______,
    KC_6   , KC_4   , KC_0   , KC_2   , BS_DLR ,         _______, KC_3   , KC_1   , KC_5   , KC_7   ,
    BS_PERC, BS_LEFT, BS_DOWN, BS_RGHT, BS_CAPG,         _______, _______, _______, BS_C   , _______,
                                    BS_E   , BS_W   , _______, _______
  ),

  [_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______,         _______, KC_WH_U, KC_MS_U, KC_BTN3, _______,
    _______, KC_BTN2, KC_NO  , KC_BTN1, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,
    _______, _______, _______, _______, _______,         _______, KC_WH_D, KC_WH_L, KC_WH_R, _______,
                                    _______, _______, TG_MOUS, KC_BTN1
  ),

  [_NAV] = LAYOUT(
    _______, KC_HOME, KC_UP  , KC_PGUP, SELWORD,         _______, _______, KC_WBAK, KC_WFWD, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,         _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,
    _______, KC_END , KC_DOWN, KC_PGDN, _______,         _______, _______, _______, _______, _______,
                                    TG_NAV , _______, _______, _______
  ),
  
  [_SYM] = LAYOUT(
    KC_CIRC, KC_LT  , KC_GT  , KC_HASH, KC_AMPR,         _______, KC_LBRC, KC_RBRC, UP_DIR , KC_GRV ,
    KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_PIPE,         _______, KC_LPRN, KC_RPRN, KC_QUOT, KC_QUES,
    KC_PERC, KC_SLSH, KC_ASTR, KC_BSLS, KC_TILD,         KC_COLN, KC_LCBR, KC_RCBR, KC_DLR , KC_AT  ,
                                    TG_SYM , _______, _______, _______
  ),
  
  [_FUNC] = LAYOUT(
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
    KC_F6  , KC_F4  , KC_F10 , KC_F2  , _______,         _______, KC_F3  , KC_F1  , KC_F5  , KC_F7  ,
    _______, _______, KC_F12 , KC_8   , _______,         _______, KC_F9  , KC_F11 , _______, _______,
                                    TG_FUNC, _______, _______, _______
  ),
  
  [_NUMS] = LAYOUT(
    KC_CIRC, KC_LT  , KC_K   , CAP_G  , KC_RGHT,         KC_DOT , KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS,
    HOME_6 , HOME_4 , HOME_0 , HOME_2 , KC_PEQL,         _______, HOME_3 , HOME_1 , HOME_5 , HOME_7 ,
    KC_PERC, KC_GT  , KC_J   , KC_8   , KC_LEFT,         KC_COMM, KC_9   , KC_LPRN, KC_RPRN, KC_RBRC,
                                    TG_NUMS, _______, _______, _______
  ),
};
