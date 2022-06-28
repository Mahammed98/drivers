sbit LCD_RS at RE0_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RC3_bit;
sbit LCD_D5 at RC2_bit;
sbit LCD_D6 at RC1_bit;
sbit LCD_D7 at RC0_bit;

sbit LCD_RS_Direction at TRISE0_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISC3_bit;
sbit LCD_D5_Direction at TRISC2_bit;
sbit LCD_D6_Direction at TRISC1_bit;
sbit LCD_D7_Direction at TRISC0_bit;

void reset_wifi();
void new_line();
void reset_buffer();
void configuration ();
char find_string(char *string, char *string_find);
char respone_success();
void wifi_config();
void check_webpage_request();
void get_counter_value();
unsigned int get_size_data();