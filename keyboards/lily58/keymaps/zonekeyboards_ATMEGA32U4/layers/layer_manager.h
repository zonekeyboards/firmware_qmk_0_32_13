#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"

typedef struct {
    uint8_t id;
    const char* name;
    bool oled_show;
    uint8_t oled_order;
} layer_config_t;

extern void layer_manager_init(const void* config_array, uint8_t count);
extern const layer_config_t* get_active_layer_config(layer_state_t state);
extern const layer_config_t* get_layers_configs(void);
extern const uint8_t get_layers_count(void);
extern const layer_config_t** get_layers_configs_visible_and_sorted(void);
extern const uint8_t get_layers_configs_visible_and_sorted_count(void);

void update_visible_and_sorted_layers_cache(void);