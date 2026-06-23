// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


/************************************
 ******* LAYERS CONFIGURATION *******
*************************************/
#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 3


/************************************
 ****** GENERAL CONFIGURATIONS ******
*************************************/
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define EE_HANDS
#define SPLIT_ACTIVITY_ENABLE

/************************************
 **** RGB MATRIS CONFIGURATIONS *****
*************************************/
#ifdef RGB_MATRIX_ENABLE
    // GENERAL
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_DEFAULT_BRIGHTNESS 100
    #define RGB_MATRIX_LED_PROCESS_LIMIT 5
    #define RGB_MATRIX_LED_FLUSH_LIMIT 5

    // EFFECTS
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#endif

/************************************
 ******** VIA CONFIGURATIONS ********
*************************************/
#ifdef VIA_ENABLE
    #define DYNAMIC_KEYMAP_LAYER_COUNT 6
#endif

/************************************
 ******* OLED CONFIGURATIONS ********
*************************************/
#define OLED_DISPLAY_128X32
#define OLED_UPDATE_PROCESS_LIMIT 16
#define OLED_UPDATE_INTERVAL 33

