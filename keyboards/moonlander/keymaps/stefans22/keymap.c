/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

enum layers {
    BASE,  // default layer
    SHFT,  // fake shift layer
    FUN,   // function layer
    UPER,  // upper layer
    NUM,   // mouse and numpad layer
    GAME,  // gaming layer
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    RGB_RST,
    MY_00,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TO(GAME),        TG(NUM), DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
        DE_LBRC, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    KC_NO,           KC_NO,   DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_HOME,
        DE_RBRC, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_GRV,          DE_BSLS, DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN, KC_PGUP,
        KC_NO,   DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                              DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_SLSH, KC_PGDN,
        KC_NO,   KC_ESC,  KC_TAB,  KC_LGUI, MO(SHFT),         KC_ESC,          KC_ENT,           MO(FUN), DE_MINS, DE_QUOT, KC_ENT,  KC_END,
                                            KC_BSPC, KC_LCTL, KC_DEL,          KC_RGUI, KC_LALT, KC_SPC
    ),

    [SHFT] = LAYOUT_moonlander(
        DE_DEG    ,DE_EXLM   ,DE_DQUO   ,DE_SECT   ,DE_DLR    ,DE_PERC   ,_______   ,            _______   ,DE_AMPR   ,DE_SLSH   ,DE_LPRN   ,DE_RPRN   ,DE_EQL    ,DE_QUES   ,
	DE_LCBR   ,S(DE_Q)   ,S(DE_W)   ,S(DE_E)   ,S(DE_R)   ,S(DE_T)   ,_______   ,            _______   ,S(DE_Z)   ,S(DE_U)   ,S(DE_I)   ,S(DE_O)   ,S(DE_P)   ,_______   ,
	DE_RCBR   ,S(DE_A)   ,S(DE_S)   ,S(DE_D)   ,S(DE_F)   ,S(DE_G)   ,DE_TILD   ,            DE_PIPE   ,S(DE_H)   ,S(DE_J)   ,S(DE_K)   ,S(DE_L)   ,DE_COLN   ,_______   ,
	_______   ,S(DE_Y)   ,S(DE_X)   ,S(DE_C)   ,S(DE_V)   ,S(DE_B)   ,                                  S(DE_N)   ,S(DE_M)   ,DE_LABK   ,DE_RABK   ,DE_QUES   ,_______   ,
	_______   ,S(KC_ESC) ,S(KC_TAB) ,S(KC_LGUI),_______   ,           S(KC_ESC) ,            S(KC_ENT) ,           _______   ,DE_UNDS   ,DE_DQUO   ,S(KC_ENT) ,_______   ,
	                                            KC_DEL    ,S(KC_LCTL),KC_BSPC   ,            S(KC_RGUI),S(KC_LALT),S(KC_SPC)
    ),
    
    [FUN] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, DE_EXLM, DE_AT,   KC_UP,   DE_DLR,  DE_PERC, _______,         _______, KC_PGUP, DE_7,    DE_8,    DE_9,    KC_BSPC, KC_F12,
        _______, DE_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, DE_RPRN, DE_CIRC,         DE_AMPR, KC_PGDN, DE_4,    DE_5,    DE_6,    DE_EURO, KC_F13,
        _______, DE_LBRC, DE_RBRC, DE_HASH, DE_LCBR, DE_RCBR,                           DE_ASTR, DE_1,    DE_2,    DE_3,    DE_PLUS, KC_F14,
        _______, TG(UPER),KC_INS,  _______, KC_LSFT,          _______,         _______,          _______, _______, DE_0,    DE_EQL,  KC_F15,
	                                    _______, _______, _______,         _______, _______, _______

    ),

    [UPER] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,    
	_______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,         _______, KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,    
	_______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO,           KC_NO,   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,    
	_______, KC_NO,   KC_VOLU, KC_NO,   KC_NO,   KC_NO,                             KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,    
	_______, TG(UPER),KC_VOLD, _______, _______,          _______,         _______,          _______, KC_PSCR, KC_SLCK, KC_MPLY, _______,    
                                            _______, _______, _______,         _______, _______, _______
		    
    ),

    [NUM] = LAYOUT_moonlander(
        RGB_TOG, _______, _______, _______, _______, _______, _______,         _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, TOGGLE_LAYER_COLOR,
        RGB_VAI, KC_ACL2, KC_NO,   KC_MS_U, KC_NO,   KC_WH_U, _______,        LED_LEVEL,_______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, RGB_HUD,
        RGB_VAD, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,         _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, RGB_SAI,
        RGB_SPI, KC_ACL0, KC_NO,   KC_WH_L, KC_WH_R, KC_NO,                             _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, RGB_SAD,
        RGB_SPD, KC_NO,   KC_NO,   KC_BTN3, KC_BTN1,          RGB_MOD,         RGB_RST,          KC_P0,   MY_00,   KC_PCMM, KC_PENT, RGB_HUI,
                                            KC_BTN2, _______, _______,         _______, _______, _______
    ),

    [GAME] = LAYOUT_moonlander(
	_______, _______, _______, _______, _______, _______, TO(BASE),        _______, _______, _______, _______, _______, _______, _______,    
	KC_TAB,  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, DE_UDIA,    
	KC_CAPS, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, DE_ODIA, DE_ADIA,    
	KC_LSFT, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, DE_MINS, KC_RSFT,    
	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,           _______,         _______,          KC_SPC,  KC_RALT, KC_RGUI, KC_APP,  KC_RCTL,    
                                            KC_SPC,  KC_BSPC, _______,         _______, KC_ENT,  KC_SPC
	
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
	case RGB_RST:
            rgblight_mode(1);
	    return false;
	case MY_00:
	    SEND_STRING ("00");
	    return false;
        }
    }
    return true;
}
