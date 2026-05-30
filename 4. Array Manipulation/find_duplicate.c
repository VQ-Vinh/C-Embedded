/*
You are given an array of n integers. Each number is guaranteed to be in the range [0, n-1], and exactly one number is repeated once. 
Write a program to find and print the repeated number.
You cannot modify the array and cannot use extra memory (O(1) space).

Example-1
    Input: n = 5 , arr = [0 1 2 3 2]
    Output: 2
*/

#include <stdio.h>

int find_duplicate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {    
            if (arr[i] == arr[j]) return arr[i];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = find_duplicate(arr, n);
    printf("%d", result);
    return 0;
}