#ifndef SERIAL_H
#define SERIAL_H

void uart_init();
char uart_getchar();
void uart_putchar(char data);
void uart_echo();

#endif
