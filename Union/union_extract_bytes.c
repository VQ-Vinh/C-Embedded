/*
Your task is to:
    Use a union that overlays a uint32_t value with a 4-byte uint8_t array
    Read a 32-bit unsigned integer input
    Print its 4 individual bytes in little-endian order (i.e., LSB first)
    Assume the program runs on a little-endian machine.
Use only union access, no bit masking or shifts.

Example-1
    Input: 0x05 → 00000101
    Output: 1
    (enable=1, mode=0, priority=1, reserved=0)

Example-2
    Input: 0x0F → 00001111
    Output: 0
    (priority=3, reserved=0)

Example-3
    Input: 0x95 → 10010101
    Output: 0
    (reserved ≠ 0)
*/
#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t value;
    uint8_t bytes[4];
} Register;

// Write logic here to extract bytes using union
void print_bytes(uint32_t input) {
    
}

int main() {
    uint32_t num;
    scanf("%u", &num);
    print_bytes(num);
    return 0;
}