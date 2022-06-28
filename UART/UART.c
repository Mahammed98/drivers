
/*
 Made by : Mohamed EL Nabawy

  UART DRIVER

 RUN IN Asynchronous mode , high speed baud rate , transmit 8 bit

*/
#include"UART.h"

void UART_INT()
{
  (*(volatile char *)0x98) |= (1<<5) |(1<<2);
  (*(volatile char *)0x18) |= (1<<7);
   (*(volatile char *)0x18) |= (1<<4);

  (*(volatile char *)0x99) = baud;
  }

void UART_write( char data1)
{
      while (!((*(volatile char *)0x0c) & (1<<4)));

      ( *(volatile char *)0x19) = data1;
     while (!((*(volatile char *)0x98) & (1<<5)));


}
 void UART_write_text( char *str)
{


  while(*str != 0)

   { UART_write(*str++);}


}

  char UART_read(void)
 {
   while (!((*(volatile char *)0x0c) & (1<<5)));
         return RCREG;


 }
 void UART_read_text(char* str , char  end  )
 {  for(;;){

       while (!((*(volatile char *)0x0c) & (1<<5)));
            *str = RCREG;

            if (*str == end) break;

        str++;

           }


 }