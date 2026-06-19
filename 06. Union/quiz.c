#include <stdio.h>
#include <stdint.h>

int main() {
    union { float f; uint32_t u; } data;
    data.f = 3.14f;
    data.u = 0x00000001;
    printf("%f", data.f);
}