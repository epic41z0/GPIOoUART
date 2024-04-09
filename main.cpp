#include "serial.h"

int main() {
    // Initiera UART
    uart_init();

    while (1) {
        // Anropa uart_echo för att vänta på och skicka tillbaka ett inkommande tecken
        uart_echo();
    }

    return 0;
}
