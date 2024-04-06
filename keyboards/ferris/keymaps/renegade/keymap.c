#include QMK_KEYBOARD_H
#include "keydef.h"
#include "layouts.h"
#include "g/keymap_combo.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
		STRGRP;
	}
	return true;
}

