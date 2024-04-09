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

void uart_putchar(char data) {
    // Vänta på att bufferten ska bli klar för sändning
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    // Lägg till data i sändningsbufferten
    UDR0 = data;
}

void uart_putstr(const char *str) {
    // Loopa över varje tecken i strängen tills vi når '\0'
    while (*str != '\0') {
        // Skicka tecknet över UART
        uart_putchar(*str);
        // Gå till nästa tecken i strängen
        str++;
    }
    // Lägg till en newline-tecken på slutet av strängen
    uart_putchar('\n');
}
