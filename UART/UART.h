#ifndef UART_H
#define UART_H

#define fosc 8000000
#define bdr 9600
#define baud (fosc/bdr/16)-1

 void UART_INT();
void UART_write( char data1);
char UART_read(void);
void UART_write_text( char * str);
void UART_read_text(char* str , char end  );

#endif