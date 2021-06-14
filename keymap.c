#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
    PND_SYM = SAFE_RANGE
};

enum tap_dance_codes {
    TD_INS_COLMOD,
    TD_F1,
    TD_F2,
    TD_F3,
    TD_F4,
    TD_F5,
    TD_F6,
    TD_F7,
    TD_F8,
    TD_F9,
    TD_F10,
    TD_F11,
    TD_F12
};

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_split_3x6_3(
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TAB   , KC_SCLN , KC_COMM , KC_DOT  , KC_P    , KC_Y   ,     KC_F     , KC_G    , KC_C    , KC_R    , KC_L    , KC_ESC,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
        KC_BSPC  , KC_A    , KC_O    , KC_E    , KC_U    , KC_I   ,     KC_D     , KC_H    , KC_T    , KC_N    , KC_S    , KC_ENT,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_LSFT  , KC_QUOT , KC_Q    , KC_J    , KC_K    , KC_X   ,     KC_B     , KC_M    , KC_W    , KC_V    , KC_Z    , KC_LGUI,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		                               KC_LALT , LOWER   , KC_SPC ,     KC_SPC   , RAISE   , KC_LCTL
                                    //---------|---------|-------\\     //-------|---------|----------
	),
	
	[_LOWER] = LAYOUT_split_3x6_3(
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TRNS  , PND_SYM , KC_LBRC , KC_RBRC , KC_BSLS , KC_NO  ,     KC_NO    , KC_SLSH , KC_7    , KC_8    , KC_9    , KC_0,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------		
		KC_TRNS  , KC_UNDS , KC_LPRN , KC_RPRN , KC_EQL  , KC_TILD,     KC_GRV   , KC_PLUS , KC_4    , KC_5    , KC_6    , KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TRNS  , KC_PIPE , KC_LCBR , KC_RCBR , KC_QUES , KC_NO  ,     KC_NO    , KC_MINS , KC_1    , KC_2    , KC_3    , KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		                               KC_TRNS , KC_TRNS , KC_TRNS,     KC_TRNS  , KC_TRNS , KC_TRNS
                                    //---------|---------|-------\\     //-------|---------|----------
	),
	
	[_RAISE] = LAYOUT_split_3x6_3(
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
	    KC_TRNS  , KC_APP  , KC_HOME , KC_UP   , KC_END  , KC_PGUP,     LCTL(KC_F),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_L),KC_ESC,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TRNS ,LCTL(KC_A), KC_LEFT , KC_DOWN , KC_RGHT , KC_PGDN,     LCTL(KC_D), KC_LSFT, KC_LCTL , KC_LALT,TD(TD_INS_COLMOD), KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TRNS ,LCTL(KC_G),LCTL(KC_Q),LALT(KC_J),LCTL(KC_K),KC_NO,     LCTL(KC_B),KC_DEL, LCTL(KC_W),LCTL(LSFT(KC_Z)), LCTL(KC_Z), KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		                               KC_TRNS , KC_TRNS , KC_TRNS,     KC_TRNS  , KC_TRNS , KC_TRNS
                                    //---------|---------|-------\\     //-------|---------|----------
	),
	
	[_ADJUST] = LAYOUT_split_3x6_3(
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		KC_TRNS  , KC_NO   , KC_NO   , KC_MS_U , KC_NO   , KC_NO,       KC_NO    , KC_WH_U , KC_BTN2 , KC_ACL0 , KC_NO   , KC_TRNS, 
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------		
		KC_TRNS  , KC_NO   , KC_MS_L , KC_MS_D , KC_MS_R , TD(TD_F11),  TD(TD_F12), KC_WH_D, KC_BTN1 , KC_ACL2 , KC_NO   , KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------		
		KC_TRNS ,TD(TD_F1),TD(TD_F2),TD(TD_F3),TD(TD_F4),TD(TD_F5),     TD(TD_F6),TD(TD_F7),TD(TD_F8),TD(TD_F9),TD(TD_F10),KC_TRNS,
        //-------|---------|---------|---------|---------|-------\\     //-------|---------|---------|---------|---------|-------
		                               KC_TRNS , KC_TRNS , KC_TRNS,     KC_TRNS  , KC_TRNS , KC_TRNS
                                    //---------|---------|-------\\     //-------|---------|----------
	)
};

// Tri Layers :id=olkb-tri-layers
// see: https://beta.docs.qmk.fm/developing-qmk/qmk-reference/ref_functions#update_tri_layer_state-state-x-y-z
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// START of Micro definitions     ------------------------------------------------------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PND_SYM: if (record->event.pressed) SEND_STRING("£"); break;
    }
    return true;
}

// START of Tap Dance definitions ------------------------------------------------------

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[13];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } 
    else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    else return MORE_TAPS;
}

// F1
void on_dance_f1(qk_tap_dance_state_t *state, void *user_data);
void dance_f1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f1_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}
void dance_f1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F1)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F1)); break;
        case DOUBLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}
void dance_f1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F1)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F1)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[1].step = 0;
}

// F2
void on_dance_f2(qk_tap_dance_state_t *state, void *user_data);
void dance_f2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f2_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}
void dance_f2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F2)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F2)); break;
        case DOUBLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}
void dance_f2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F2)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F2)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[2].step = 0;
}

// F3
void on_dance_f3(qk_tap_dance_state_t *state, void *user_data);
void dance_f3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f3_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}
void dance_f3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F3)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F3)); break;
        case DOUBLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}
void dance_f3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F3)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F3)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[3].step = 0;
}

// F4
void on_dance_f4(qk_tap_dance_state_t *state, void *user_data);
void dance_f4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f4_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}
void dance_f4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F4)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F4)); break;
        case DOUBLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}
void dance_f4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F4)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[4].step = 0;
}

// F5
void on_dance_f5(qk_tap_dance_state_t *state, void *user_data);
void dance_f5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f5_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}
void dance_f5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F5)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F5)); break;
        case DOUBLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}
void dance_f5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F5)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F5)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[5].step = 0;
}

// F6
void on_dance_f6(qk_tap_dance_state_t *state, void *user_data);
void dance_f6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f6_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}
void dance_f6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F6)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F6)); break;
        case DOUBLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}
void dance_f6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F6)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F6)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[6].step = 0;
}

// F7
void on_dance_f7(qk_tap_dance_state_t *state, void *user_data);
void dance_f7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f7_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}
void dance_f7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F7)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F7)); break;
        case DOUBLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}
void dance_f7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F7)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F7)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[7].step = 0;
}

// F8
void on_dance_f8(qk_tap_dance_state_t *state, void *user_data);
void dance_f8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f8_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}
void dance_f8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F8)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F8)); break;
        case DOUBLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}
void dance_f8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F8)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F8)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[8].step = 0;
}

// F9
void on_dance_f9(qk_tap_dance_state_t *state, void *user_data);
void dance_f9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f9_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}
void dance_f9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F9)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F9)); break;
        case DOUBLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}
void dance_f9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F9)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F9)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[9].step = 0;
}

// F10
void on_dance_f10(qk_tap_dance_state_t *state, void *user_data);
void dance_f10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f10_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}
void dance_f10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F10)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F10)); break;
        case DOUBLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}
void dance_f10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F10)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F10)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[10].step = 0;
}

// F11
void on_dance_f11(qk_tap_dance_state_t *state, void *user_data);
void dance_f11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f11_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F11);
        tap_code16(KC_F11);
        tap_code16(KC_F11);
    }
    if(state->count > 3) {
        tap_code16(KC_F11);
    }
}
void dance_f11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_F11); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F11)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F11)); break;
        case DOUBLE_HOLD: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F11); register_code16(KC_F11);
    }
}
void dance_f11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_F11); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F11)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F11)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F11); break;
    }
    dance_state[11].step = 0;
}

// F12
void on_dance_f12(qk_tap_dance_state_t *state, void *user_data);
void dance_f12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f12_reset(qk_tap_dance_state_t *state, void *user_data);
void on_dance_f12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F12);
        tap_code16(KC_F12);
        tap_code16(KC_F12);
    }
    if(state->count > 3) {
        tap_code16(KC_F12);
    }
}
void dance_f12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_F12); break;
        case SINGLE_HOLD: register_code16(LALT(KC_F12)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_F12)); break;
        case DOUBLE_HOLD: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F12); register_code16(KC_F12);
    }
}
void dance_f12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_F12); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_F12)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_F12)); break;
        case DOUBLE_HOLD: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F12); break;
    }
    dance_state[12].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_INS_COLMOD] = ACTION_TAP_DANCE_DOUBLE(KC_INS, LALT(LSFT(KC_INS))),
    [TD_F1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f1, dance_f1_finished, dance_f1_reset),
    [TD_F2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f2, dance_f2_finished, dance_f2_reset),
    [TD_F3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f3, dance_f3_finished, dance_f3_reset),
    [TD_F4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f4, dance_f4_finished, dance_f4_reset),
    [TD_F5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f5, dance_f5_finished, dance_f5_reset),
    [TD_F6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f6, dance_f6_finished, dance_f6_reset),
    [TD_F7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f7, dance_f7_finished, dance_f7_reset),
    [TD_F8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f8, dance_f8_finished, dance_f8_reset),
    [TD_F9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f9, dance_f9_finished, dance_f9_reset),
    [TD_F10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f10, dance_f10_finished, dance_f10_reset),
    [TD_F11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f11, dance_f11_finished, dance_f11_reset),
    [TD_F12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f12, dance_f12_finished, dance_f12_reset)
};

// END of Tap Dance definitions ------------------------------------------------------