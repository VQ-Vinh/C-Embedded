/*
Write a C program to count the number of set bits (1s) in the binary representation of an integer N.

Input Format
    A single integer N.
Output Format
    Print the count of set bits.

Here are the examples for Count Set Bits in an Integer:
*/

#include <stdio.h>

int countSetBits(unsigned int n) {
    unsigned int cout = 0;
    while (n > 0) {
        if (n & 1 == 1) {
            cout++;
        }
        n >>= 1;
    }
    return cout;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", countSetBits(n));
    return 0;
}