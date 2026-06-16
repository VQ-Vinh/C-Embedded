#include <stdio.h>
#include <stdint.h>

void to_lowercase(char *str) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    // Remove newline
    uint8_t i = 0;
    while (str[i]) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    to_lowercase(str);
    printf("%s", str);
    return 0;
}