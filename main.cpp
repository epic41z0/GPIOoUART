#include <avr/io.h>

#define LED_PIN 8
#define BUTTON_PIN 9

int main() {
    // Konfigurera LED_PIN som output
    DDRB |= (1 << LED_PIN);

    // Konfigurera BUTTON_PIN som input
    DDRB &= ~(1 << BUTTON_PIN);
    // Aktivera pull-up motstånd för knappen
    PORTB |= (1 << BUTTON_PIN);

    while (1) {
        // Läs status för knappen
        if (PINB & (1 << BUTTON_PIN)) {
            // Om knappen är tryckt, sätt LED_PIN till HIGH
            PORTB |= (1 << LED_PIN);
        } else {
            // Annars, sätt LED_PIN till LOW
            PORTB &= ~(1 << LED_PIN);
        }
    }
  

    return 0;
}
