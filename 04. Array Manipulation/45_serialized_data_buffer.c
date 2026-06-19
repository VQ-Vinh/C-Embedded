/*
In firmware, you often need to assemble a communication packet as a byte array before sending it over UART/SPI.

You are given the following fields:
    Field	    Size	    Description
    Start	    1 byte	    Always 0xA5
    Command	    1 byte	    User input
    Value	    2 byte	    16-bit data (uint16_t)
    Status	    1 byte	    Flags (0 or 1)
    Checksum	4 byte	    32-bit checksum (uint32_t)
    End	        1 byte	    Always 0x5A

Your task is to:
    Fill a uint8_t buffer[10] with the data in this order
    Use pointer casting or byte manipulation
    Print the entire buffer contents as space-separated integers
*/

#include <stdio.h>
#include <stdint.h>

void build_packet(uint8_t command, uint16_t value, uint8_t status, uint32_t checksum) {
    uint8_t buffer[10];
    // Start
    buffer[0] = 0xA5;
    // Command
    buffer[1] = command;
    // Value
    buffer[2] = value & 0xFF;
    buffer[3] = (value >> 8) & 0xFF;
    // Status
    buffer[4] = status;
    // Checksum
    buffer[5] = checksum & 0xFF;
    buffer[6] = (checksum >> 8) & 0xFF;
    buffer[7] = (checksum >> 16) & 0xFF;
    buffer[8] = (checksum >> 24) & 0xFF;
    // End
    buffer[9] = 0x5A;
    // Print
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }

}

int main() {
    uint8_t cmd, status;
    uint16_t val;
    uint32_t crc;

    scanf("%hhu %hu %hhu %u", &cmd, &val, &status, &crc);
    build_packet(cmd, val, status, crc);
    return 0;
}