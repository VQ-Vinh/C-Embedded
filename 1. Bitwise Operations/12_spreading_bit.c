/*
In some protocols or hardware applications (e.g. graphic rendering, signal encoding), bit spreading or interleaving is used to insert 0s between the bits of a value for purposes like data alignment or transmission.

You are given an 8-bit number, and your task is to:
    Spread the bits such that each bit is followed by a 0
    The result will be a 16-bit number where each original bit occupies even positions (0, 2, 4…)
    All odd positions are 0s

Example Logic
    Original (8-bit):                          b7 b6 b5 b4 b3 b2 b1 b0
    Spreading result (16-bit): 0 b7 0 b6 0 b5 0 b4 0 b3 0 b2 0 b1 0 b0
*/
#include <stdio.h>
#include <stdint.h>

uint16_t spread_bits(uint8_t val) {
    uint16_t result = 0; 
    for (uint8_t i = 0; i <= 7; i++) {
        if (val & (1 << i)) {
            result |= (1 << i*2);
        }
    }
    return result;
}

int main() {
    uint8_t val;
    scanf("%hhu", &val);

    uint16_t result = spread_bits(val);
    printf("%u", result);
    return 0;
}