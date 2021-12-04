/* Copyright 2021 REPLACE_WITH_YOUR_NAME
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

#define _BL 0  // base layer
#define _ALT_GR 1  // altgr layer
#define _lACUTE 2  // lower case acute layer
#define _UACUTE 3  // Upper case acute layer
#define _lAGRAVE 4  // lower case agrave layer
#define _UAGRAVE 5  // lower case agrave layer
#define _lUML 6
#define _UUML 7
#define _lCIRC 8
#define _UCIRC 9
#define _lCEDIL 10
#define _UCEDIL 11
#define _EMOJI 12
#define _OPTS 13

enum unicode_names {
    a_ACUTE,
    A_ACUTE,
    a_GRAVE,
    A_GRAVE,
    a_CIRC,
    A_CIRC,
    a_UML,
    A_UML,
    c_CEDIL,
    C_CEDIL,
    e_ACUTE,
    E_ACUTE,
    e_GRAVE,
    E_GRAVE,
    e_CIRC,
    E_CIRC,
    e_UML,
    E_UML,
    i_CIRC,
    I_CIRC,
    i_UML,
    I_UML,
    o_CIRC,
    O_CIRC,
    u_GRAVE,
    U_GRAVE,
    u_CIRC,
    U_CIRC,
    u_UML,
    U_UML,

    emoji_p1,
    emoji_smile,
    emoji_troll,
    emoji_party,
    emoji_thanks,
    emoji_muscle,
    emoji_heart,
    emoji_champagne,
    emoji_shrug,
    emoji_scream,
    emoji_beer,
    emoji_up,
    emoji_cry,
    emoji_sweat,
};

// U+00C0 	À 	0192 	0303 0200 	&Agrave; 	Latin Capital Letter A with grave 	0128
// U+00C1 	Á 	0193 	0303 0201 	&Aacute; 	Latin Capital letter A with acute 	0129
// U+00C2 	Â 	0194 	0303 0202 	&Acirc; 	Latin Capital letter A with circumflex 	0130
// U+00C3 	Ã 	0195 	0303 0203 	&Atilde; 	Latin Capital letter A with tilde 	0131
// U+00C4 	Ä 	0196 	0303 0204 	&Auml; 	Latin Capital letter A with diaeresis 	0132
// U+00C5 	Å 	0197 	0303 0205 	&Aring; 	Latin Capital letter A with ring above 	0133
// U+00C6 	Æ 	0198 	0303 0206 	&AElig; 	Latin Capital letter Æ 	0134
// U+00C7 	Ç 	0199 	0303 0207 	&Ccedil; 	Latin Capital letter C with cedilla 	0135
// U+00C8 	È 	0200 	0303 0210 	&Egrave; 	Latin Capital letter E with grave 	0136
// U+00C9 	É 	0201 	0303 0211 	&Eacute; 	Latin Capital letter E with acute 	0137
// U+00CA 	Ê 	0202 	0303 0212 	&Ecirc; 	Latin Capital letter E with circumflex 	0138
// U+00CB 	Ë 	0203 	0303 0213 	&Euml; 	Latin Capital letter E with diaeresis 	0139
// U+00CC 	Ì 	0204 	0303 0214 	&Igrave; 	Latin Capital letter I with grave 	0140
// U+00CD 	Í 	0205 	0303 0215 	&Iacute; 	Latin Capital letter I with acute 	0141
// U+00CE 	Î 	0206 	0303 0216 	&Icirc; 	Latin Capital letter I with circumflex 	0142
// U+00CF 	Ï 	0207 	0303 0217 	&Iuml; 	Latin Capital letter I with diaeresis 	0143
// U+00D0 	Ð 	0208 	0303 0220 	&ETH; 	Latin Capital letter Eth 	0144
// U+00D1 	Ñ 	0209 	0303 0221 	&Ntilde; 	Latin Capital letter N with tilde 	0145
// U+00D2 	Ò 	0210 	0303 0222 	&Ograve; 	Latin Capital letter O with grave 	0146
// U+00D3 	Ó 	0211 	0303 0223 	&Oacute; 	Latin Capital letter O with acute 	0147
// U+00D4 	Ô 	0212 	0303 0224 	&Ocirc; 	Latin Capital letter O with circumflex 	0148
// U+00D5 	Õ 	0213 	0303 0225 	&Otilde; 	Latin Capital letter O with tilde 	0149
// U+00D6 	Ö 	0214 	0303 0226 	&Ouml; 	Latin Capital letter O with diaeresis 	0150
// Math 	U+00D7 	× 	0215 	0303 0227 	&times; 	Multiplication sign 	0151
// Letters:

// Uppercase
// 	U+00D8 	Ø 	0216 	0303 0230 	&Oslash; 	Latin Capital letter O with stroke 	0152
// U+00D9 	Ù 	0217 	0303 0231 	&Ugrave; 	Latin Capital letter U with grave 	0153
// U+00DA 	Ú 	0218 	0303 0232 	&Uacute; 	Latin Capital letter U with acute 	0154
// U+00DB 	Û 	0219 	0303 0233 	&Ucirc; 	Latin Capital Letter U with circumflex 	0155
// U+00DC 	Ü 	0220 	0303 0234 	&Uuml; 	Latin Capital Letter U with diaeresis 	0156
// U+00DD 	Ý 	0221 	0303 0235 	&Yacute; 	Latin Capital Letter Y with acute 	0157
// U+00DE 	Þ 	0222 	0303 0236 	&THORN; 	Latin Capital Letter Thorn 	0158
// Letters:

// Lowercase
// 	U+00DF 	ß 	0223 	0303 0237 	&szlig; 	Latin Small Letter sharp S 	0159
// U+00E0 	à 	0224 	0303 0240 	&agrave; 	Latin Small Letter A with grave 	0160
// U+00E1 	á 	0225 	0303 0241 	&aacute; 	Latin Small Letter A with acute 	0161
// U+00E2 	â 	0226 	0303 0242 	&acirc; 	Latin Small Letter A with circumflex 	0162
// U+00E3 	ã 	0227 	0303 0243 	&atilde; 	Latin Small Letter A with tilde 	0163
// U+00E4 	ä 	0228 	0303 0244 	&auml; 	Latin Small Letter A with diaeresis 	0164
// U+00E5 	å 	0229 	0303 0245 	&aring; 	Latin Small Letter A with ring above 	0165
// U+00E6 	æ 	0230 	0303 0246 	&aelig; 	Latin Small Letter Æ 	0166
// U+00E7 	ç 	0231 	0303 0247 	&ccedil; 	Latin Small Letter C with cedilla 	0167
// U+00E8 	è 	0232 	0303 0250 	&egrave; 	Latin Small Letter E with grave 	0168
// U+00E9 	é 	0233 	0303 0251 	&eacute; 	Latin Small Letter E with acute 	0169
// U+00EA 	ê 	0234 	0303 0252 	&ecirc; 	Latin Small Letter E with circumflex 	0170
// U+00EB 	ë 	0235 	0303 0253 	&euml; 	Latin Small Letter E with diaeresis 	0171
// U+00EC 	ì 	0236 	0303 0254 	&igrave; 	Latin Small Letter I with grave 	0172
// U+00ED 	í 	0237 	0303 0255 	&iacute; 	Latin Small Letter I with acute 	0173
// U+00EE 	î 	0238 	0303 0256 	&icirc; 	Latin Small Letter I with circumflex 	0174
// U+00EF 	ï 	0239 	0303 0257 	&iuml; 	Latin Small Letter I with diaeresis 	0175
// U+00F0 	ð 	0240 	0303 0260 	&eth; 	Latin Small Letter Eth 	0176
// U+00F1 	ñ 	0241 	0303 0261 	&ntilde; 	Latin Small Letter N with tilde 	0177
// U+00F2 	ò 	0242 	0303 0262 	&ograve; 	Latin Small Letter O with grave 	0178
// U+00F3 	ó 	0243 	0303 0263 	&oacute; 	Latin Small Letter O with acute 	0179
// U+00F4 	ô 	0244 	0303 0264 	&ocirc; 	Latin Small Letter O with circumflex 	0180
// U+00F5 	õ 	0245 	0303 0265 	&otilde; 	Latin Small Letter O with tilde 	0181
// U+00F6 	ö 	0246 	0303 0266 	&ouml; 	Latin Small Letter O with diaeresis 	0182
// Math 	U+00F7 	÷ 	0247 	0303 0267 	&divide; 	Division sign 	0183
// Letters:

// Lowercase
// 	U+00F8 	ø 	0248 	0303 0270 	&oslash; 	Latin Small Letter O with stroke 	0184
// U+00F9 	ù 	0249 	0303 0271 	&ugrave; 	Latin Small Letter U with grave 	0185
// U+00FA 	ú 	0250 	0303 0272 	&uacute; 	Latin Small Letter U with acute 	0186
// U+00FB 	û 	0251 	0303 0273 	&ucirc; 	Latin Small Letter U with circumflex 	0187
// U+00FC 	ü 	0252 	0303 0274 	&uuml; 	Latin Small Letter U with diaeresis 	0188
// U+00FD 	ý 	0253 	0303 0275 	&yacute; 	Latin Small Letter Y with acute 	0189
// U+00FE 	þ 	0254 	0303 0276 	&thorn; 	Latin Small Letter Thorn 	0190
// U+00FF 	ÿ 	0255 	0303 0277 	&yuml; 	Latin Small Letter Y with diaeresis 	0191

const uint32_t PROGMEM unicode_map[] = {
    [a_ACUTE]  = 0x00E1,
    [A_ACUTE]  = 0x00C1,
    [a_GRAVE]  = 0x00E0,
    [A_GRAVE]  = 0x00C0,
    [a_CIRC]  = 0x00E2,
    [A_CIRC]  = 0x00C2,
    [a_UML]  = 0x00E4,
    [A_UML]  = 0x00C4,
    [c_CEDIL]  = 0x00E7,
    [C_CEDIL]  = 0x00C7,
    [e_ACUTE]  = 0x00E9,
    [E_ACUTE]  = 0x00C9,
    [e_GRAVE]  = 0x00E8,
    [E_GRAVE]  = 0x00C8,
    [e_CIRC]  = 0x00EA,
    [E_CIRC]  = 0x00CA,
    [e_UML]  = 0x00EB,
    [E_UML]  = 0x00CB,
    [i_CIRC]  = 0x00EE,
    [I_CIRC]  = 0x00CE,
    [i_UML]  = 0x00EF,
    [I_UML]  = 0x00CF,
    [o_CIRC]  = 0x00F4,
    [O_CIRC]  = 0x00D4,
    [u_GRAVE]  = 0x00F9,
    [U_GRAVE]  = 0x00D9,
    [u_CIRC]  = 0x00FB,
    [U_CIRC]  = 0x00DB,
    [u_UML]  = 0x00FC,
    [U_UML]  = 0x00DC,

    [emoji_p1] = 0x1F44D,
    [emoji_smile] = 0x1F600,
    [emoji_troll] = 0x1F47A,
    [emoji_party] = 0x1F389,
    [emoji_thanks] = 0x1F64F,
    [emoji_muscle] = 0x1F4AA,
    [emoji_heart] = 0x2764,
    [emoji_champagne] = 0x1F37E,
    [emoji_shrug] = 0x1F937,
    [emoji_scream] = 0x1F631,
    [emoji_beer] = 0x1F37B,
    [emoji_up] = 0x261D,
    [emoji_cry] = 0x1F622,
    [emoji_sweat] = 0x1F625,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        KC_ESC,    KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______,  KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, _______,  _______,  _______, _______, _______, _______, KC_HOME, KC_END, KC_INS, KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_ENT,
        KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,
        KC_LSFT,   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        _______, KC_LCTL,   KC_LGUI, KC_LALT, KC_SPC,                                      OSL(_ALT_GR), KC_PSCR, KC_RCTL, KC_PGUP,KC_UP,  KC_PGDN,
                                                                                                                             KC_LEFT,KC_DOWN,KC_RGHT,
                                                        _______, _______, _______
    ),
    [_ALT_GR] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,RESET,_______, TO(_OPTS),_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, OSL(_lCEDIL),  _______,
        _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    OSL(_lUML), _______,   _______,
        _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    OSL(_lACUTE), OSL(_lCIRC), OSL(_lAGRAVE),
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        UC_RMOD,_______,UC_MOD,
                                                        _______, _______, _______
    ),
    [_lACUTE] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(e_ACUTE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,   _______,
        _______,       X(a_ACUTE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        OSL(_UACUTE),   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_UACUTE] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(E_ACUTE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,   _______,
        _______,       X(A_ACUTE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                         _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_lAGRAVE] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(e_GRAVE),    _______,    _______,    _______,    X(u_GRAVE),    _______,    _______,    _______,    _______, _______,   _______,
        _______,       X(a_GRAVE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        OSL(_UAGRAVE),   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                         _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_UAGRAVE] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(E_GRAVE),    _______,    _______,    _______,    X(U_GRAVE),    _______,    _______,    _______,    _______, _______,   _______,
        _______,       X(A_GRAVE),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_lUML] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(e_UML),    _______,    _______,    _______,    X(u_UML),    X(i_UML),    _______,    _______,    _______, _______,   _______,
        _______,       X(a_UML),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        OSL(_UUML),   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_UUML] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(E_UML),    _______,    _______,    _______,    X(U_UML),    X(I_UML),    _______,    _______,    _______, _______,   _______,
        _______,       X(A_UML),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_lCIRC] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(e_CIRC),    _______,    _______,    _______,    X(u_CIRC),    X(i_CIRC),    X(o_CIRC),    _______,    _______, _______,   _______,
        _______,       X(a_CIRC),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        OSL(_UCIRC),   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_UCIRC] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    X(E_CIRC),    _______,    _______,    _______,    X(U_CIRC),    X(I_CIRC),    X(O_CIRC),    _______,    _______, _______,   _______,
        _______,       X(A_CIRC),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_lCEDIL] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,   _______,
        _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        OSL(_UCEDIL),   _______, _______,    _______,    X(c_CEDIL),    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_UCEDIL] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,   _______,
        _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
        _______,   _______, _______,    _______,    X(C_CEDIL),    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_EMOJI] = LAYOUT(
        _______,    _______, _______, _______, _______,  _______, _______, _______,  _______,  _______, _______, _______, _______,_______,_______, _______,_______,
        _______,  X(emoji_p1),    X(emoji_troll),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    _______,    _______,    X(emoji_sweat),    _______,    X(emoji_scream),    _______,    X(emoji_shrug),    X(emoji_party),    _______, _______,   _______,
        _______,       _______,    X(emoji_smile),    _______,    X(emoji_muscle),    _______,    X(emoji_heart),    _______,    _______,    X(emoji_cry),    _______, _______, _______,
        _______,   _______, _______,    _______,    X(emoji_champagne),    _______,    X(emoji_beer),    _______,    X(emoji_thanks),    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,X(emoji_up),  _______,
                                                                                                                        _______,_______,_______,
                                                        _______, _______, _______
    ),
    [_OPTS] = LAYOUT(
        TO(_BL),    KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, _______,_______, _______,_______,
        _______,  UC_M_WC,    UC_M_LN,    UC_M_MA,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,
        _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MS_UP,    _______,    _______,    _______, _______,   _______,
        _______,       _______,    _______,    _______,    _______,    _______,    _______,    KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,    _______, _______, _______,
        _______,   _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
        _______, _______,   _______, _______, _______,                                      _______, _______, _______, _______,_______,  _______,
                                                                                                                        _______,_______,_______,
                                                        KC_BTN1, KC_BTN3, KC_BTN2
    ),
};
