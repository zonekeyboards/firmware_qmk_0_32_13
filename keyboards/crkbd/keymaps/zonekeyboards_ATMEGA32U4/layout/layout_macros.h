#pragma once

#define LAYOUT_SPLIT( \
    L00, L01, L02, L03, L04, L05, \
    L10, L11, L12, L13, L14, L15, \
    L16, L17, L18, L19, L20, L21, \
    L22, L23, L24, \
    R00, R01, R02, R03, R04, R05, \
    R10, R11, R12, R13, R14, R15, \
    R16, R17, R18, R19, R20, R21, \
    R22, R23, R24 \
) \
LAYOUT_split_3x6_3( \
    L00, L01, L02, L03, L04, L05,               R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,               R10, R11, R12, R13, R14, R15, \
    L16, L17, L18, L19, L20, L21,               R16, R17, R18, R19, R20, R21, \
                        L22, L23, L24,     R22, R23, R24 \
)
