#pragma once
#include "quantum.h"

/**
 * @brief Main entry point to render the primary OLED content.
 */
void render_oled_primary_display(uint8_t* buffer, uint16_t size);

/**
 * @brief Rebuilds the UI cache for the primary display.
 */
void update_oled_primary_cache(layer_state_t state, uint8_t* buffer, uint16_t size);
