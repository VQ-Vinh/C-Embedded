/*

*/
#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint8_t start;
        uint8_t command;
        uint16_t data;
        uint8_t crc;
        uint8_t end;
    } fields;
    uint8_t raw[6];
} Packet;

// Fill struct fields and print raw bytes
void build_and_print_packet(uint8_t s, uint8_t c, uint16_t d, uint8_t crc, uint8_t e) {
    Packet pk;
    pk.fields.start = s;
    pk.fields.command = c;
    pk.fields.data = d;
    pk.fields.crc = crc;
    pk.fields.end = e;
    for (uint8_t i = 0; i < 6; i++) {
        printf("%d ", pk.raw[i]);
    }
}

int main() {
    uint8_t s, c, crc, e;
    uint16_t d;
    scanf("%hhu %hhu %hu %hhu %hhu", &s, &c, &d, &crc, &e);
    build_and_print_packet(s, c, d, crc, e);
    return 0;
}