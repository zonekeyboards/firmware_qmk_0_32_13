/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include ZK_KEYBOARD_H

/*********************************************
 ************ 1. LAYER DEFINITIONS ***********
 ********************************************/

/**
 * --- LAYER CONFIGURATION ---
 * Defined using X-Macro technique to keep enum and config array in sync.
 * Format: LAYER(id, name, oled_show, oled_order)
 */
#define LAYER_LIST(LAYER) \
    LAYER(_BASE        ,"BASE"          ,true   ,1) \
    LAYER(_LOWER       ,"LOWER"         ,true   ,2) \
    LAYER(_RAISE       ,"RAISE"         ,true   ,0) \
    LAYER(_ADJUST      ,"ADJ&FN"      ,true   ,3)

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
        KC_TAB    ,     KC_Q     ,     KC_W     ,     KC_E     ,     KC_R     ,     KC_T     ,
/* │     TAB      │      Q       │      W       │      E       │      R       │      T       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
       KC_LCTL    ,     KC_A     ,     KC_S     ,     KC_D     ,     KC_F     ,     KC_G     ,
/* │    CTRL      │      A       │      S       │      D       │      F       │      G       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
    TD(TD_CAPLOCK),     KC_Z     ,     KC_X     ,     KC_C     ,     KC_V     ,     KC_B     ,
/* │  SHIFT/CAPS  │      Z       │      X       │      C       │      V       │      B       │ */
/* └──────────────┴──────────────┴──────────────┴──────────────┼──────────────┼──────────────┤ */
                                                                    KC_LGUI   ,    TL_LOWR   ,    KC_SPC    ,
/*                                                             │     LGUI     │    LOWER     │    Space     │ */ 
/*                                                             └──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                 ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                         KC_Y     ,     KC_U     ,     KC_I     ,     KC_O     ,     KC_P     ,   KC_BSPC    ,
/*                 │      Y       │      U       │      I       │      O       │      P       │     Bspc     │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                         KC_H     ,     KC_J     ,     KC_K     ,     KC_L     ,   KC_SCLN    ,   KC_LBRC    ,
/*                 │      H       │      J       │      K       │      L       │      Ñ       │      ´¨      │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                         KC_N     ,     KC_M     ,   ZK_COMM    ,    ZK_DOT    ,   KC_SLSH    ,    KC_ESC    ,
/*                 │      N       │      M       │      ,;      │     .:       │      -_      │     ESC      │ */    
/*  ┌──────────────┼──────────────┼──────────────┼──────────────┴──────────────┴──────────────┴──────────────┘ */
         KC_ENT    ,    TL_UPPR   ,    KC_RALT   
/*  │    ENTER     │    RAISE     │ RALT / ALTGR │ */ 
/*  └──────────────┴──────────────┴──────────────┘ */  

),

[_LOWER] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 0. QWERTY ***************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/    
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        _______   ,     KC_1     ,     KC_2     ,     KC_3     ,     KC_4     ,     KC_5     ,
/* │     ESC      │      1!      │      2"      │      3#      │      4$      │      5%      │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    ZK_AT     ,   ZK_QUOT    ,    ZK_PLUS   ,   ZK_LCBR    ,   ZK_RCBR    ,
/* │     TAB      │      @       │      '       │      +       │      {       │      }       │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
        _______   ,    ZK_NOT    ,    ZK_DEG    ,   ZK_BSLS    ,   ZK_ASTR    ,   XXXXXXX    ,
/* │  SHIFT/CAPS  │      ¬       │      °       │      \       │      *       │     NONE     │ */
/* └──────────────┴──────────────┴──────────────┴──────────────┼──────────────┼──────────────┼──────────────┐ */
                                                                    _______   ,    _______   ,    _______   ,
/*                                                             │     LGUI     │    LOWER     │     SPACE    │ */ 
/*                                                             └──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                 ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                         KC_6     ,     KC_7     ,     KC_8     ,     KC_9     ,     KC_0     ,   _______    ,
/*                 │      6&      │      7/      │      8(      │      9)      │      0=      │     Bspc     │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_PIPE    ,   ZK_LABK    ,   ZK_RABK    ,   ZK_LBRC    ,   ZK_RBRC    ,   _______    ,
/*                 │      |       │      <       │      >       │      [       │      ]       │      ´¨      │ */    
/*                 ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_IQUE    ,   ZK_QUES    ,   ZK_TILD    ,   ZK_CIRC    ,   ZK_IEXC    ,   _______    ,
/*                 │      ¿       │      ?       │      ~       │      ^       │      ¡       │     ESC      │ */    
/*  ┌──────────────┼──────────────┼──────────────┼──────────────┴──────────────┴──────────────┴──────────────┘ */
         KC_ENT    ,    TL_UPPR   ,    KC_RALT   
/*  │    ENTER     │    RAISE     │ RALT / ALTGR │ */ 
/*  └──────────────┴──────────────┴──────────────┘ */  

),

[_RAISE] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 2. RAISE ****************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        _______   ,    XXXXXXX   ,    XXXXXXX   ,     KC_UP    ,    XXXXXXX   ,    KC_HOME   ,
/* │     ESC      │     NONE     │     NONE     │      UP      │     NONE     │     HOME     │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,    KC_LEFT   ,    KC_DOWN   ,    KC_RGHT   ,    KC_END   ,
/* │     TAB      │     NONE     │     LEFT     │     DOWN     │     RIGHT    │     END      │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,    XXXXXXX   ,
/* │  SHIFT/CAPS  │     NONE     │     NONE     │     NONE     │     NONE     │     NONE     │ */    
/* └──────────────┴──────────────┴──────────────┴──────────────┼──────────────┼──────────────┼──────────────┐ */
                                                                   _______    ,   _______    ,   _______    ,
/*                                                                   LCTR     │    LOWER     │    Enter     │ */ 
/*                                                             └──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                       KC_KP_0   ,   KC_KP_7    ,   KC_KP_8    ,   KC_KP_9    ,   ZK_ASTR    ,   _______    ,
/*                │       0      │      7       │      8       │      9       │      *       │     Bspc     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_COMM   ,   KC_KP_4    ,   KC_KP_5    ,   KC_KP_6    ,  ZK_SLASH    ,   ZK_PLUS    ,
/*                │       ,      │      4       │      5       │      6       │      /       │      +       │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                       ZK_DOT    ,   KC_KP_1    ,   KC_KP_2    ,   KC_KP_3    ,    ZK_EQL    ,   ZK_MINS    ,
/*                │       .      │      1       │      2       │      3       │      =       │      -       │ */    
/* ┌──────────────┼──────────────┼──────────────┼──────────────┴──────────────┴──────────────┴──────────────┘ */
        _______   ,   _______    ,   _______    
/* │    Enter     │    RAISE     │     RCTR     │ */ 
/* └──────────────┴──────────────┴──────────────┘ */     
),

[_ADJUST] = LAYOUT_SPLIT(
/**************************************************************************************************************
************************************************* 3. ADJUST ***************************************************
***************************************************************************************************************/

/************************************************* LEFT SIDE **************************************************/
/* ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
        _______   ,   XXXXXXX    ,   KC_MPRV    ,   KC_MPLY    ,   KC_MNXT    ,   RGB_TOG    ,
/* │              │     NONE     │     PREV     │     PLAY     │     NEXT     │   RGB TOG    │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
        _______   ,    RGB_HUI   ,    RGB_SAI   ,    RGB_VAI   ,    RGB_SPI   ,   RGB_MOD    ,
/* │              │    HUE UP    │    SAT UP    │    VAL UP    │    SPD UP    │    MOD UP    │ */    
/* ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┐ */
        _______   ,    RGB_HUD   ,    RGB_SAD   ,    RGB_VAD   ,    RGB_SPD   ,   XXXXXXX    ,
/* │              │    HUE DN    │    SAT DN    │    VAL DN    │    SPD DN    │     NONE     │ */    
/* └──────────────┴──────────────┴──────────────┴──────────────┼──────────────┼──────────────┼──────────────┐ */
                                                                   _______    ,   _______    ,   _______    ,
/*                                                                   LCTR     │    LOWER     │    Enter     │ */ 
/*                                                             └──────────────┴──────────────┴──────────────┘ */   

/************************************************* RIGHT SIDE *************************************************/
/*                ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐ */
                      KC_PSCR    ,    KC_F1     ,    KC_F2     ,    KC_F3     ,    KC_F4     ,   QK_BOOT    ,
/*                │ PRINT SCREEN │      F1      │      F2      │      F3      │      F4      │    RESET     │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                      XXXXXXX    ,    KC_F5     ,    KC_F6     ,    KC_F7     ,    KC_F8     ,   ZK_DESKL   ,
/*                │     NONE     │      F5      │      F6      │      F7      │      F8      │  DESK LEFT   │ */    
/*                ├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤ */
                      XXXXXXX    ,    KC_F9     ,    KC_F10    ,    KC_F11    ,    KC_F12    ,   ZK_DESKR   ,
/*                      NONE     │      F9      │      F10     │      F11     │      F12     │  DESK RIGHT  │ */    
/* ┌──────────────┼──────────────┼──────────────┼──────────────┴──────────────┴──────────────┴──────────────┘ */
        _______   ,   _______    ,   _______    
/* │              │              │              │ */ 
/* └──────────────┴──────────────┴──────────────┘ */   
),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif


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
