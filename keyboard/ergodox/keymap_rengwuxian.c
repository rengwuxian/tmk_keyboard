/*
Copyright 2016 Paul Williamson <squarefrog@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <util/delay.h>
#include "bootloader.h"
#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Keymap 0: Default Colemak Layer
     *
     * This is a general purpose Colemak layout which should serve as a good
     * basis for your own custom layout. Mac users may want to swap the
     * position of the Alt and GUI keys.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  | CpsLk|           |  -   |   6  |   7  |   8  |   9  |   0  |   +    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   ~    |   Q  |   W  |   E  |   R  |   T  | VolDn|           |VolUp |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  Tab   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| PgDn |           | PgUp |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L1  |   [  |   ]  | LAlt | LGui |                                       |  Lt  |  Dn  |  Up  |  Rt  |  ~L1 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  F1  |  F2  |       |  F3  |  +L2 |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Space|       | Space|      |      |
     *                                 | Space|BSpace|------|       |------| RCtrl| Enter|
     *                                 |      |      | G + A|       | Space|      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(
        // left hand
        ESC, 1,   2,   3,   4,   5,   CAPS,
        GRV, Q,   W,   E,   R,   T,   VOLD,
        TAB, A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   PGDN,
        CAPS, FN2, FN3,FN4,FN5,
                                      F1,  F2,
                                           RSFT,
                                 SPC,CAPS,FN15,
        // right hand
             MINS,6,   7,   FN28,   9,   0,   EQL,
             VOLU,Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,SCLN,   QUOT,
             BSPC,N,   M,   COMM,DOT, SLSH,RSFT,
                       FN6,FN7,FN8,FN9,  CAPS,
        F3,  FN2,
        RSFT,
        FN17,BSPC, ENT
    ),

    /*
     * Layer 1: Function keys
     *
     * This layer contains function keys, and media keys. Additionally, there
     * are QWERTY-style Vim arrow keys. I could never get used to Colemak's
     * rearranged Vim arrow placements.
     *
     * Most of the non-modifier keys are marked as NO, so it's immediately
     * obvious if you start typing on a secondary layer.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Teensy |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |  TRNS  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      | TRNS |           | TRNS |      |      |      |      |      |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |  TRNS  |
     * |--------+------+------+------+------+------| +L2  |           |      |------+------+------+------+------+--------|
     * |   TRNS |      |      |      |      |      |      |           |      |      |      |      |      |      |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | TRNS | Play |  RW  |  FF  |                                       | Mute | Vol- | Vol+ | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       | HOME |  END |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 |SPACE |      |------|       |------| TRNS | ENTER|
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(
        // left hand
        FN31,TRNS, TRNS, TRNS, TRNS, TRNS,   F11,
        TRNS,FN3,  F7,  F8,  F9,  NO,   TRNS,
        TRNS,MS_L, F4,  F5,  F6,  BTN1,
        TRNS,FN5,  F1,  F2,  F3,  BTN2, FN2,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      NO,  NO,
                                           TRNS,
                                 SPC,NO,  TRNS,
        // right hand
             F12, TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,
             TRNS,NO,  NO,  UP,  NO,  NO,  TRNS,
                  LEFT,LEFT,DOWN,  RGHT,NO,  TRNS,
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        HOME,END,
        TRNS,
        TRNS,TRNS,ENT
    ),

    /*
    * Layer 2: Number Pad
    *
    * This layer has a number pad for quicker number entry. As with layer 1,
    * most of the non-modifier keys are marked as NO, so it's immediately
    * obvious if you start typing on a secondary layer.
    *
    * Inspired by Ben Blazak QWERTY num pad.
    * https://git.io/voIeY
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   ESC  |      |      |      |      |      |      |           |      |      | NmLk |   /  |   *  |   -  | Bkspc  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      | TRNS |           | TRNS |      |   7  |   8  |   9  |   +  | Bkspc  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  | Enter  |
    * |--------+------+------+------+------+------|      |           | -L0  |------+------+------+------+------+--------|
    * |   TRNS |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | Enter| Enter  |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | TRNS | TRNS | LALT |      |      |                                       |   0  |   0  |   .  | Enter| Enter|
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       | TRNS | TRNS |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      | TRNS |       | TRNS |      |      |
    *                                 | Bkspc|      |------|       |------| Enter|      |
    *                                 |      |      | TRNS |       | TRNS |      |      |
    *                                 `--------------------'       `--------------------'
    */

    KEYMAP(
        // left hand
        ESC, NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,TRNS,LALT,NO,  NO,
                                      NO,  NO,
                                           TRNS,
                                 BSPC,NO,  TRNS,
        // right hand
             NO,  NO,  NLCK,SLSH,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PPLS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             FN0, NO,  P1,  P2,  P3,  PENT,PENT,
                       P0,  P0,  PDOT,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,ENT, TRNS
    ),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    // Layer shifting
    [0] = ACTION_LAYER_SET(0, ON_PRESS),           // Switch to Layer 0

    // [1] = ACTION_LAYER_TOGGLE(1),
    [2] = ACTION_LAYER_TAP_KEY(1, KC_LBRC),
    [3] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_RBRC),
    [4] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_MINS),
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_EQL),
    [6] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LEFT),
    [7] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOWN),
    [8] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_UP),
    [9] = ACTION_LAYER_TAP_KEY(1, KC_RGHT),
    // [10] = ACTION_LAYER_TOGGLE(2),

    [11] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),
    [14] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENTER),
    [15] = ACTION_LAYER_MOMENTARY(1),
    [17] = ACTION_LAYER_MOMENTARY(1),

    [28] = ACTION_LAYER_TAP_KEY(1, KC_8),

    // Teensy≈
    [31] = ACTION_FUNCTION(TEENSY_KEY),
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

