#include <stdio.h>
#include <stdint.h>

void remove_duplicates(char *str) {
    int n = 0; 
    while (str[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j]) {
                for (int k = j; k < n; k++) {
                    str[k] = str[k + 1];
                }
                n--;
                j--;
            }
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

    remove_duplicates(str);
    printf("%s", str);
    return 0;
}