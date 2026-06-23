#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>
#include QMK_KEYBOARD_H

extern void render_oled_primary(void);
extern void render_oled_secondary(void);
extern void update_layers_info_cache_oled(layer_state_t state);
