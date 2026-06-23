#include "oled_secondary.h"
#include "quantum.h"
#include "../../images/side_indicator/img_side_indicator.h"
#include "../../images/caps_lock/img_caps_lock.h"
#include "../../images/logo/img_logo.h"

#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix.h"
#endif

#define POSITION_Y_HANDEDNESS 13
#define POSITION_Y_RGB        8

/**
 * @brief Renders the UI to the secondary OLED.
 * Caps Lock [A] is at the Top-Left.
 * Handedness [L/R] is at the Bottom-Center.
 */
void render_oled_secondary_display(uint8_t* buffer, uint16_t size) {
    #ifdef OLED_ENABLE
        // 1. Get Bitmaps
        const uint8_t* side_bmp = is_keyboard_left() ? side_left_bmp : side_right_bmp;
        const uint16_t side_bmp_size = is_keyboard_left() ? side_left_bmp_size : side_right_bmp_size;

        bool caps_active = host_keyboard_led_state().caps_lock;
        const uint8_t* caps_lock = caps_active ? caps_lock_on_bmp : caps_lock_off_bmp;
        const uint16_t caps_lock_size = caps_active ? caps_lock_on_bmp_size : caps_lock_off_bmp_size;

        // 2. render logo
        oled_set_cursor(0, 0);
        oled_write_raw_P((const char *)zone_logo, zone_logo_size);

        // 3. Render Caps Lock                                                      
        oled_set_cursor(0, 4);
        oled_write_raw_P((const char*)caps_lock, caps_lock_size);

        // 5. Render Handedness [L/R]
        oled_set_cursor(0, POSITION_Y_HANDEDNESS);
        oled_write_raw_P((const char*)side_bmp, side_bmp_size);
    #endif
}
