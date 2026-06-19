/*
You are given an array of size n and an integer k. Rotate the array left by k positions, in-place (without using any extra array).
This means the elements that go beyond the first k positions should wrap around to the end.

Example-1
    Input: n = 5, k = 2, arr = [1 2 3 4 5]
    Output:[3  4  5  1  2]
Example-2
    Input: n = 4, k = 1, arr = [10 20 30 40]
    Output:[20  30  40  10]
*/

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

void rotate_left(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;
    reverse(arr, 0, k - 1);     // Dao k phan dau
    reverse(arr, k, n - 1);     // Dao n - k phan cuoi
    reverse(arr, 0, n - 1);     // Dao toan bo mang
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[100];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Rotate the array
    rotate_left(arr, n, k);

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
        	printf(" ");
        }
    }

    return 0;
}