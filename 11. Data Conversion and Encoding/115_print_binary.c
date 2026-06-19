#include <stdio.h>
#include <stdint.h>

void print_binary(uint16_t val) {
    int8_t bits = (val <= 255) ? 7 : 15;
    for (int8_t i = bits; i >= 0; i--)
    {
        printf("%d", (val >> i) & 1);
    }
}

int main() {
    uint16_t val;
    scanf("%hu", &val);
    print_binary(val);
    return 0;
}