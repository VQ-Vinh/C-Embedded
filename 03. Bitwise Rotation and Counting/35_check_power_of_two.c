/*
Write a function to check if a given positive integer is a power of 2. 
Do not use loops, multiplication, division, or library functions.
You must solve it using bitwise logic only.

Example-1
    Input:  n = 8  
    Output: YES
Example-2
    Input:  n = 7  
    Output: NO
*/
#include <stdio.h>
#include <stdint.h>

const char* is_power_of_two(uint32_t n) {
    if (n != 0 && (n & (n - 1)) == 0) return "YES";
    return "NO";
}

int main() {
    uint32_t n;
    scanf("%u", &n);

    const char* result = is_power_of_two(n);
    printf("%s", result);
    return 0;
}