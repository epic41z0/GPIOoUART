#include <avr/io.h>
#include "serial.h"

void uart_init() {
    // Konfigurera baud rate till 9600
    UBRR0H = (unsigned char)(103 >> 8);
    UBRR0L = (unsigned char)103;
    // Aktivera sändning och mottagning
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    // Ställ in frame format: 8 data, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

char uart_getchar() {
    // Vänta på att ett tecken ska mottagas
    while (!(UCSR0A & (1 << RXC0)))
        ;
    // Returnera tecknet som mottogs
    return UDR0;
}

void uart_putchar(char data) {
    // Vänta på att bufferten ska bli klar för sändning
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    // Lägg till data i sändningsbufferten
    UDR0 = data;
}

void uart_echo() {
    // Vänta på ett inkommande tecken
    char received_char = uart_getchar();
    // Skicka tillbaka samma tecken
    uart_putchar(received_char);
}
