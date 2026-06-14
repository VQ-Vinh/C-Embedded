/*
You are given a struct with the following fields in order:
    char a
    int b
    short c
Your task is to:
    Declare a variable of this struct
    Compute the offset (in bytes) of each field from the base address of the struct (i.e., &s)
    Print:
        Offset of a
        Offset of b
        Offset of c
        Total size of the struct
 
Example Output
    Offset of a: 0  
    Offset of b: 4  
    Offset of c: 8  
    Size: 12
*/
#include <stdio.h>
#include <stddef.h>

typedef struct {
    char a;
    int b;
    short c;
} MyStruct;

void print_offsets() {
    printf("Offset of a: %lu\n", offsetof(MyStruct, a));
    printf("Offset of b: %lu\n", offsetof(MyStruct, b));
    printf("Offset of c: %lu\n", offsetof(MyStruct, c));
    printf("Size: %lu", sizeof(MyStruct));
}

int main() {
    print_offsets();
    return 0;
}