#pragma once

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

// Preneseno sa gugutka (googootkah.h), pozicije prevedene na zilpzalp.

/* Layers */
#define DEF 0
#define BAS 0
#define NUM 1
#define NAV 2
#define SYM 3
#define BT  4
#define LAT 5

/* Timing */
#define TAPPING_TERM 200
#define QUICK_TAP_MS 0

//     __________________________  __________________________
//    /     0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7    \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
//    \    18  | 19  | 20    /        \    21 |  22 |  23   /
//          \    24  | 25  /            \  26 |  27    /
//           --------------              --------------

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

#define COMBO(NAME, BINDINGS, KEYPOS, TIMEOUT, LAYERS) \
    combo_##NAME { \
        timeout-ms = <TIMEOUT>; \
        bindings = <BINDINGS>; \
        key-positions = <KEYPOS>; \
        layers = <LAYERS>; \
        slow-release; \
    };

#define DEFAULT_TIME 64

/ {
    combos {
        compatible = "zmk,combos";

        COMBO(z,     &kp Y,     4  5, DEFAULT_TIME, BAS)   // Z + U
        COMBO(q,     &kp Q,     0  1, DEFAULT_TIME, BAS)   // W + E
        COMBO(tab,   &kp TAB,   9 10, DEFAULT_TIME, BAS)   // S + D
        COMBO(esc,   &kp ESC,  19 20, DEFAULT_TIME, BAS)   // V + B
        COMBO(enter, &kp ENTER, 21 23, DEFAULT_TIME, BAS)  // M + .
        COMBO(qmark, &kp QMARK, 22 23, DEFAULT_TIME, BAS)  // , + .
    };

    behaviors {
        hl: homerow_left {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            tapping-term-ms = <TAPPING_TERM>;
            quick-tap-ms = <QUICK_TAP_MS>;
            flavor = "balanced";
            bindings = <&kp>, <&kp>;
            // desna ruka + palcevi
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
            hold-trigger-on-release;
        };

        hr: homerow_right {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            tapping-term-ms = <TAPPING_TERM>;
            quick-tap-ms = <QUICK_TAP_MS>;
            flavor = "balanced";
            bindings = <&kp>, <&kp>;
            // leva ruka + palcevi
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
            hold-trigger-on-release;
        };

        my_lt: my_layer_tap {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            tapping-term-ms = <200>;
            quick-tap-ms = <0>;
            flavor = "balanced";
            bindings = <&mo>, <&kp>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };

        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMICOLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
