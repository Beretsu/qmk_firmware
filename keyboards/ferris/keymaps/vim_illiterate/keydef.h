#ifndef KEYDEF
#define KEYDEF

enum layers {
  _BASE,
  _VIM,
  _VIM2,
  _VNUM,
  _VISUAL,
  _VCHGE,
  _MOUSE,
  _NAV,
  _SYM,
  _FUNC,
  _NUMS,
};

enum custom_keycodes {
  BS_I = SAFE_RANGE,
  BS_A,
  BS_AC,
  BS_OC,
  BS_O,
  BS_RC,
  BS_COL,
  VI_ESC,
  BS_SLS,
  BS_QUE,
  BS_CC,
  BS_C,
  AU_V,
  AU_D,
  AU_Y,
  CB_DD,
  AU_C,
  OSL_R,
  VIM_GG,
  AT_GG,
  AT_CAPG,
  AT_LEFT,
  AT_UP,
  AT_RGHT,
  AT_DOWN,
  AT_B,
  AT_PERC,
  AT_DLR,
  AT_CIRC,
  AT_E,
  AT_W,
  AT_D,
  AT_Y,
  AT_P,
  AT_ESC,
  BS_GG,
  BS_CAPG,
  BS_LEFT,
  BS_UP,
  BS_RGHT,
  BS_DOWN,
  BS_B,
  BS_PERC,
  BS_DLR,
  BS_CIRC,
  BS_E,
  BS_W,
  W_VIM,
  WQ_VIM,
  Q_VIM,
  ALT_TAB,
  CTL_TAB,
  SELWORD,
  UP_DIR,
  SB_AND,
  SB_NEQL,
  SB_OR,
  SB_GT,
  SB_EQL,
  SB_LT,
  SB_SLEQ,
  SB_PLPL,
  SB_MNMN,
  SB_ASEQ,
  SB_PLEQ,
  SB_MNEQ,
  SB_LRBR,
  SB_RARR,
  SB_DBAS,
  SB_EQ0,
  SB_LRPN,
  SB_PNCB,
  SB_CLCM,
  SB_DBSL,
  SB_OPCM,
};

// Home row mods. BASE layer.
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_N LCTL_T(KC_N)
#define HOME_D LGUI_T(KC_D)
#define HOME_A LGUI_T(KC_A)
#define HOME_E LCTL_T(KC_E)
#define HOME_I LSFT_T(KC_I)
#define HOME_H LALT_T(KC_H)
#define HOME_6 LALT_T(KC_6)
#define HOME_4 LSFT_T(KC_4)
#define HOME_0 LCTL_T(KC_0)
#define HOME_2 LGUI_T(KC_2)
#define HOME_3 LGUI_T(KC_3)
#define HOME_1 LCTL_T(KC_1)
#define HOME_5 LSFT_T(KC_5)
#define HOME_7 LALT_T(KC_7)
#define VIM DF(_VIM)
#define OPN_TAB LCTL(KC_T)
#define CLS_TAB LCTL(KC_F4)
#define CLS_WIN LALT(KC_F4)
#define VIM_RDO LCTL(KC_R)

// Shortcuts.
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define UNDO LCTL(KC_Z)

// Capitalized letters. VIM layout, NUM Layout
#define CAP_O LSFT(KC_O)
#define CAP_A LSFT(KC_A)
#define CAP_R LSFT(KC_R)
#define CAP_G LSFT(KC_G)
#define CAP_U LSFT(KC_U)
#define CAP_N LSFT(KC_N)

// Default layout
#define BASE DF(_BASE)
#define MOUSE DF(_MOUSE)
#define NAV DF(_NAV)

// SYM layer
#define TG_SYM TG(_SYM)
#define TG_NUMS TG(_NUMS)
#define TG_NAV TG(_NAV)
#define TG_MOUS TG(_MOUSE)
#define TG_FUNC TG(_FUNC)
#define TG_VIM2 TG(_VIM2)
#define TG_VNUM TG(_VNUM)

// VIM
#define CTL_G LCTL(KC_G)
#define CTL_O LCTL(KC_O)
#define CTL_I LCTL(KC_I)
#define CTL_W LCTL(KC_W)
#define CTL_RBR LCTL(KC_RBRC)
#endif
