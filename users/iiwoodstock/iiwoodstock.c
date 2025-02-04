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

#include QMK_KEYBOARD_H
#include "iiwoodstock.h"

// TIMEOUTS
#ifdef IDLE_TIMEOUT_ENABLE
    static uint16_t timeout_timer = 0;
    static uint16_t timeout_counter = 0;  //in minute intervals
    static uint16_t timeout_threshold = TIMEOUT_THRESHOLD_DEFAULT;

    uint16_t get_timeout_threshold(void) {
        return timeout_threshold;
    }

    void timeout_reset_timer(void) {
        timeout_timer = timer_read();
        timeout_counter = 0;
    };

    void timeout_update_threshold(bool increase) {
        if (increase && timeout_threshold < TIMEOUT_THRESHOLD_MAX) timeout_threshold++;
        if (!increase && timeout_threshold > 0) timeout_threshold--;
    };

    void timeout_tick_timer(void) {
        if (timeout_threshold > 0) {
            if (timer_elapsed(timeout_timer) >= 60000) { // 1 minute tick
                timeout_counter++;
                timeout_timer = timer_read();
            }
            #ifdef RGB_MATRIX_ENABLE
                if (timeout_threshold > 0 && timeout_counter >= timeout_threshold) {
                    rgb_matrix_disable_noeeprom();
                }
            #endif
        } // timeout_threshold = 0 will disable timeout
    }

#endif // IDLE_TIMEOUT_ENABLE

#if defined(IDLE_TIMEOUT_ENABLE)       // timer features
    __attribute__((weak)) void matrix_scan_keymap(void) {}

    void matrix_scan_user(void) {
        #ifdef IDLE_TIMEOUT_ENABLE
            timeout_tick_timer();
        #endif
        matrix_scan_keymap();
    }
#endif   // IDLE_TIMEOUT_ENABLE

// PROCESS KEY CODES
__attribute__ ((weak))  bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) { return false; }
    switch (keycode) {

#ifdef IDLE_TIMEOUT_ENABLE
    case RGB_TOI:
        if(record->event.pressed) {
            timeout_update_threshold(true);
        } else  unregister_code16(keycode);
        break;
    case RGB_TOD:
        if(record->event.pressed) {
             timeout_update_threshold(false);  //decrease timeout
        } else  unregister_code16(keycode);
        break;
#endif // IDLE_TIMEOUT_ENABLE

    default:
        if (record->event.pressed) {
            #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_enable();
            #endif
            #ifdef IDLE_TIMEOUT_ENABLE
                timeout_reset_timer();  //reset activity timer
            #endif
        }
        break;
    }
    return true;
};

// INITIAL STARTUP
__attribute__ ((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
    #ifdef IDLE_TIMEOUT_ENABLE
        timeout_timer = timer_read(); // set inital time for idle timeout
    #endif
}