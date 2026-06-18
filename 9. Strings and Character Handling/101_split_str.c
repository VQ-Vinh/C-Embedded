#include <stdio.h>
#include <stdint.h>

void split_string(const char *str, char delimiter, char tokens[10][20], uint8_t *count) {
    uint8_t i = 0;
    *count = 0;
    uint8_t col = 0;
    while (str[i] != '\0')
    {
        if (str[i] != delimiter) {
            tokens[*count][col] = str[i];
            col++;
        } else {
            tokens[*count][col] = '\0';
            col = 0;
            (*count)++;
        }
        i++;
    }
    (*count)++;
    tokens[*count][col] = '\0';
}

int main() {
    char str[101];
    char delimiter;
    fgets(str, sizeof(str), stdin);
    scanf(" %c", &delimiter);

    // Remove newline
    uint8_t i = 0;
    while (str[i]) {
        if (str[i] == '\n') { str[i] = '\0'; break; }
        i++;
    }

    char tokens[10][20];
    uint8_t count = 0;

    split_string(str, delimiter, tokens, &count);

    for (uint8_t i = 0; i < count; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}