
#ifndef GPIO_H
#define GPIO_H



void port_direction(char ,char  );
void bin_direction(char ,char,char);
char Read_bin(char ,char);
void write_bin(char , char,char);
void write_port(char  , char);
char read_port(char );


#endif