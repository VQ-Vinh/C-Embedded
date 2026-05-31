/*
In embedded systems, registers are often configured by setting specific bits. To make the code cleaner and reusable, firmware developers use macros to set fields in a register.

You are given a 16-bit control register layout:
    Field	    Bits	Position (LSB-first)
    ENABLE	    1	    Bit 0
    MODE	    2	    Bits 1–2
    SPEED	    3	    Bits 3–5
    RESERVED	2	    Bits 6–7 (must be 0)

Your task is to:
    Write macros to:
        Set the ENABLE bit
        Set the MODE field
        Set the SPEED field
    Read ENABLE, MODE, SPEED from input
    Use the macros to pack a final 16-bit register value
    RESERVED bits (6–7) must be left 0

Example-1:
    Input: enable = 1, mode = 2, speed = 4
    Output: 37
    (Binary: 0000 0000 0010 0101)
Example-2:
    Input: enable = 0, mode = 1, speed = 3
    Output: 26
    (Binary: 0000 0000 0001 1010)
*/

#include <stdio.h>
#include <stdint.h>

#define ENABLE_POS 0
#define MODE_POS 1
#define SPEED_POS 3

#define SET_ENABLE(v) ((uint16_t)(v) << ENABLE_POS)
#define SET_MODE(v) ((uint16_t)(v) << MODE_POS)
#define SET_SPEED(v) ((uint16_t)(v) << SPEED_POS)

uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t reg = 0;
    return reg = (SET_ENABLE(enable) | SET_MODE(mode) | SET_SPEED(speed));
}

int main() {
    unsigned int e, m, s;
    scanf("%hhu %hhu %hhu", &e, &m, &s);
    uint8_t enable = (uint8_t)e;
    uint8_t mode = (uint8_t)m;
    uint8_t speed = (uint8_t)s;
    
    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);
    return 0;
}