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

#define RGB_DLAVENDER	0x50, 0x20, 0xFF
#define RGB_LLAVENDER	0x70, 0x38, 0xFF
#define RGB_WINERED	0xFF, 0x00, 0x10
#define RGB_PEACH	0xFF, 0x40, 0x40
#define RGB_BISQUE	0xFF, 0xD0, 0x80
#define RGB_SUISEI	0x30, 0x40, 0xFF
#define RGB_FAUNA	0xA0, 0xFF, 0xA0

#define HSV_DLAVENDER	179, 223, 255
#define HSV_LLAVENDER	183, 199, 255
#define HSV_WINERED	253, 255, 255
#define HSV_PEACH	  0, 191, 255
#define HSV_BISQUE	 27, 127, 255
#define HSV_SUISEI	167, 207, 255
#define HSV_FAUNA	 85,  95, 255


// All of these config options can be changed by keyboard in their config.h
// These are all just the defaults I like for most of my keyboards

#ifndef RGB_MATRIX_TIMEOUT
// If the keyboard is unused for 1 minutes then just turn off RGB
#    define RGB_MATRIX_TIMEOUT 60000 // 1 minutes (1 * 60 * 1000ms)
#endif

#ifndef MAC_LAYER_DEFAULT_COLOR
#    define MAC_LAYER_DEFAULT_COLOR RGB_SUISEI
#endif

#ifndef WIN_LAYER_DEFAULT_COLOR
#    define WIN_LAYER_DEFAULT_COLOR RGB_LLAVENDER
#endif

#ifndef CAPS_LOCK_INDICATOR_COLOR
// When caps lock is pressed, the letter keys, caps lock, and both shift keys, will light up this color.
#    define CAPS_LOCK_INDICATOR_COLOR RGB_FAUNA
#endif

#ifndef SHIFT_INDICATOR_COLOR
// If defined also light up alphabet keys when either shift is held
#    define SHIFT_INDICATOR_COLOR RGB_BISQUE
#endif

#ifndef CAPS_LOCK_INDICATOR_OTHER
// When caps lock is pressed, all other keys will light up this color
// #define CAPS_LOCK_INDICATOR_OTHER RGB_WHITE
#endif

#ifndef CAPS_LOCK_INDICATOR_LIGHT_ALPHAS
// All alphabet keys will light up, otherwise just caps lock.
#    define CAPS_LOCK_INDICATOR_LIGHT_ALPHAS RGB_OFF
#endif

#ifndef FN_LAYER_TRANSPARENT_KEYS_COLOR
// Keys not defined in the current layer will use this color
//#    define FN_LAYER_TRANSPARENT_KEYS_COLOR RGB_OFF
#endif

// Keys defined in the current layer will use this color
#ifndef FN_LAYER_KEYS_COLOR
#     define FN_LAYER_KEYS_COLOR RGB_WHITE
#endif

#ifndef CURRENT_LAYER_INDICATOR_COLOR
// If a key on a FN layer changes the default layer to the current layer, light up this color
#    define CURRENT_LAYER_INDICATOR_COLOR RGB_PEACH
#endif

#ifndef NKRO_INDICATOR_COLOR
// If NKRO is enabled, the key on the fn layer that toggles it will light up this color
#    define NKRO_INDICATOR_COLOR RGB_GREEN
#endif

#ifndef GUILOCK_INDICATOR_COLOR
// If GUILOCK is enabled, the key on the fn layer that toggles it will light up this color
#    define GUILOCK_INDICATOR_COLOR RGB_RED
#endif

// Don't light up my whole room when the pc is asleep
#ifndef RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif