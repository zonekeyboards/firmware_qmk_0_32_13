#include "oled_primary.h"
#include "quantum.h"
#include "../../layers/layer_manager.h"
#include "../../images/logo/img_logo.h"
#include "../../images/side_indicator/img_side_indicator.h"
#include "../../images/indicator/img_indicators.h"
#include "../../fonts/glcdfont.h"
#include <string.h>

/* 
 * --- OLED LAYOUT MAP (32x128 Rotated) ---
 * Pages 0-2:   Logo (96 bytes)
 * Pages 3-12:  UI Buffer (320 bytes)
 * Pages 13-14: Handedness Indicator (64 bytes)
 * Page 15:     Empty/Clear (32 bytes)
 */

#define OLED_WIDTH          32
#define OLED_PAGE_HEIGHT    8
#define LOGO_PAGE_END       3
#define MAX_UI_PAGES        10      /* Match PRIMARY_UI_PAGES in oled_manager.c */
#define CANVAS_HEIGHT_PX    (MAX_UI_PAGES * OLED_PAGE_HEIGHT)
#define LETTER_SPACING      10

#define TEXT_X_OFFSET       2
#define IND_X_OFFSET        16
#define INDICATOR_HEIGHT    8
#define FONT_WIDTH          5
#define FONT_BLOCK_SIZE     6
#define ASCII_SPACE         32
#define CASE_CONV_OFFSET    32

#define USABLE_HEIGHT_PX    CANVAS_HEIGHT_PX 

static void draw_bitmap_to_buffer(uint8_t* buffer, const uint8_t* bmp, uint8_t x, uint8_t y_px, uint8_t w, bool pgm);
static const uint8_t* get_indicator_bmp(uint8_t i, uint8_t count, int8_t active_idx);
static void render_direction_hanedness(void);

static void draw_bitmap_to_buffer(uint8_t* buffer, const uint8_t* bmp, uint8_t x, uint8_t y_px, uint8_t w, bool pgm) {
    if (y_px > (CANVAS_HEIGHT_PX - OLED_PAGE_HEIGHT)) return;

    uint8_t page = y_px / OLED_PAGE_HEIGHT;
    uint8_t shift = y_px % OLED_PAGE_HEIGHT;
    uint16_t base_idx = (uint16_t)page * OLED_WIDTH + x;

    for (uint8_t col = 0; col < w; col++) {
        uint8_t bits = pgm ? pgm_read_byte(bmp + col) : bmp[col];
        buffer[base_idx + col] |= (bits << shift);
        if (shift > 0 && (page + 1) < MAX_UI_PAGES) {
            buffer[base_idx + OLED_WIDTH + col] |= (bits >> (OLED_PAGE_HEIGHT - shift));
        }
    }
}

static const uint8_t* get_indicator_bmp(uint8_t i, uint8_t count, int8_t active_idx) {
    if (i == 0) return (active_idx == 0) ? top_fill_bmp : top_empty_bmp;
    if (i == count) return (active_idx == count - 1) ? bottom_fill_bmp : bottom_empty_bmp;
    if (active_idx == i - 1) return direction_bottom_fill_bmp;
    if (active_idx == i) return direction_top_fill_bmp;
    return (active_idx != -1 && active_idx < i) ? direction_bottom_empty_bmp : direction_top_empty_bmp;
}

static void render_direction_hanedness(void) {
    #ifdef OLED_ENABLE
        const uint8_t* side_bmp = is_keyboard_left() ? side_left_bmp : side_right_bmp;
        const uint16_t side_bmp_size = is_keyboard_left() ? side_left_bmp_size : side_right_bmp_size;

        // Position fixed at Page 13 (After the UI buffer)
        oled_set_cursor(0, 13);
        oled_write_raw_P((const char*)side_bmp, side_bmp_size);
    #endif
}

void render_oled_primary_display(uint8_t* buffer, uint16_t size) {
    #ifdef OLED_ENABLE
        // 1. Render Logo (Pages 0-2)
        oled_set_cursor(0, 0);
        oled_write_raw_P((const char *)zone_logo, zone_logo_size);

        // 2. Render UI Buffer (Pages 3-12)
        oled_set_cursor(0, LOGO_PAGE_END);
        oled_write_raw((const char*)buffer, size);

        // 3. Render Handedness [L/R] (Pages 13-14)
        render_direction_hanedness();

        // 4. Clear Page 15 (Final row) to remove noise
        static const uint8_t PROGMEM blank_page[32] = {0};
        oled_set_cursor(0, 15);
        oled_write_raw_P((const char*)blank_page, 32);
    #endif
}

void update_oled_primary_cache(layer_state_t state, uint8_t* buffer, uint16_t size) {
    const layer_config_t* active_config = get_active_layer_config(state);
    uint8_t layer_count = get_layers_configs_visible_and_sorted_count();
    const layer_config_t** sorted_list = get_layers_configs_visible_and_sorted();

    if (!active_config || !active_config->name || !sorted_list || layer_count == 0) return;

    memset(buffer, 0, size);

    uint8_t name_len = (uint8_t)strlen(active_config->name);
    uint8_t indicator_slots = layer_count + 1;
    
    uint8_t name_height  = (name_len * LETTER_SPACING) - 2;
    uint8_t stack_height = (indicator_slots * INDICATOR_HEIGHT);

    uint8_t text_y = ((USABLE_HEIGHT_PX - name_height) / 2);
    uint8_t ind_y  = ((USABLE_HEIGHT_PX - stack_height) / 2);

    for (uint8_t i = 0; i < name_len; i++) {
        char c = active_config->name[i];
        if (c >= 'a' && c <= 'z') c -= CASE_CONV_OFFSET;
        if (c < ASCII_SPACE) c = ASCII_SPACE;
        const uint8_t* char_ptr = &font_custom[(uint16_t)(c - ASCII_SPACE) * FONT_BLOCK_SIZE];
        draw_bitmap_to_buffer(buffer, char_ptr, TEXT_X_OFFSET, text_y + (i * LETTER_SPACING), FONT_WIDTH, true);
    }

    uint8_t active_id = get_highest_layer(state);
    int8_t active_idx = -1;
    for (uint8_t i = 0; i < layer_count; i++) {
        if (sorted_list[i] && sorted_list[i]->id == active_id) {
            active_idx = (int8_t)i;
            break;
        }
    }

    for (uint8_t i = 0; i < indicator_slots; i++) {
        const uint8_t* bmp = get_indicator_bmp(i, layer_count, active_idx);
        if (bmp) {
            draw_bitmap_to_buffer(buffer, bmp, IND_X_OFFSET, ind_y + (i * INDICATOR_HEIGHT), 16, true);
        }
    }
}
