/* Copyright 2020 QMK
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

#include "quantum.h"

#define ___ KC_NO

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments as on the physical keyboard
// The second converts the arguments into the 2-D scanned array

#define LAYOUT( \
    K71,  K64,K63,K03,K73,K7E,K78,K06,K66, K6E,K4E,K4D,K4B, K6D,K4C,K4F,K6F,     \
    K61, K41, K44, K43, K45, K65, K62, K42, K48, K46, K47, K67, K68, K0E,        \
    K01,   K51, K54, K53, K55, K05, K02, K52, K58, K56, K57, K07, K08,  K2E,     \
    K04,    K31, K34, K33, K35, K75, K72, K32, K38, K36, K37, K77, K27,          \
    K00,  K74, K21, K24, K23, K25, K15, K12, K22, K28, K26, K17, K20,            \
    K3C, K69,  K0B, K7A, K1E,                     K1A, K3F, K29, K2F, K7C,K1F,   \
                                                                 K1C, K1D,K1B,    \
                                                                               K1G, K1H, K1I \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   KC_NO, KC_NO, K0B,   KC_NO, KC_NO, K0E,   KC_NO, KC_NO, KC_NO, KC_NO}, \
    { KC_NO, KC_NO, K12,   KC_NO, KC_NO, K15,   KC_NO, K17,   KC_NO, KC_NO, K1A,   K1B,   K1C,   K1D,   K1E,   K1F,   KC_NO, KC_NO, KC_NO  }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   KC_NO, KC_NO, KC_NO, KC_NO, K2E,   K2F,   KC_NO, KC_NO, KC_NO  }, \
    { KC_NO, K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   KC_NO, KC_NO, KC_NO, K3C,   KC_NO, KC_NO, K3F,   KC_NO, KC_NO, KC_NO  }, \
    { KC_NO, K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48,   KC_NO, KC_NO, K4B,   K4C,   K4D,   K4E,   K4F,   KC_NO, KC_NO, KC_NO  }, \
    { KC_NO, K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, K61,   K62,   K63,   K64,   K65,   K66,   K67,   K68,   K69,   KC_NO, KC_NO, KC_NO, K6D,   K6E,   K6F,   KC_NO, KC_NO, KC_NO  }, \
    { KC_NO, K71,   K72,   K73,   K74,   K75,   KC_NO, K77,   K78,   KC_NO, K7A,   KC_NO, K7C,   KC_NO, K7E,   KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K1G, K1H, K1I } \
}
