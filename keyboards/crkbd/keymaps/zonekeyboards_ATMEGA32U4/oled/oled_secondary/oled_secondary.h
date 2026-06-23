#pragma once
#include "quantum.h"

/**
 * @brief Main entry point to render the secondary OLED content.
 */
void render_oled_secondary_display(uint8_t* buffer, uint16_t size);

/**
 * @brief Rebuilds the UI cache for the secondary display.
 */
