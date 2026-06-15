/*
You are given two null-terminated strings.
Your task is to:
    Compare them character by character using ASCII values
    Return:
        0 if all characters are the same and both strings end at the same time
        If mismatched: ASCII difference of the first mismatched characters. 
        I.e. positive value if the first non-matching character in string a is greater than that in string b or negative value (vice-versa)
Do not use built-in functions like strcmp().
*/
#include <stdio.h>

int custom_strcmp(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        int ans = a[i] - b[i];
        if (ans != 0) return ans;
        i++;
    }
    return 0;
}

int main() {
    char a[101], b[101];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    // Remove newline
    int i = 0;
    while (a[i]) {
        if (a[i] == '\n') { a[i] = '\0'; break; }
        i++;
    }
    i = 0;
    while (b[i]) {
        if (b[i] == '\n') { b[i] = '\0'; break; }
        i++;
    }

    printf("%d", custom_strcmp(a, b));
    return 0;
}