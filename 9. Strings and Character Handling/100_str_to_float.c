/*
You are given a null-terminated string representing a floating-point number, which may contain:
    An optional sign (+ or -)
    A decimal point
    Only valid digits and one dot
Your task is to convert this string to its floating-point value (float), 
without using standard library functions like atof() or strtof().

Do not handle scientific notation (e.g., "1.2e5").

Example-1
    Input: "123.45"
    Output: 123.45

Example-2
    Input: "-0.75"
    Output: -0.75

Example-3
    Input: "100"
    Output: 100.00

Example-4
    Input: "+9.99"
    Output: 9.99
*/
#include <stdio.h>
#include <stdint.h>

float custom_atof(const char *str) {
    float result = 0.0f;
    float fraction = 0.0f;
    float divisor = 10.0f;
    int sign = 1;
    uint8_t i = 0;
    uint8_t in_fraction = 0;

    // Handle optional sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] == '.') {
            in_fraction = 1;
            i++;
            continue;
        }

        if (str[i] >= '0' && str[i] <= '9') {
            int digit = str[i] - '0';
            if (!in_fraction) {
                result = result * 10.0f + digit;
            } else {
                fraction += digit / divisor;
                divisor *= 10.0f;
            }
        } else {
            break;  // Stop if non-digit, non-dot char
        }
        i++;
    }

    return sign * (result + fraction);
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

    float value = custom_atof(str);
    printf("%.2f", value);
    return 0;
}