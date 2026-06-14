/*
Many embedded microcontrollers store ADC results in a packed format where a 12-bit ADC value 
and channel number are stored together in a 16-bit register.
You are given a 16-bit ADC register where:
    Bits 0–11 represent the ADC result (0–4095)
    Bits 12–15 represent the ADC channel (0–15)
Your task is to:
    1. Define a union that overlays:
        A raw 16-bit uint16_t adc_reg
        A struct with:
            adc_value (12 bits)
            channel (4 bits)
    2. Read adc_reg from input
    3. Extract and print:
        Channel number
        ADC result (0–4095)
 
Example-1
    Input: 0xC3F5
    Output:
    Channel: 12  
    ADC Value: 1013
 
Example-2
    Input: 0x10FF
    Output:
    Channel: 1  
    ADC Value: 255
*/
#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint16_t adc_value : 12;
        uint16_t channel   : 4;
    };
    uint16_t adc_reg;
} ADC_Result;

int main() {
    uint16_t reg;
    scanf("%hx", &reg);

    // Fill union and print channel and adc_value
    ADC_Result adc_rs;
    adc_rs.adc_reg = reg;
    printf("Channel: %u\n", adc_rs.channel);
    printf("ADC Value: %u", adc_rs.adc_value);
    return 0;
}