#line 1 "D:/Eng moahmed/drivers/GPIO/GPIO.c"
#line 1 "d:/eng moahmed/drivers/gpio/macros.h"
#line 1 "d:/eng moahmed/drivers/gpio/gpio.h"






void port_direction(char,char );
void bin_direction(char,char,char);
char Read_bin(char,char);
void write_bin(char, char,char);
void write_port(char, char);
char read_port(char);
#line 1 "d:/eng moahmed/drivers/gpio/ports_pic.h"
#line 8 "D:/Eng moahmed/drivers/GPIO/GPIO.c"
 void port_direction(char base,char state)

 { if(state== 0 )
  (*(volatile char *)(base|0x80)=0x00) ;

 if(state== 1 )
  (*(volatile char *)(base|0x80)=0xff) ;

 }


 void pin_direction(char base , char bin ,char state)

 {
 if(state== 0 )
  (*(volatile char *)(base|0x80)&=~(1<<bin)) ;

 if(state== 1 )
  (*(volatile char *)(base|0x80)|=1<<bin) ;

 }


 char read_bin(char base,char bin)
 {
 char result;
 result = (*(volatile char *)(base)) & (1<<bin);

 if (result==1)
 return 1;
 else
 return 0;


 }

 char read_port (char base)

 {

 return (*(volatile char *)(base));

 }

 void port_write (char base ,char value)


 {
 (*(volatile char *)(base))=value;

 }


 void bin_write (char base ,char value ,char bin)


 {
 if(value==0)
  (*(volatile char *)(base)&=~(1<<bin)) ;


 if(value==1)
  (*(volatile char *)(base)|=1<<bin) ;

 }
