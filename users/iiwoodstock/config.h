/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//Custom color aliases

#define RGB_DLAVENDER	          0x50, 0x20, 0xFF
#define RGB_LLAVENDER	          0x70, 0x38, 0xFF
#define RGB_WINERED	              0xFF, 0x00, 0x10
#define RGB_PEACH	              0xFF, 0x40, 0x40
#define RGB_BISQUE	              0xFF, 0xD0, 0x80
#define RGB_SUISEI	              0x30, 0x40, 0xFF
#define RGB_FAUNA	              0xA0, 0xFF, 0xA0
#define RGB_TOWAEYES              0xDE, 0xFC, 0x1D
#define RGB_CHIHAYA	              0x1B, 0x98, 0x9A
#define RGB_CECI                  0x99, 0xDA, 0xB0
#define RGB_VIVI                  0xFF, 0x11, 0xBB

#define HSV_DLAVENDER	          180, 224, 255
#define HSV_LLAVENDER	          183, 199, 255
#define HSV_WINERED	              253, 255, 255
#define HSV_PEACH	                0, 191, 255
#define HSV_BISQUE	               27, 127, 255
#define HSV_SUISEI	              167, 207, 255
#define HSV_FAUNA	               85,  95, 255
#define HSV_TOWAEYES               48, 227, 253
#define HSV_CHIHAYA	              128, 210, 154
#define HSV_CECI                  100,  76, 218
#define HSV_VIVI                  225, 239, 255

//#ifndef RGB_MATRIX_TIMEOUT
// If the keyboard is unused for 1 minutes then just turn off RGB
//#    define RGB_MATRIX_TIMEOUT 60000 // 1 minutes (1 * 60 * 1000ms)
//#endif

#ifndef MAC_LAYER_DEFAULT_COLOR
#    define MAC_LAYER_DEFAULT_COLOR RGB_SUISEI
#endif

#ifndef WIN_LAYER_DEFAULT_COLOR
#    define WIN_LAYER_DEFAULT_COLOR RGB_LLAVENDER
#endif

#ifndef LOCK_LAYER_COLOR
#    define LOCK_LAYER_COLOR RGB_OFF
#endif

#ifndef CAPS_LOCK_INDICATOR_COLOR
// alpha keys, caps lock, and both shift keys light up this color when caps lock is on
#    define CAPS_LOCK_INDICATOR_COLOR RGB_FAUNA
#endif

#ifndef SHIFT_INDICATOR_COLOR
// shift augmented keys light up this color when either shift is held
#    define SHIFT_INDICATOR_COLOR RGB_BISQUE
#endif

#ifndef FN_LAYER_KEYS_COLOR
// keys defined in the FN layer will use this color
#     define FN_LAYER_KEYS_COLOR RGB_WHITE
#endif

#ifndef CURRENT_LAYER_INDICATOR_COLOR
// this color indicates the active default layer
#    define CURRENT_LAYER_INDICATOR_COLOR RGB_VIVI
#endif

#ifndef NKRO_INDICATOR_COLOR
// the key on the fn layer that toggles it will light up this color, otherwise FN_LAYER_KEYS_COLOR when NKRO is disabled
#    define NKRO_INDICATOR_COLOR RGB_GREEN
#endif

#ifndef GUILOCK_INDICATOR_COLOR
// the key on the fn layer that toggles it will light up this color, otherwise FN_LAYER_KEYS_COLOR when GUILOCK is disabled
#    define GUILOCK_INDICATOR_COLOR RGB_RED
#endif

#ifndef LOCKLAYER_INDICATOR_COLOR
// the key on the fn layer that toggles it will light up this color
#    define LOCKLAYER_INDICATOR_COLOR RGB_ORANGE
#endif

#ifndef TIMEOUT_INDICATOR_COLOR
// the key on the fn layer that indicates it will light up this color
#    define TIMEOUT_INDICATOR_COLOR RGB_TOWAEYES
#endif

#ifndef RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// max 8 total layers
#define LAYER_STATE_8BIT

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING

#ifdef RGB_MATRIX_ENABLE 
    // RGB step values
    #define RGBLIGHT_HUE_STEP 32             // The number of steps to cycle through the hue by (default 10)
    #define RGBLIGHT_SAT_STEP 17             // The number of steps to increment the saturation by (default 17)
    #define RGBLIGHT_VAL_STEP 17             // The number of steps to increment the brightness by (default 17)

    // Startup values, when none have been set (HSV_PEACH)
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR    // Sets the default effect mode, if none has been set (was RGB_MATRIX_SOLID_COLOR)
    #define RGB_MATRIX_DEFAULT_HUE 0                          // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT 191                        // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_VAL 255                        // Sets the default brightness value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD 127                        // Sets the default animation speed, if none has been set

#endif //RGB_MATRIX_ENABLE

// RGB Matrix Animation modes. Explicitly disabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH