#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)

enum layers {
	_BS,
	_MS,
	_NV,
	_NU,
	_MC,
};

enum custom_keycodes {
	ST_UPDR = SAFE_RANGE,
	ST_LCMT,
	ST_RCMT,
	ST_AND,
	ST_OR,
	ST_NEQL,
	ST_EQL ,
	ST_GEQL,
	ST_LEQL,
	ST_PLPL,
	ST_MNMN,
	ST_PLEQ,
	ST_MNEQ,
	ST_SLEQ,
	ST_ASEQ,
	ST_ARRW,
	ST_COMM,
};

#define SS(kc, s)                \
	case (kc):                    \
           if (record->event.pressed) \
	       SEND_STRING((s));        \
	   return false

#define STRGRP \
	SS(ST_UPDR, "../"); \
	SS(ST_LCMT, "/*"); \
	SS(ST_RCMT, "*/"); \
	SS(ST_AND , "&&"); \
	SS(ST_OR  , "||"); \
	SS(ST_NEQL, "!="); \
	SS(ST_EQL , "=="); \
	SS(ST_GEQL, ">="); \
	SS(ST_LEQL, "<="); \
	SS(ST_PLPL, "++"); \
	SS(ST_MNMN, "--"); \
	SS(ST_PLEQ, "+="); \
	SS(ST_MNEQ, "-="); \
	SS(ST_SLEQ, "/="); \
	SS(ST_ASEQ, "*="); \
	SS(ST_ARRW, "->"); \
	SS(ST_COMM, "//")

// navigation
#define WN_BAK A(KC_LEFT)
#define WN_FWD A(KC_RGHT)
#define WN_HOME A(KC_HOME)
#define WN_OPEN C(KC_O)
#define WN_RE KC_F5
#define WN_REOW C(KC_F5)
#define WN_STOP KC_ESC

// current page
#define WC_NXLK KC_TAB
#define	WC_PVLK S(KC_TAB)
#define WC_NXFR KC_F6
#define WC_PVFR S(KC_F6)
#define WC_PRNT C(KC_P)
#define WC_SAVE C(KC_S)
#define WC_ZIN C(KC_PLUS)
#define WC_ZOUT C(KC_MINS)
#define WC_ZRST C(KC_0)

// search
#define WS_FIND C(KC_F)
#define WS_NEXT KC_F3
#define WS_PREV S(KC_F3)

// windows & tabs
#define WT_RGHT C(KC_PGDN)
#define WT_LEFT C(KC_PGUP)
#define WT_CLSE C(KC_F4)
#define WT_REOP RCS(KC_T)
#define WM_ADDR C(KC_L)
