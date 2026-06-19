/*
In embedded systems, communication between processors may require byte-order conversion. 
You are given a 32-bit unsigned integer stored in little-endian format.
Your task is to convert this value to big-endian by swapping its bytes, and print the result.
 
Example-1
    Input: 305419896
    Output: 2018915346
    (0x12345678 → 0x78563412)

Example-2
    Input: 1
    Output: 16777216
    (0x00000001 → 0x01000000)

Example-3
    Input: 0xAABBCCDD
    Output: 0xDDCCBBAA → 3721182122
*/
#include <stdio.h>
#include <stdint.h>

uint32_t convert_endian(uint32_t value) {
    return  ((value >> 24) & 0xFF) |
            ((value >> 8) & 0xFF00) |
            ((value << 8) & 0xFF0000) |
            ((value << 24) & 0xFF000000);
}

int main() {
    uint32_t val;
    scanf("%u", &val);
    printf("%u", convert_endian(val));
    return 0;
}