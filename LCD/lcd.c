/* lcd Driver
 Work in 4 bit mode or 8 bit mode
    Made by : Mohamed EL Nabawy
        */



#define data D
#define b1 4                    //user must connect the data bits in first 4 bits or the last 4 bits in the port
#define b2 5
#define b3 6
#define b4 7
#define command C
#define RS 6
#define EN 7
#define mode 4               //chose mode 4 or 8








#include"lcd.h"

//#include"Macros.h"





void lcd_intializatian()

  { if(mode==4)                                                   // if user used  4 bit mode
      {
                   //reset the data bits
    (*(volatile char *)(data|0x80))&= ~(1<<b1);
    (*(volatile char *)(data|0x80))&= ~(1<<b2);
    (*(volatile char *)(data|0x80))&= ~(1<<b3);
    (*(volatile char *)(data|0x80))&= ~(1<<b4);

             //reset the command pins

     (*(volatile char *)(command|0x80))&= ~(1<<EN);
     (*(volatile char *)(command|0x80))&= ~(1<<RS);

               // data bits=0 (intial value)

     (*(volatile char *)data) &= ~(1<<b1);
     (*(volatile char *)data) &= ~(1<<b2);
     (*(volatile char *)data) &= ~(1<<b3);
     (*(volatile char *)data) &= ~(1<<b4);

          //reste E bin

     (*(volatile char *)command &= ~(1<<EN));
            //commands in 4 bin mode
            
        delay_ms(20);
       lcd_command(0x33);
       lcd_command(0x32);
       lcd_command(0x28);             // 4 bit mode command
         }

    else if (mode==8)                                                            //if user used 8 bit mode
        {

             (*(volatile char *)(data|0x80))=0x00;
             ///////////////////////////////

                (*(volatile char *)(command|0x80))&= ~(1<<EN);
                (*(volatile char *)(command|0x80))&= ~(1<<RS);

///////////////////////////////
               (*(volatile char *)data)=0x00;

                    (*(volatile char *)command)&= ~(1<<EN);
          delay_ms(20);
            lcd_command(0x38);          // 8 bit mode command


           }


                 lcd_command(0x0e);    //display and carsor on
                 lcd_command(0x01);             //clear display
                 delay_us(2000);
                 lcd_command(0x06);             //increment carsor to right


    }

/***************************************************************************************************************************/

     void lcd_command(char cmd)
      {
          if (mode==8)                 // 8 bit mode

               {
                (*(volatile char *)data)=cmd;                              // send the command in all 8 bit data
               (*(volatile char *)command) &= ~(1<<RS);                                 // reset the rs bin if sent the command
                          }

          else if(mode==4)                                //4 bit mode

               {
                  if(((b1==0)&&(b2==1)&&(b3==2)&&(b4==3))||((b1==3)&&(b2==2)&&(b3==1)&&(b4==0)))                    // if user choose first 4 bit in port
                              {   
                              
                                  (*(volatile char *)command) &= ~(1<<RS);                                  // reset the rs bin if sent the command
                              
                                (*(volatile char*)data)=(*(volatile char*)data & 0xf0) | (cmd & 0x0f);         // first send the less significant  4 bit  of command in data port

                                (*(volatile char *)command) |= (1<<EN);                               // send puls

                         delay_us(1);

                         (*(volatile char *)command) &= ~(1<<EN);

                         delay_us(100);

                        (*(volatile char*)data )=((*(volatile char *)data) & 0xf0)| (cmd >> 4);        // send the most signtficant 4 bits of command in data port

                                       }


                     else if(((b1==7)&&(b2==6)&&(b3==5)&&(b4==4))||((b1==4)&&(b2==5)&&(b3==6)&&(b4==7)))                 // if user choose the last 4 bit in port

                                  {
                                  
                                   (*(volatile char *)command) &= ~(1<<RS);                 // reset the rs bin if sent the command

                                   (*(volatile char*)data) = (*(volatile char*)data & 0x0f) | (cmd & 0xf0);     // send the most signtficant 4 bits of command in data port




                                   (*(volatile char *)command) |= (1<<EN);                           //send puls
                                   
                                   delay_us(1);
                                  
                                   (*(volatile char *)command) &= ~(1<<EN);

                                    delay_us(100);

                                   (*(volatile char*)data) =(*(volatile char *)data & 0x0f) | (cmd << 4);              // first send the less significant  4 bit  of command in data port

                                       }


                  }


                       (*(volatile char *)command) |= (1<<EN);                          //send puls after send the last  4 command's bit
                            delay_us(1);
                         (*(volatile char *)command) &= ~(1<<EN);
                         delay_ms(10);


       }



     void lcd_out_(unsigned char value)             //send character

                 {

                      (*(volatile char *)command) |= (1<<RS);                                //set the rs bin when send the data

                           if(mode==8)

                              {*(volatile char *)data=value;}

            else if(mode==4)
                    {

                    if(((b1==7)&&(b2==6)&&(b3==5)&&(b4==4))||((b1==4)&&(b2==5)&&(b3==6)&&(b4==7)))

                                    {

                            (*(volatile char*)data)=(*(volatile char*)data & 0x0f) | (value & 0xf0);

                            (*(volatile char *)command) |= (1<<EN);

                            delay_us(1);

                            (*(volatile char *)command) &= ~(1<<EN);

                            delay_us(100);

                            (*(volatile char*)data =(*(volatile char *)data & 0x0f )| (value << 4));

                                       }

                    else if(((b1==0)&&(b2==1)&&(b3==2)&&(b4==3))||((b1==3)&&(b2==2)&&(b3==1)&&(b4==0)))

                                {

                            (*(volatile char *)command) |= (1<<RS);

                            (*(volatile char*)data)|=(value & 0x0f);

                            (*(volatile char *)command) |= (1<<EN);

                            delay_us(1);

                            (*(volatile char *)command) &= ~(1<<EN);

                            delay_us(100);

                              (*(volatile char*)data =(*(volatile char *)data & 0xf0)| (value >> 4));

                                }



                            }

                                     (*(volatile char *)command) |= (1<<EN);

                                           delay_us(1);

                                (*(volatile char *)command) &= ~(1<<EN);

                                               delay_us(100);


                      }



       void lcd_print_s(char *str)                                // send string

                  {
                      unsigned char i=0;
                        while(str[i]!=0)  { lcd_out_(str[i]); i++;}
                         }
                         
                         
         void lcd_goxy(unsigned char y , unsigned char x)                       //to control the axis of lcd
         {
           unsigned char entered_row[]={0x80,0xc0};

              lcd_command(entered_row[y-1]+x-1);
             // delay_ms(12);
         }