/*
You are given a block of memory (as an integer array) of size n.

Your task is to write a function that scans the memory using pointers and detects the first occurrence of three consecutive increasing integers 
— for example: [4, 5, 6] or [10, 11, 12].

Return the starting index of the first such pattern. If no such pattern is found, return -1.You must use pointer logic only, not array indexing.
*/
#include <stdio.h>

int find_pattern(int *mem, int n) {
    for (int i = 0; i < n - 2; i++) {
        if (*(mem + i) == *(mem + i + 1) - 1 &&
            *(mem + i) == *(mem + i + 2) - 2) {
                return i;
        }
    }
    return -1;

}

int main() {
    int n, arr[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int res = find_pattern(arr, n);
    printf("%d", res);

    return 0;
}