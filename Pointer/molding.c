#include <stdio.h>

int main() {
    int data[3] = {0x11223344, 0x55667788, 0xAABBCCDD};
    for (int i = 0; i < 3; i++) {
        printf("Địa chỉ mảng data:");
        printf("%p\n", data + i);
    }
    char *p = (char *)data;
    p += 5;
    printf("Địa chỉ p sau khi nhảy: %p\n", p);
    printf("0x%X", *(int *)p);
}

