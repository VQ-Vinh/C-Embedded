#include <stdio.h>

struct UART_ControlRegister {
    unsigned int baudrate : 4;
    unsigned int tx_enable : 1;
    unsigned int rx_enable : 1;
    unsigned int tx_irq_en : 1;
    unsigned int rx_irq_en : 1;
    unsigned int parity_en : 1;
    unsigned int stop_bits : 1;
    unsigned int reserved : 22;
};

void configure_uart(struct UART_ControlRegister *reg) {
    reg->baudrate = 9;
    reg->tx_enable = 1;
    reg->rx_enable = 1;
    reg->tx_irq_en = 1;
    reg->rx_irq_en = 0;
    reg->parity_en = 1;
    reg->stop_bits = 0;
}

int main() {
    struct UART_ControlRegister reg = {0};

    configure_uart(&reg);

    printf("baudrate = %u\n", reg.baudrate);
    printf("tx_enable = %u\n", reg.tx_enable);
    printf("rx_enable = %u\n", reg.rx_enable);
    printf("tx_irq_en = %u\n", reg.tx_irq_en);
    printf("rx_irq_en = %u\n", reg.rx_irq_en);
    printf("parity_en = %u\n", reg.parity_en);
    printf("stop_bits = %u", reg.stop_bits);

    return 0;
}