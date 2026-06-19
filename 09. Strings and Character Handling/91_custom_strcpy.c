#include <stdio.h>

void custom_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
}

int main() {
    char src[101];
    char dest[101];
    fgets(src, sizeof(src), stdin);

    // Remove newline
    int i = 0;
    while (src[i] != '\0') {
        if (src[i] == '\n') {
            src[i] = '\0';
            break;
        }
        i++;
    }

    custom_strcpy(dest, src);
    printf("%s", dest);
    return 0;
}