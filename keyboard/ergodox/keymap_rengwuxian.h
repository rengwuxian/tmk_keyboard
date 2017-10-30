/*
 * Bu-TECK inspired Layout. Credit to Oobly
 * https://geekhack.org/index.php?topic=49721.msg1078758#msg1078758
 *
 * NOTES:
 * To be used with QWERTY US 101-key keyboard layout
 *
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and release quickly)
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_TAP_KEY(layer, key)
 * Turns on layer momentary while holding, but registers key on tap(press and release quickly).
 *
 * MACRO()
 *
 */

enum macro_id {
  EURO,
  POUND,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =  ACTION_LAYER_TAP_KEY(1, KC_N),             // FN0  -  Momentary Layer1 on N key
    [1] =  ACTION_LAYER_TAP_KEY(2, KC_T),             // FN1  -  Momentary Layer2 on T key
    [2] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_H),       // FN2  -  Tap for H, Hold for Shift
    [3] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_E),       // FN3  -  Tap for E, Hold for Shift
    [4] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_S),       // FN4  -  Tap for S, Hold for Alt
    [5] =  ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH),      // FN8  -  Hold=Left-Shift, Tap='\'
    [6] =  ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE),       // FN9  -  Hold=Left-Shift, Tap='`'
    [7] =  ACTION_MODS_KEY(MOD_LSFT, KC_1),           // FN10 -  Hold=Left-Shift, Tap=1
    [8] =  ACTION_MODS_KEY(MOD_LSFT, KC_2),           // FN11 -  Hold=Left-Shift, Tap=2
    [9] =  ACTION_MODS_KEY(MOD_LSFT, KC_3),           // FN12 -  Hold=Left-Shift, Tap=3
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_4),           // FN13 -  Hold=Left-Shift, Tap=4
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_5),           // FN14 -  Hold=Left-Shift, Tap=5
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_6),           // FN15 -  Hold=Left-Shift, Tap=6
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_7),           // FN16 -  Hold=Left-Shift, Tap=7
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_9),//ACTION_MACRO(OPEN_PARENTHESIS),            // FN17 -  Unshifted='(', Shifted=PgUp
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_0),//ACTION_MACRO(CLOSE_PARENTHESIS),           // FN18 -  Unshifted=')', Shifted=PgDown
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET),    // FN20 -  Hold=Left-Shift, Tap='['
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),    // FN21 -  Hold=Left-Shift, Tap=']'
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_SLASH),       // FN22 -  Hold=Left-Shift, Tap='/'
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON),      // FN23 -  Hold=Left-Shift, Tap=';'
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA),       // FN24 -  Hold=Left-Shift, Tap=','
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),         // FN25 -  Hold=Left-Shift, Tap='.'
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE),       // FN26 -  Hold=Left-Shift, Tap="'"
    [23] = ACTION_MACRO(EURO),                        // FN27 -  Hold=AltGr, Tap='=', Tap=e
    [24] = ACTION_MACRO(POUND),                       // FN28 -  Hold=AltGr, Tap=l, Tap=-
    [25] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_O),       // FN30 -  Tap for O, Hold for Alt
    [26] = ACTION_LAYER_TAP_KEY(3, KC_A),             // FN31 -  Tap for A, Hold for Layer3
    [27] = ACTION_LAYER_TAP_KEY(4, KC_I),             // FN31 -  Tap for I, Hold for Layer4
};

/* Define function actions for readability of keymap below */
#define KC_NML       KC_FN0
#define KC_TML       KC_FN1
#define KC_HMS       KC_FN2
#define KC_EMS       KC_FN3
#define KC_SMA       KC_FN4
#define KC_PIPE      KC_FN5
#define KC_TILDE     KC_FN6
#define KC_EXCL      KC_FN7
#define KC_AT        KC_FN8    // removable
#define KC_HASH      KC_FN9
#define KC_DOLLR     KC_FN10
#define KC_PRCNT     KC_FN11
#define KC_CARET     KC_FN12
#define KC_AMPRS     KC_FN13
#define KC_OPAREN    KC_FN14
#define KC_CPAREN    KC_FN15
#define KC_OCUBRC    KC_FN16
#define KC_CCUBRC    KC_FN17
#define KC_QUESTN    KC_FN18
#define KC_COLON     KC_FN19
#define KC_SMLRT     KC_FN20
#define KC_GRTRT     KC_FN21
#define KC_DQUOT     KC_FN22
#define KC_EURO      KC_FN23
#define KC_POUND     KC_FN24
#define KC_OMA       KC_FN25
#define KC_AMN       KC_FN26 // a mod numpad (layer3)
#define KC_IMF       KC_FN27 // i mod f-keys (layer4)


static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,-----------------------------------------------.           ,----------------------------------------------------.
     * |  Esc   |   1  |  2  |  3  |  4   |  5  | LGUI |           | PSCR |   6   |   7   |   8  |  9   |   0  |  Del   |
     * |--------+------+-----+-----+------+------------|           |------+-------+-------+------+------+------+--------|
     * |  Tab   |   Q  |  D  |  R  |  W   |  B  | Right|           |  Up  |   J   |   F   |   U  |  P   |   +  |        |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * |   $    |   A  |  S  |  H  |  T   |  G  |------|           |------|   Y   |   N   |   E  |  O   |   I  |        |
     * |--------+------+-----+-----+------+-----| Left |           | Down |-------+-------+------+------+------+--------|
     * | LShift |   Z  |  X  |  M  |  C   |  V  |      |           |      |   K   |   L   |  <,  |  >.  |  -_  | RSHIFT |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  |  Mute |  ~   |     | LAlt| LCtrl|                                       | RCtrl | RAlt | VOLU | VOLD |NUMLOCK |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |LShift| Home |       | PgUp |LShift|
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       |PgDown|      |      |
     *                                 | Tab  | Bkspc|------|       |------|Enter |Space |
     *                                 |      |      | '"   |       | LGUI |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     * Layer 1: Left                                                  Layer2: Right
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  | F9   |  F10 |  Bkspc |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |  ^   |  [   |  Up  |  ]   |  *   | Left |           |  Up  |  ~   |  (   |  !   |  )   |  $   |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |   /    | Home | Left | Down |Right |  End |------|           |------|  =   |  {   |  ?   |  }   |  "   |   \    |
     * |--------+------+------+------+------+------|  End |           |PgDown|------+------+------+------+------+--------|
     * | CapsLck|  &   |  |   |  +   |  ;   |  :   |      |           |      |  %   |  <   |  #   |  >   |  `   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |  €   |  £   |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |  Esc | Del  |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Numbers layer
     * Layer 3:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  /   |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |  *   |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |  -   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |  0   |  .   |  ,   |  +   |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * fkeys layer
     * Layer 4:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |  f7  |  f8  |  f9  |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        | f11  |  f4  |  f5  |  f6  | f12  |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |  f1  |  f2  |  f3  |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      | f10  |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // Layer0, Left hand.
        ESC,     1,       2,      3,      4,   5,  NO,
        TAB,     Q,       D,      R,     W ,   B, RIGHT,
      DOLLR,   AMN,     SMA,    HMS,    TML,   G,
     LSHIFT,     Z,       X,      M,      C,   V,  LEFT,
       MUTE, TILDE,     EQL,   LALT,  LCTRL,

                                     LSHIFT, HOME,
                                              END,
                                 TAB, BSPC, QUOTE,

             // Right hand.
             PSCR,    6,     7,      8,        9,        0,   DELETE,
               UP,    J,     F,      U,        P,  KP_PLUS,   NO,
                      Y,   NML,    EMS,      OMA,      IMF,   NO,
             DOWN,    K,     L,  COMMA,      DOT,    MINUS,   RSHIFT,
                          RCTL,  RALT ,     VOLU,     VOLD,   NLCK,

           PGUP, LSHIFT,
           PGDN,
           LGUI, ENTER, SPC
    ),


    KEYMAP(  // Layer1, left hand
            TRNS,     F1,       F2,       F3,       F4,          F5,  F11,
              NO,  CARET, LBRACKET,       UP, RBRACKET, KP_ASTERISK, HOME,
            SLSH,   HOME,     LEFT,     DOWN,    RIGHT,         END,
        CAPSLOCK,  AMPRS,     PIPE,  KP_PLUS,   SCOLON,       COLON,  END,
            TRNS,   EURO,    POUND,     TRNS,     TRNS,

                                       TRNS, TRNS,
                                             TRNS,
                                ESC, DELETE, TRNS,

             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),


    KEYMAP(  // Layer2, right hand
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,

                  F12,     F6,     F7,     F8,    F9,     F10,   BSPC,
                 PGUP,  TILDE, OPAREN,   EXCL, CPAREN,  DOLLR,   TRNS,
                          EQL, OCUBRC, QUESTN, CCUBRC,  DQUOT, BSLASH,
                 PGDN,  PRCNT,  SMLRT,   HASH,  GRTRT,  GRAVE,   TRNS,
                                 TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
         TRNS, TRNS,
         TRNS,
         TRNS, TRNS, TRNS
    ),

    KEYMAP(  // Layer3, numbers
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,

             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,  P7,  P8,  P9,PSLS,TRNS,
                  TRNS,  P4,  P5,  P6,PAST,TRNS,
             TRNS,TRNS,  P1,  P2,  P3,PMNS,TRNS,
                         P0,PDOT,PCMM,PPLS,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer4, f-keys
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS,   F7,   F8,   F9, TRNS, TRNS,
        TRNS,  F11,   F4,   F5,   F6,  F12,
        TRNS, TRNS,   F1,   F2,   F3, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS,  F10,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,

             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
        return MACRO_NONE;
    }

    switch (id) {
        case EURO:
            return MACRO( I(15), D(RALT), T(EQL), T(E), U(RALT), END );
        case POUND:
            return MACRO( I(15), D(RALT), T(L), T(MINUS), U(RALT), END );
    }
    return MACRO_NONE;
}

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO &&
        FN_INDEX(keycode) < (sizeof(fn_actions)   / sizeof(fn_actions[0]))) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}
