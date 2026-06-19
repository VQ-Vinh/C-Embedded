#include <stdio.h>

void reverse_string(char *str) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    // Remove newline
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    reverse_string(str);
    printf("%s", str);
    return 0;
}