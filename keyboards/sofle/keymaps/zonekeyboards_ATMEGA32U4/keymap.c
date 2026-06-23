// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include ZK_KEYBOARD_H

#include <stdio.h>

/*********************************************
 ************ 1. LAYER DEFINITIONS ***********
 ********************************************/

/**
 * --- LAYER CONFIGURATION ---
 * Defined using X-Macro technique to keep enum and config array in sync.
 * Format: LAYER(id, name, oled_show, oled_order)
 */
#define LAYER_LIST(LAYER) \
    LAYER(_BASE        ,"BASE"     ,true   ,1) \
    LAYER(_LOWER       ,"LOWER"    ,true   ,2) \
    LAYER(_RAISE       ,"RAISE"    ,true   ,0) \
    LAYER(_ADJUST      ,"ADJUST"   ,true   ,3)

/* Generate layer enum automatically */
enum keyboard_layers {
    LAYER_LIST(ACTION_LAYER_NAME)
};

/* Create the layer configuration array */
const layer_config_t my_layer_configs[] = {
    LAYER_LIST(ACTION_STRUCT)
};

#define LAYERS_COUNT (sizeof(my_layer_configs) / sizeof(my_layer_configs[0]))

/*********************************************
 ********* 2. CUSTOM KEYCODES & MACROS ********
 ********************************************/

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_CUSTOM
};

/* Tap Dance Definitions */
enum {
    TD_CAPLOCK,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

/*********************************************
 ******* 3. KEYMAP LAYER DEFINITIONS ********
 ********************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 0. QWERTY ***************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
       KC_PSCR    ,     KC_1     ,     KC_2     ,     KC_3     ,     KC_4     ,     KC_5     ,
/* │ PRINT SCREEN │      1       │      2       │      3       │      4       │      5       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        KC_ESC    ,     KC_Q     ,     KC_W     ,     KC_E     ,     KC_R     ,     KC_T     ,
/* │     ESC      │      Q       │      W       │      E       │      R       │      T       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        KC_TAB    ,     KC_A     ,     KC_S     ,     KC_D     ,     KC_F     ,     KC_G     ,
/* │     TAB      │      A       │      S       │      D       │      F       │      G       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
    TD(TD_CAPLOCK),     KC_Z     ,     KC_X     ,     KC_C     ,     KC_V     ,     KC_B     ,   KC_MUTE    ,
/* │     LCTRL    │      Z       │      X       │      C       │      V       │      B       │    (MUTE)    │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                                      KC_LGUI   ,   KC_LALT    ,    KC_LCTL   ,    TL_LOWR   ,    KC_ENT    ,
/*                               │     LGUI     │     LAlt     │     LCTR     │    LOWER     │    Enter     │ */ 
/*                               └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                 ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                         KC_6     ,     KC_7     ,     KC_8     ,     KC_9     ,     KC_0     ,    KC_DEL    ,
/*                 │      6       │      7       │      8       │      9       │      0       │     DEL      │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                         KC_Y     ,     KC_U     ,     KC_I     ,     KC_O     ,     KC_P     ,   KC_BSPC    ,
/*                 │      Y       │      U       │      I       │      O       │      P       │     Bspc     │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                         KC_H     ,     KC_J     ,     KC_K     ,     KC_L     ,   KC_SCLN    ,   KC_LBRC    ,
/*                 │      H       │      J       │      K       │      L       │      Ñ       │      ´¨      │ */    
/*  ┌──────────────├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        KC_CUSTOM  ,     KC_N     ,     KC_M     ,   ZK_COMM    ,    ZK_DOT    ,   KC_SLSH    ,   KC_RSFT    ,
/*  │    CUSTOM    │      N       │      M       │      ,;      │     .:       │      -_      │    RShift    │ */    
/*  └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
         KC_SPC    ,    TL_UPPR   ,    KC_RCTL   ,    KC_RALT   ,    KC_RGUI   
/*  │    SPACE     │    RAISE     │     RCTR     │     RAlt     │     RGUI     │ */ 
/*  └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   
),

[_LOWER] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 1. LOWER ****************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        KC_F1     ,    KC_F2     ,    KC_F3     ,    KC_F4     ,    KC_F5     ,    KC_F6     ,
/* │      F1      │      F2      │      F3      │      F4      │      F5      │      F6      │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,   ZK_EXLM    ,    ZK_DQUO   ,   ZK_HASH    ,    ZK_DLR    ,   ZK_PERC    ,
/* │     ESC      │      !       │      "       │      #       │      $       │      %       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    ZK_AT     ,    ZK_QUOT   ,    ZK_PLUS   ,   ZK_LCBR    ,   ZK_RCBR    ,
/* │     TAB      │      @       │      '       │      +       │      {       │      }       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
        _______   ,    ZK_NOT    ,    ZK_DEG    ,    ZK_BSLS   ,   ZK_ASTR    ,   XXXXXXX    ,   _______    ,
/* │     LCTRL    │      ¬       │       °      │       \      │      *       │     NONE     │              │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                                      _______   ,   _______    ,   _______    ,   _______    ,   _______    ,
/*                               │     LGUI     │     LAlt     │     LCTR     │    LOWER     │    Enter     │ */ 
/*                               └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                        KC_F7    ,     KC_F8    ,     KC_F9    ,    KC_F10    ,    KC_F11    ,    KC_F12    ,
/*                │      F7      │      F8      │      F9      │     F10      │      F11     │      F12     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_AMPR   ,   ZK_SLASH   ,   ZK_LPRN    ,   ZK_RPRN    ,    ZK_EQL    ,   _______    ,
/*                │      &       │       /      │      (       │      )       │      =       │     Bspc     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_PIPE   ,   ZK_LABK    ,   ZK_RABK    ,   ZK_LBRC    ,   ZK_RBRC    ,   XXXXXXX    ,
/*                │      |       │       <      │       >      │      [       │      ]       │     NONE     │ */    
/* ┌──────────────├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    ZK_IQUE   ,   ZK_QUES    ,   ZK_TILD    ,   ZK_CIRC    ,   ZK_IEXC    ,   _______    ,
/*                │       ¿      │       ?      │       ~      │       ^      │      ¡       │   RShift     │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    _______   ,    _______   ,    _______   ,    _______   
/* │    Enter     │    RAISE     │     RCTR     │     RAlt     │     RGUI     │ */ 
/* └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   
),

[_RAISE] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 2. RAISE ****************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        _______   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,
/* │              │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,    XXXXXXX   ,     KC_UP    ,    XXXXXXX   ,    KC_HOME   ,
/* │     ESC      │     NONE     │     NONE     │      UP      │     NONE     │     HOME     │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,    KC_LEFT   ,    KC_DOWN   ,    KC_RGHT   ,    KC_END   ,
/* │     TAB      │     NONE     │     LEFT     │     DOWN     │     RIGHT    │     END      │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
        _______   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,   _______    ,
/* │     LCTRL    │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │              │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                                      _______   ,   _______    ,   _______    ,   _______    ,   _______    ,
/*                               │     LGUI     │     LAlt     │     LCTR     │    LOWER     │    Enter     │ */ 
/*                               └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                       XXXXXXX   ,   KC_KP_7    ,   KC_KP_8    ,   KC_KP_9    ,   ZK_PERC    ,   _______    ,
/*                │     NONE     │      7       │      8       │      9       │      %       │     DEL      │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       XXXXXXX   ,   KC_KP_4    ,   KC_KP_5    ,   KC_KP_6    ,   ZK_ASTR    ,   _______    ,
/*                │     NONE     │      4       │      5       │      6       │      *       │     Bspc     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       XXXXXXX   ,   KC_KP_1    ,   KC_KP_2    ,   KC_KP_3    ,   ZK_SLASH   ,   ZK_PLUS    ,
/*                │     NONE     │      1       │      2       │      3       │      /       │      +       │ */    
/* ┌──────────────├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,   KC_KP_0    ,   ZK_COMM    ,   ZK_DOT     ,    ZK_EQL    ,   ZK_MINS    ,
/* │              │     NONE     │      0       │      ,       │      .       │      =       │      -       │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,   _______    ,   _______    ,   _______    ,   _______    
/* │    Enter     │    RAISE     │     RCTR     │     RAlt     │     RGUI     │ */ 
/* └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */     
),

[_ADJUST] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 3. ADJUST ***************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        _______   ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,
/* │              │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   RGB_TOG    ,
/* │              │     NONE     │     NONE     │     NONE     │     NONE     │   RGB TOG    │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    RGB_HUI   ,    RGB_SAI   ,    RGB_VAI   ,    RGB_SPI   ,   RGB_MOD    ,
/* │              │    HUE UP    │    SAT UP    │    VAL UP    │    SPD UP    │    MOD UP    │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
        _______   ,    RGB_HUD   ,    RGB_SAD   ,    RGB_VAD   ,    RGB_SPD   ,   XXXXXXX    ,   _______    ,
/* │              │    HUE DN    │    SAT DN    │    VAL DN    │    SPD DN    │     NONE     │              │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                                      _______   ,   _______    ,   _______    ,   _______    ,   _______    ,
/*                               │     LGUI     │     LAlt     │     LCTR     │    LOWER     │    Enter     │ */ 
/*                               └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                       XXXXXXX   ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,
/*                │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       XXXXXXX   ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,   XXXXXXX    ,
/*                │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       XXXXXXX   ,   ZK_DESKL   ,    KC_NO     ,   ZK_DESKR   ,   XXXXXXX    ,   QK_BOOT    ,
/*                │     NONE     │  DESK LEFT   │     NONE     │  DESK RIGHT  │     NONE     │    RESET     │ */    
/* ┌──────────────├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,   KC_MPRV    ,   KC_MPLY    ,   KC_MNXT    ,   XXXXXXX    ,   XXXXXXX    ,
/* │              │     NONE     │     PREV     │     PLAY     │     NEXT     │     NONE     │     NONE     │ */    
/* └──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,   _______    ,   _______    ,   _______    ,   _______    
/* │              │              │              │              │              │ */ 
/* └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘ */   
),
};

/*********************************************
 ************ 4. USER CALLBACKS **************
 ********************************************/

 bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Encoder Left
        if (clockwise) {
            tap_code(KC_VOLD); // Turn left : volume down
        } else {
            tap_code(KC_VOLU); // Turn Right: volume up
        }
    } else if (index == 1) { // Encoder Right
        if (clockwise) {
            tap_code(KC_PGDN); // Turn Right: Page down
        } else {
            tap_code(KC_PGUP); // Turn Right: Page up
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    #ifdef OLED_ENABLE
        layer_manager_init(my_layer_configs, LAYERS_COUNT);
        update_layers_info_cache_oled(layer_state);
    #endif
}



#ifdef OLED_ENABLE
/**
 * @brief Initialize OLED display orientation.
 */
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/**
 * @brief Main OLED task to render content based on master/slave status.
 */
bool oled_task_user(void) {
    // 1. refesh cache in change layer state
    update_layers_info_cache_oled(layer_state);

    // 2. render oled direction left or right
    if (is_keyboard_left()) {
        render_oled_primary();
    }
    else {
        render_oled_secondary();
    }
    return false;
}
#endif

