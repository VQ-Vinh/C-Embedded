#include <stdio.h>
#include <stdint.h>

void find_top_3(uint8_t *arr, uint8_t n) {
    uint8_t max[3] = {0, 0, 0}; // max1, max2, max3

    for (uint8_t i = 0; i < n; i++) {
        if (arr[i] > max[0]) {
            max[2] = max[1];
            max[1] = max[0];
            max[0] = arr[i];
        } else if (arr[i] > max[1]) {
            max[2] = max[1];
            max[1] = arr[i];
        } else if (arr[i] > max[2]) {
            max[2] = arr[i];
        }
    }
    
    uint8_t limit = (n < 3) ? n : 3;
    for (uint8_t i = 0; i < limit; i++) {
        printf("%hhu ", max[i]);
    }
} 

int main() {
    uint8_t n;
    scanf("%hhu", &n);
    uint8_t arr[100];

    for (uint8_t i = 0; i < n; i++) {
        scanf("%hhu", &arr[i]);
    }

    find_top_3(arr, n);
    return 0;
}