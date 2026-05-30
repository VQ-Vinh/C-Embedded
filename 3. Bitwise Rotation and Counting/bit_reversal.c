/*
You are given an 8-bit unsigned integer. Your task is to:
    Reverse the order of its bits
    Print the resulting 8-bit value (in decimal)
You must not use any lookup table or standard library function. Use pure bitwise logic.

Example-1
    Input: val = 0b00011010
    Output: 0b01011000 → Decimal: 88
Example-2
    Input: val = 0b10110000
    Output: 0b00001101 → Decimal: 13
*/

#include <stdio.h>
#include <stdint.h>

uint8_t reverse_bits(uint8_t val) {
    uint8_t ans = 0;
    for (uint8_t i = 0; i < 8; i++) {
        ans |= ((val >> i) & 1) << (7 - i);
    }
    return ans;
}

int main() {
    uint8_t val;
    scanf("%hhu", &val);

    uint8_t result = reverse_bits(val);
    printf("%u", result);
    return 0;
}