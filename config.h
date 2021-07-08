/*
  Set config.h overrides.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

/* Select hand configuration */
#define MASTER_LEFT

#define USE_SERIAL_PD2
#define USB_SUSPEND_WAKEUP_DELAY 0

/*
  RGB overides
  See https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#usage
*/
#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLED_NUM 12
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

/*
  Tabdance overides
*/
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define TAPPING_FORCE_HOLD

#define ONESHOT_TAP_TOGGLE 5

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 5000

/*
  Mouse mode overides
*/
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 40

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 400

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 14

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 45

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 100

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 8

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
