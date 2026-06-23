#include <avr/pgmspace.h>
#include "oled_manager.h"
#include "oled_primary/oled_primary.h"
#include "oled_secondary/oled_secondary.h"
#include <string.h>

/**
 * --- OLED BUFFER CONFIGURATION ---
 */
#define OLED_WIDTH          32
#define PRIMARY_UI_PAGES    10
#define PRIMARY_UI_SIZE     (OLED_WIDTH * PRIMARY_UI_PAGES)

/* Atomic shared buffer (Only used by Primary Display / Master side) */
static uint8_t oled_shared_buffer[PRIMARY_UI_SIZE]; 
static layer_state_t last_rendered_layer = (layer_state_t)-1;

void render_oled_primary(void) {
    render_oled_primary_display(oled_shared_buffer, PRIMARY_UI_SIZE);
}

void render_oled_secondary(void) {
    render_oled_secondary_display(NULL, 0);
}

void update_layers_info_cache_oled(layer_state_t state) {
    
     if (state != last_rendered_layer) {
        update_oled_primary_cache(state, oled_shared_buffer, PRIMARY_UI_SIZE);
        last_rendered_layer = state;
    }
}
