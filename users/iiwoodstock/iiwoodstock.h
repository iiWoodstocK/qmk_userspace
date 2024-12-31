/*
 *
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

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
	#undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define DF_WIN DF(WIN_BASE)
#define DF_MAC DF(MAC_BASE)
#define LOCK_T TG(LOCK_TG)

#define WIN_F MO(WIN_FN)
#define MAC_F MO(MAC_FN)
#define LOCK_F MO(LOCK_FN)

// clang-format off

enum layers {
    WIN_BASE,
    MAC_BASE,
    WIN_FN,
    MAC_FN,
    LOCK_TG,
	LOCK_FN
};

// clang-format on

// KEYCODES
enum custom_user_keycodes {
  KC_00 = SAFE_RANGE,

  RGB_TOI,      // Timeout idle time up
  RGB_TOD,      // Timeout idle time down

  NEW_SAFE_RANGE  // new safe range for keymap level custom keycodes
};

// IDLE TIMEOUTS
#ifdef IDLE_TIMEOUT_ENABLE
    #define TIMEOUT_THRESHOLD_DEFAULT   1    // default timeout minutes
    #define TIMEOUT_THRESHOLD_MAX       10  // upper limit (10 minutes)

    //prototype  functions
    uint16_t get_timeout_threshold(void);
    void timeout_reset_timer(void);
    void timeout_update_threshold(bool increase);
    void timeout_tick_timer(void);
#endif  //IDLE_TIMEOUT_ENABLE