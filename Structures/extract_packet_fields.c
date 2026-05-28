/*
You receive a 6-byte data packet from a peripheral interface (e.g., UART or I2C). The byte stream format is:

    Byte Index  Field	    Size
    0	        start	    1
    1	        command	    1
    2–3	        data	    2
    4	        crc	        1
    5	        end	        1
You are given the packet as an array: uint8_t buffer[6]. Your task is to extract and print each field as integer values
 
Example-1
    Input: 165 1 52 18 119 90
    Output:
    Start: 165
    Command: 1
    Data: 4660 (Littel Edian 00010010-00110100 (18-52))
    CRC: 119
    End: 90
 
Example-2
    Input: 170 255 255 0 254 85
    Output:
    Start: 170
    Command: 255
    Data: 255
    CRC: 254
    End: 85
*/
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t start;
    uint8_t command;
    uint16_t data;
    uint8_t crc;
    uint8_t end;
} __attribute__((packed)) Packet;

void print_packet_fields(uint8_t *buffer) {
    Packet *p = (Packet *)buffer;
    printf("Start: %hu\n", p->start);
    printf("Command: %hu\n", p->command);
    printf("Data: %hu\n", p->data);
    printf("CRC: %hu\n", p->crc);
    printf("End: %hu", p->end);
}

int main() {
    uint8_t buffer[6];
    for (int i = 0; i < 6; i++) {
        scanf("%hhu", &buffer[i]);
    }
    print_packet_fields(buffer);
   ; return 0;
}