/*
You are given an array of integers and its size n.
Using only pointer arithmetic:
    Reverse the array elements in-place.
    Print the reversed array.
❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.

Input: n = 5, arr = [1 2 3 4 5]
Output: 5 4 3 2 1
*/

#include <stdio.h>

void reverse_array(int *ptr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + n - 1 - i);
        *(ptr + n - 1 - i) = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse_array(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
            printf(" ");
        }
    }

    return 0;
}