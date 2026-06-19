#include <stdio.h>
#include <stdint.h>

void classify_chars(const char *str, uint8_t *alpha, uint8_t *digit, uint8_t *symbol) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z')) (*alpha)++;
        else if ('0' <= str[i] && str[i] <= '9') (*digit)++;
        else if (' ' == str[i]) continue;
        else (*symbol)++;
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

    uint8_t alpha = 0, digit = 0, symbol = 0;
    classify_chars(str, &alpha, &digit, &symbol);
    printf("Alphabets = %u\nDigits = %u\nSymbols = %u", alpha, digit, symbol);
    return 0;
}