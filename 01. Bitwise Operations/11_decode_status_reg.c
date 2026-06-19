#include <stdio.h>
#include <stdint.h>

void decode_status(uint8_t status_reg) {
    // Your logic here
    if (status_reg & (1 << 0)) printf("Power On\n");
    if (status_reg & (1 << 1)) printf("Error\n");
    if (status_reg & (1 << 2)) printf("Tx Ready\n");
    if (status_reg & (1 << 3)) printf("Rx Ready\n");
    if (status_reg & (1 << 4)) printf("Overheat\n");
    if (status_reg & (1 << 5)) printf("Undervoltage\n");
    if (status_reg & (1 << 6)) printf("Timeout\n");
    if (status_reg & (1 << 7)) printf("Reserved");
}

int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    decode_status(reg);
    return 0;
}