/*
 *
 *
  LCD.h  *
         */


#ifndef LCD_H
#define LCD_H

#define A 0x05
#define B 0x06
#define C 0x07
#define D 0x08
#define E 0x09

#define  clear_lcd 0x01
#define  cursor_on 0x0E
#define  cursor_off 0x0C
#define  return_home 0x02
#define  cursor_right 0x06
#define  first_row 0x80
#define  second_row 0xC0
#define  cursor_blink 0x0F

void lcd_intializatian();
void lcd_command(char cmd);
void lcd_out_(unsigned char value);
void lcd_print_s(char *str);
void lcd_goxy(unsigned char y , unsigned char x);
#endif