/*
You are given a memory block as an integer array of size n. 
Your task is to check if a segment of size k starting from the beginning of the array follows an alternating pattern — e.g., 1 0 1 0 ... or 0 1 0 1 ....

Return:
    1 if the segment follows an alternating pattern
    0 if not

You must use pointer arithmetic only, not array indexing.

Example-1
    Input: n = 6, k = 6, mem = [1, 0, 1, 0, 1, 0]
    Output: 1

Example-2
    Input: n = 6, k = 6, mem = [1, 1, 0, 1, 0, 1]
    Output: 0

Example-3
    Input: n = 5, k = 3, mem = [1 0 1 1 0]
    Output: 1
*/
#include <stdio.h>

int is_alternating_pattern(int *mem, int k) {
    int *p1 = mem; 
    int *p2 = mem + 2;
    for (int i = 0; i < k - 2; i++) {
        if (*p1 != *p2) {
            return 0; 
        }
        p1++;
        p2++;
    }
    return 1;
}

int main() {
    int n, k, arr[100];
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int res = is_alternating_pattern(arr, k);
    printf("%d", res);

    return 0;
}