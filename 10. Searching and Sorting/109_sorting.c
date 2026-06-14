#include <stdio.h>
#include <stdint.h>

void bubble_sort(uint8_t *arr, uint8_t n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
} 

int main() {
    uint8_t n;
    scanf("%hhu", &n);
    uint8_t arr[100];

    for (uint8_t i = 0; i < n; i++) {
        scanf("%hhu", &arr[i]);
    }

    bubble_sort(arr, n);

    for (uint8_t i = 0; i < n; i++) {
        printf("%hhu", arr[i]);
        if(i < n-1){
            printf(" ");
        }
    }

    return 0;
}