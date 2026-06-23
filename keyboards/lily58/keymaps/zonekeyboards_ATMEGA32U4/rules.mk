
##################################
##### General configurations #####
##################################

MCU = atmega32u4

BOOTLOADER = caterina

TRI_LAYER_ENABLE = yes

# Enable mouse keys if needed (set to 'yes' to enable)
MOUSEKEY_ENABLE = no

# Enable console output for debugging (set to 'yes' to enable)
CONSOLE_ENABLE = no

# Enable Link Time Optimization for better performance and smaller firmware size
LTO_ENABLE = yes

# Enable OLED support
OLED_ENABLE = yes

# Enable I2C support
I2C_ENABLE = yes

# Enable EEPROM support
EEPROM_ENABLE = yes

# Enable Tap Dance feature
TAP_DANCE_ENABLE = yes

# Enable RGB Matrix support
RGB_MATRIX_ENABLE = yes

# Driver RGB
RGB_MATRIX_DRIVER = ws2812

# Enable VIA support for dynamic keymap configuration
VIA_ENABLE = yes

# Enable support for hand-wired split keyboards (if applicable)
EE_HANDS = yes

# Enable command feature for debugging and advanced features (set to 'yes' to enable)
COMMAND_ENABLE = no

# Enable terminal feature for debugging (set to 'yes' to enable)
TERMINAL_ENABLE = no

##################################
## Custom Modules Configuration ##
##################################

# include module images
IMAGES_DIR = images
SRC += $(IMAGES_DIR)/logo/img_logo.c \
			 $(IMAGES_DIR)/indicator/img_indicators.c \
			 $(IMAGES_DIR)/side_indicator/img_side_indicator.c \
			 $(IMAGES_DIR)/caps_lock/img_caps_lock.c 

# include module OLED manager
OLED_DIR = oled
SRC += $(OLED_DIR)/oled_manager.c \
			 $(OLED_DIR)/oled_primary/oled_primary.c \
			 $(OLED_DIR)/oled_secondary/oled_secondary.c

# include module layers
LAYERS_DIR = layers
SRC += $(LAYERS_DIR)/layer_manager.c

# include module fonts
FONTS_DIR = fonts
SRC += $(FONTS_DIR)/glcdfont.c

# languaje keycode ZK, values accepted (LATAM, SPANISH, ENGLISH)
ZK_LANGUAGE = LATAM

# Optiones definitions, environment varible or file
OPT_DEFS += -DLANG_$(strip $(ZK_LANGUAGE))
OPT_DEFS += -DZK_KEYBOARD_H=\"zk_keyboard.h\"


# Defaul LILY58 files
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \