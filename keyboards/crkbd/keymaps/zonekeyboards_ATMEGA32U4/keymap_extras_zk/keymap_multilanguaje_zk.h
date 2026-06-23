#if defined(LANG_SPANISH)
    // =================================================================
    // QMK DICTIONARY: SPANISH SPAIN (BY CATEGORIES)
    // =================================================================

    // --- 1. OPENING AND CLOSING ---
    #define ZK_LPRN LSFT(KC_8)     // ( (Open parenthesis)
    #define ZK_RPRN LSFT(KC_9)     // ) (Close parenthesis)
    #define ZK_LBRC RALT(KC_LBRC)  // [ (Open bracket - AltGr + `)
    #define ZK_RBRC RALT(KC_RBRC)  // ] (Close bracket - AltGr + +)
    #define ZK_LCBR RALT(KC_QUOT)  // { (Open brace - AltGr + ´)
    #define ZK_RCBR RALT(KC_NUHS)  // } (Close brace - AltGr + ç)

    // --- 2. PUNCTUATION ---
    #define ZK_IQUE LSFT(KC_EQL)   // ¿ (Open question - Shift + ¡)
    #define ZK_QUES LSFT(KC_MINS)  // ? (Close question - Shift + ')
    #define ZK_IEXC KC_EQL         // ¡ (Open exclamation)
    #define ZK_EXLM LSFT(KC_1)     // ! (Close exclamation)
    #define ZK_COMM KC_COMM        // , (Comma)
    #define ZK_DOT  KC_DOT         // . (Period / Dot)
    #define ZK_SCLN LSFT(KC_COMM)  // ; (Semicolon)
    #define ZK_COLN LSFT(KC_DOT)   // : (Colon)
    #define ZK_QUOT KC_MINS        // ' (Single quote / Apostrophe)
    #define ZK_DQUO LSFT(KC_2)     // " (Double quotes)

    // --- 3. MATHEMATICS ---
    #define ZK_PLUS KC_RBRC        // + (Addition / Plus)
    #define ZK_MINS KC_SLSH        // - (Subtraction / Minus / Hyphen)
    #define ZK_ASTR LSFT(KC_RBRC)  // * (Asterisk / Multiplication - Shift + +)
    #define ZK_SLASH LSFT(KC_7)    // / (Slash / Division)
    #define ZK_EQL  LSFT(KC_0)     // = (Equal sign)
    #define ZK_PERC LSFT(KC_5)     // % (Percentage)
    #define ZK_LABK KC_NUBS        // < (Less than)
    #define ZK_RABK LSFT(KC_NUBS)  // > (Greater than)

    // --- 4. SPECIAL SYMBOLS ---
    #define ZK_AT   RALT(KC_2)     // @ (At sign - AltGr + 2)
    #define ZK_HASH RALT(KC_3)     // # (Hash / Pound - AltGr + 3)
    #define ZK_DLR  LSFT(KC_4)     // $ (Dollar sign)
    #define ZK_AMPR LSFT(KC_6)     // & (Ampersand)
    #define ZK_PIPE RALT(KC_1)     // | (Pipe / Vertical bar - AltGr + 1)
    #define ZK_BSLS RALT(KC_GRV)   // \ (Backslash - AltGr + º)
    #define ZK_NOT  RALT(KC_6)     // ¬ (Logical negation - AltGr + 6)
    #define ZK_DEG  KC_GRV         // º (Masculine ordinal / often used as Degree sign)
    #define ZK_UNDS LSFT(KC_SLSH)  // _ (Underscore - Shift + -)

    // --- 5. ACCENTS AND SPECIFIC CHARACTERS ---
    #define ZK_NTIL KC_SCLN        // ñ (For capital Ñ use Shift + ZK_NTIL)
    #define ZK_ACUT KC_QUOT        // ´ (Acute accent)
    #define ZK_DIAE LSFT(KC_QUOT)  // ¨ (Diaeresis - Shift + ´)
    #define ZK_TILD RALT(KC_4)     // ~ (Tilde - AltGr + 4)
    #define ZK_CIRC LSFT(KC_LBRC)  // ^ (Circumflex accent - Shift + `)

    // --- 6. ACTIONS ---
    #define ZK_DESKL C(G(KC_LEFT)) // Desktop Left
    #define ZK_DESKR C(G(KC_RGHT)) // Desktop Right
#elif defined(LANG_LATAM)
    // =================================================================
    // QMK DICTIONARY: SPANISH LATIN AMERICA (BY CATEGORIES)
    // =================================================================

    // --- 1. OPENING AND CLOSING ---
    #define ZK_LPRN LSFT(KC_8)     // ( (Open parenthesis)
    #define ZK_RPRN LSFT(KC_9)     // ) (Close parenthesis)
    #define ZK_LBRC LSFT(KC_QUOT)  // [ (Open bracket)
    #define ZK_RBRC LSFT(KC_NUHS)  // ] (Close bracket)
    #define ZK_LCBR KC_QUOT        // { (Open brace)
    #define ZK_RCBR KC_NUHS        // } (Close brace)

    // --- 2. PUNCTUATION ---
    #define ZK_IQUE KC_EQL         // ¿ (Open question)
    #define ZK_QUES LSFT(KC_MINS)  // ? (Close question)
    #define ZK_IEXC LSFT(KC_EQL)   // ¡ (Open exclamation)
    #define ZK_EXLM LSFT(KC_1)     // ! (Close exclamation)
    #define ZK_COMM KC_COMM        // , (Comma)
    #define ZK_DOT  KC_DOT         // . (Period / Dot)
    #define ZK_SCLN LSFT(KC_COMM)  // ; (Semicolon)
    #define ZK_COLN LSFT(KC_DOT)   // : (Colon)
    #define ZK_QUOT KC_MINS        // ' (Single quote / Apostrophe)
    #define ZK_DQUO LSFT(KC_2)     // " (Double quotes)

    // --- 3. MATHEMATICS ---
    #define ZK_PLUS KC_PPLS        // + (Addition / Plus)
    #define ZK_MINS KC_PMNS        // - (Subtraction / Minus / Hyphen)
    #define ZK_ASTR KC_PAST        // * (Asterisk / Multiplication)
    #define ZK_SLASH LSFT(KC_7)    // / (Slash / Division)
    #define ZK_EQL  LSFT(KC_0)     // = (Equal sign)
    #define ZK_PERC LSFT(KC_5)     // % (Percentage)
    #define ZK_LABK KC_NUBS        // < (Less than)
    #define ZK_RABK LSFT(KC_NUBS)  // > (Greater than)

    // --- 4. SPECIAL SYMBOLS ---
    #define ZK_AT   RALT(KC_Q)     // @ (At sign)
    #define ZK_HASH LSFT(KC_3)     // # (Hash / Pound)
    #define ZK_DLR  LSFT(KC_4)     // $ (Dollar sign)
    #define ZK_AMPR LSFT(KC_6)     // & (Ampersand)
    #define ZK_PIPE KC_GRV         // | (Pipe / Vertical bar)
    #define ZK_BSLS RALT(KC_MINS)  // \ (Backslash)
    #define ZK_NOT  RALT(KC_GRV)   // ¬ (Logical negation)
    #define ZK_DEG  LSFT(KC_GRV)   // ° (Degree sign)
    #define ZK_UNDS LSFT(KC_SLSH)  // _ (Underscore)

    // --- 5. ACCENTS AND SPECIFIC CHARACTERS ---
    #define ZK_NTIL KC_SCLN        // ñ (For capital Ñ use Shift + ZK_NTIL / LA_NTIL)
    #define ZK_ACUT KC_LBRC        // ´ (Acute accent)
    #define ZK_DIAE LSFT(KC_LBRC)  // ¨ (Diaeresis)
    #define ZK_TILD RALT(KC_RBRC)  // ~ (Tilde)
    #define ZK_CIRC RALT(KC_QUOT)  // ^ (Circumflex accent)

    // --- 6. ACTIONS ---
    #define ZK_DESKL C(G(KC_LEFT))
    #define ZK_DESKR C(G(KC_LEFT))

// =================================================================
#else
    // =================================================================
    // QMK DICTIONARY: ENGLISH US QWERTY (BY CATEGORIES)
    // =================================================================

    // --- 1. OPENING AND CLOSING ---
    #define ZK_LPRN LSFT(KC_9)           // ( (Open parenthesis)
    #define ZK_RPRN LSFT(KC_0)           // ) (Close parenthesis)
    #define ZK_LBRC KC_LBRC              // [ (Open bracket)
    #define ZK_RBRC KC_RBRC              // ] (Close bracket)
    #define ZK_LCBR LSFT(KC_LBRC)        // { (Open brace)
    #define ZK_RCBR LSFT(KC_RBRC)        // } (Close brace)
      
    // --- 2. PUNCTUATION ---      
    #define ZK_IQUE KC_NO                // ¿ (Not natively available on US layout)
    #define ZK_QUES LSFT(KC_SLSH)        // ? (Close question)
    #define ZK_IEXC KC_NO                // ¡ (Not natively available on US layout)
    #define ZK_EXLM LSFT(KC_1)           // ! (Close exclamation)
    #define ZK_COMM KC_COMM              // , (Comma)
    #define ZK_DOT  KC_DOT               // . (Period / Dot)
    #define ZK_SCLN KC_SCLN              // ; (Semicolon)
    #define ZK_COLN LSFT(KC_SCLN)        // : (Colon)
    #define ZK_QUOT KC_QUOT              // ' (Single quote / Apostrophe)
    #define ZK_DQUO LSFT(KC_QUOT)        // " (Double quotes)
      
    // --- 3. MATHEMATICS ---      
    #define ZK_PLUS LSFT(KC_EQL)         // + (Addition / Plus)
    #define ZK_MINS KC_MINS              // - (Subtraction / Minus / Hyphen)
    #define ZK_ASTR LSFT(KC_8)           // * (Asterisk / Multiplication)
    #define ZK_SLASH KC_SLSH             // / (Slash / Division)
    #define ZK_EQL  KC_EQL               // = (Equal sign)
    #define ZK_PERC LSFT(KC_5)           // % (Percentage)
    #define ZK_LABK LSFT(KC_COMM)        // < (Less than)
    #define ZK_RABK LSFT(KC_DOT)         // > (Greater than)
      
    // --- 4. SPECIAL SYMBOLS ---      
    #define ZK_AT   LSFT(KC_2)           // @ (At sign)
    #define ZK_HASH LSFT(KC_3)           // # (Hash / Pound)
    #define ZK_DLR  LSFT(KC_4)           // $ (Dollar sign)
    #define ZK_AMPR LSFT(KC_7)           // & (Ampersand)
    #define ZK_PIPE LSFT(KC_BSLS)        // | (Pipe / Vertical bar)
    #define ZK_BSLS KC_BSLS              // \ (Backslash)
    #define ZK_NOT  RALT(KC_TILD)        // ¬ (Not natively available on US layout)
    #define ZK_DEG  RALT(LSFT(KC_SCLN))  // ° (Not natively available on US layout)
    #define ZK_UNDS LSFT(KC_MINS)  // _ (Underscore)

    // --- 5. ACCENTS AND SPECIFIC CHARACTERS ---
    #define ZK_NTIL RALT(KC_N)           // ñ (Not natively available on US layout)
    #define ZK_ACUT KC_QUOT              // ´ (Not natively available on US layout)
    #define ZK_DIAE LSFT(KC_QUOT)        // ¨ (Not natively available on US layout)
    #define ZK_TILD LSFT(KC_GRV)         // ~ (Tilde)
    #define ZK_CIRC LSFT(KC_6)           // ^ (Circumflex accent)

    // --- 6. ACTIONS ---
    #define ZK_DESKL C(G(KC_LEFT))       // Desktop Left
    #define ZK_DESKR C(G(KC_RGHT))       // Desktop Right (Fixed from KC_LEFT)
#endif

// =================================================================
// RGB ALIAS KEYCODE FOR KEYMAP
// =================================================================
#define RGB_TOG QK_RGB_MATRIX_TOGGLE
#define RGB_MOD QK_RGB_MATRIX_MODE_NEXT
#define RGB_HUI QK_RGB_MATRIX_HUE_UP
#define RGB_HUD QK_RGB_MATRIX_HUE_DOWN
#define RGB_SAI QK_RGB_MATRIX_SATURATION_UP
#define RGB_SAD QK_RGB_MATRIX_SATURATION_DOWN
#define RGB_VAI QK_RGB_MATRIX_VALUE_UP
#define RGB_VAD QK_RGB_MATRIX_VALUE_DOWN
#define RGB_SPI QK_RGB_MATRIX_SPEED_UP
#define RGB_SPD QK_RGB_MATRIX_SPEED_DOWN

