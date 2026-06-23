#include "layer_manager.h"
#include <string.h>
#include <progmem.h>

/**
 * --- LAYER MANAGER ---
 * Static implementation to avoid malloc() and save RAM.
 */

#define MAX_VISIBLE_LAYERS 8

static const layer_config_t* internal_configs = NULL;
static uint8_t internal_count = 0;

// Static array of pointers to avoid dynamic memory allocation
static const layer_config_t* internal_visible_sorted_configs[MAX_VISIBLE_LAYERS];
static uint8_t internal_visible_sorted_count = 0;

void layer_manager_init(const void* config_array, uint8_t count) {
    internal_configs = (const layer_config_t*)config_array;
    internal_count = count;
    update_visible_and_sorted_layers_cache();
}

void update_visible_and_sorted_layers_cache(void) {
    const layer_config_t* all_layers = get_layers_configs();
    uint8_t total_layers = get_layers_count();

    internal_visible_sorted_count = 0;
    
    // Fill and sort (Insertion Sort) directly into the static array
    for (uint8_t i = 0; i < total_layers; i++) {
        if (all_layers[i].oled_show && internal_visible_sorted_count < MAX_VISIBLE_LAYERS) {
            uint8_t j = internal_visible_sorted_count;
            
            while (j > 0 && internal_visible_sorted_configs[j - 1]->oled_order > all_layers[i].oled_order) {
                internal_visible_sorted_configs[j] = internal_visible_sorted_configs[j - 1];
                j--;
            }
            
            internal_visible_sorted_configs[j] = &all_layers[i];
            internal_visible_sorted_count++;
        }
    }
}

const layer_config_t* get_layers_configs(void) {
    return internal_configs;
}

const uint8_t get_layers_count(void) {
    return internal_count;
}

const layer_config_t** get_layers_configs_visible_and_sorted(void) {
    return (const layer_config_t**)internal_visible_sorted_configs;
}

const uint8_t get_layers_configs_visible_and_sorted_count(void) {
    return internal_visible_sorted_count;
}

const layer_config_t* get_active_layer_config(layer_state_t state) {
    if (!internal_configs) return NULL;
    uint8_t layer = get_highest_layer(state);
    for (uint8_t i = 0; i < internal_count; i++) {
        if (internal_configs[i].id == layer) {
            return &internal_configs[i];
        }
    }
    return NULL;
}
