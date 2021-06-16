# Set correct bootloader for my controller, Puchi-C. (`qmk flash` will be looking for the wrong kind of device otherwise.)
BOOTLOADER = atmel-dfu
TAP_DANCE_ENABLE = yes
OLED_DRIVER_ENABLE = yes
RGBLIGHT_ENABLE = yes
