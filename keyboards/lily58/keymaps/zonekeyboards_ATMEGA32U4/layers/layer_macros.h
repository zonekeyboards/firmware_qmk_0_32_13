// 1. Generate the layer enum and configuration using X-Macro technique
#define ACTION_LAYER_NAME(id, name, oled_show, oled_order) id,

// 2. Generate the layer configuration array using the same X-Macro
#define ACTION_STRUCT(id, name, oled_show, oled_order) {id, name, oled_show, oled_order},