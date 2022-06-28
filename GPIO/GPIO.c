
#include"Macros.h"
#include"GPIO.h"
#include"ports_pic.h"



 void port_direction(char base,char state)

    {  if(state==OUTPUT)
         reset_port(*(volatile char *)(base|0x80));

          if(state==INPUT)
             set_port(*(volatile char *)(base|0x80));

       }


  void bin_direction(char base , char bin ,char state)

        {
            if(state==OUTPUT)
          reset_bin(*(volatile char *)(base|0x80),bin);

         else
             set_bin(*(volatile char *)(base|0x80),bin);

          }


       char read_bin(char base,char bin)
            {
             volatile char result;
              result = (*(volatile char *)(base)) & (1<<bin);

                if (result==1)
                  return 1;
               else
                  return 0;


       }

  char read_port (char base)

    {
      //uint8_t result ;
     return  (*(volatile char *)(base));

      }

   void write_port (char base ,char value)


    {
       (*(volatile char *)(base))=value;

      }


    void write_bin (char base ,char value ,char bin)


    {
       if(value==0)
         reset_bin(*(volatile char *)(base),bin);


       if(value==1)
         set_bin(*(volatile char *)(base),bin);

      }