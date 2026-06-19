/*
You are working with an 8-bit control register. Write a function to set the bit at a given position without affecting other bits.

Use 0-based indexing for bit positions (0 = LSB, 7 = MSB).

Example 1
    Input: reg = 0b00000101, pos = 1
    Output: 0b00000111

Example 2
    Input: reg = 0b00001000, pos = 0
    Output: 0b00001001
*/
#include <stdio.h>
#include <stdint.h>

uint8_t set_bit(uint8_t reg, uint8_t pos) {
    return reg | (1 << pos);
}

int main() {
    unsigned int r,p;
    uint8_t reg, pos;
    scanf("%hhu %hhu", &r, &p);
    reg = (uint8_t)r;
    pos = (uint8_t)p;
    uint8_t result = set_bit(reg, pos);
    printf("%u", result);
    return 0;
}
