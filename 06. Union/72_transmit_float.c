#include <stdio.h>
#include <stdint.h>

typedef union {
    float f;
    uint8_t bytes[4];
} FloatPacket;

int main() {
    float input;
    scanf("%f", &input);

    // Fill union and print 4 bytes
    FloatPacket p;
    p.f = input;
    for (uint8_t i = 0; i < 4; i++) {
        printf("Byte %u: %u\n", i, p.bytes[i]);
    }
    return 0;
}