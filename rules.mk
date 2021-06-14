# Set correct bootloader for my controller, Puchi-C. (`qmk flash` will be looking for the wrong kind of device otherwise.)
BOOTLOADER = atmel-dfu
OLED_DRIVER_ENABLE  = no
TAP_DANCE_ENABLE = yes