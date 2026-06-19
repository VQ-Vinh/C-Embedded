/*
You are given an array of integers and its size n.
Using only pointer arithmetic:
    Traverse the array
    Find and print the maximum element in the array.
❌ Do not use array indexing like arr[I].
✅ Only use pointer movements and dereferencing.

Example-1
    Input: n = 5, arr = [10 25 5 30 15]
    Output: 30

*/

#include <stdio.h>

int find_max_element(int *ptr, int n) {
    int max = *ptr;
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
    return max;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = find_max_element(arr, n);
    printf("%d", result);

    return 0;
}