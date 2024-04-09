#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main() {
    // Initiera UART
    uart_init();

    // Anropa uart_putstr för att skicka en sträng över UART
    uart_putstr("Hello, world!");

    while (1) {
        // Anropa uart_putchar för att skicka ett enskilt tecken över UART
        uart_putchar('A');
        // Vänta 1 sekund
        _delay_ms(1000);
    }

    return 0;
}
