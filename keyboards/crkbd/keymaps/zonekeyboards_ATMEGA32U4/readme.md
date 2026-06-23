# Lily58 Corne Cherry V3 firmware (QMK Firmware 0.32.13)

This directory contains a modular QMK keymap configuration for the **Lily58** split keyboard, specifically tailored for controllers powered by the **ATmega32U4** microcontroller (such as the Pro Micro). 

This keymap implements advanced features, including custom OLED display logic, an RGB matrix configuration, tap-dance controls, and a multi-language keycode mapping system.

---


## Directory Structure Analysis

The `zonekeyboards_ATMEGA32U4` folder implements a highly modular structure to compile a customized firmware for the Sofle keyboard (running on an ATmega32U4 controller). Below is an explanation of the files and directories:

### Root Files
*   [config.h]: Hardware configuration overrides. Defines custom layer configuration numbers, enables split-keyboard features (like mirror transport, activity detection, OLED state sharing), specifies RGB matrix settings (brightness, effects), configures VIA dynamic layer counts, and sets OLED refresh constraints.
*   [rules.mk]: Build settings for QMK. Declares the microcontroller (`atmega32u4`), the bootloader (`caterina`), enables specific features (like TAP_DANCE, VIA, OLED, EEPROM, RGB Matrix), and dynamically links files from custom module directories (`images`, `oled`, `layers`, `fonts`). It also defines the layout language (`ZK_LANGUAGE = LATAM`).
*   [zk_keyboard.h]: Master header file that integrates all modular components (layers manager, OLED manager, macros, and Spanish/LATAM keymap extras).
*   [keymap.c]: The primary QMK keymap file. It defines the layout matrices (BASE, LOWER, RAISE, ADJUST layers), keycodes, rotary encoder behaviors, and standard QMK initialization and update hooks (such as encoder rotation and OLED task updates).


### Subdirectories
*   **`fonts/`**:
    *   [glcdfont.c] / [glcdfont.h]: Contains the custom font matrix used by the OLED screen.
*   **`images/`**:
    *   Holds custom bitmaps divided by their display purpose, used to draw graphics on the OLED screens:
        *   `caps_lock/`: Bitmap for the Caps Lock indicator status (On/Off).
        *   `indicator/`: Bitmaps for active layer navigation/state bullets.
        *   `logo/`: Custom startup logo bitmap (`zone_logo`).
        *   `side_indicator/`: Bitmaps indicating handedness (Left/Right side indicator graphics).
*   **`keymap_extras_zk/`**:
   *   [keymap_multilanguaje_zk.h]: A keycode dictionary that maps standard Spanish (Latin America and Spain) and English to their corresponding QMK keycodes under the `ZK_` prefix.
*   **`layers/`**:
    *   [layer_macros.h]: Macro definitions that generate the layer enum and layer configurations array (X-Macro pattern).
    *   [layer_manager.c] / [layer_manager.h]: Manages active layers information, caching visible layers, and sorting them to be cleanly shown on the OLED display.
*   **`layout/`**:
    *   [layout_macros.h]: Defines the `LAYOUT_SPLIT` macro, wrapping key matrix arguments into the standard QMK split keyboard physical representation.
*   **`oled/`**:
    *   [oled_manager.c] / [oled_manager.h]: Orchestrates drawing on both OLED displays. It caches the layers state and routes rendering function calls to the primary and secondary OLED displays.
    *   `oled_primary/` ([oled_primary.c] / [oled_primary.h]): Code to render the master-side OLED interface (Logo, current layer name, vertical navigation bullets, and L/R side indicators).
    *   `oled_secondary/` ([oled_secondary.c] / [oled_secondary.h]): Code to render the slave-side OLED interface (Logo, Caps Lock status, and L/R side indicators).

---

## Compilation Instructions

To compile the firmware and initialize the handedness settings in the EEPROM for each side of the keyboard, run the following commands:

*   **Left Side:**
    ```bash
    qmk compile -c -kb lily58/rev1 -km zonekeyboards_ATMEGA32U4 -e EXTRAFLAGS="-DINIT_EE_HANDS_LEFT"
    ```

*   **Right Side:**
    ```bash
    qmk compile -c -kb lily58/rev1 -km zonekeyboards_ATMEGA32U4 -e EXTRAFLAGS="-DINIT_EE_HANDS_RIGHT"
    ```
