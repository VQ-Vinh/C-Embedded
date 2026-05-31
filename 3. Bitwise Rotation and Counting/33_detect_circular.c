/*
You are given a 16-bit register and a target pattern (also 16-bit). 
Check if the target pattern can be matched by any circular rotation of the register.

Example 1
    Input: reg = 0b1011 0000 0000 0000, target = 0b0000 0000 0000 1011  
    Output: 1 (matches after left rotation by 13)
Example 2 
    Input: reg = 0b1000 0000 0000 0001, target = 0b0000 0000 0000 1100  
    Output: 1
Example 3 
    Input: reg = 0b1111 1111 1111 1111, target = 0b1111 1111 1111 0111  
    Output: 0
*/

#include <stdio.h>
#include <stdint.h>

uint8_t is_circular_match(uint16_t reg, uint16_t target) {
    for (uint8_t i = 0; i < 16; i ++) {
        uint16_t reg_rot = (reg >> i) | (reg << (16 - i));
        if ( reg_rot & target != 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    uint16_t reg, target;
    scanf("%hu %hu", &reg, &target);
    printf("%hhu", is_circular_match(reg, target));
    return 0;
}