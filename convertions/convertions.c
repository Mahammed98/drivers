 /* This deriver is used for convert the digital number
       to character to display  in  lcd

       Made by : Mohamed EL Nabawy   */
#include"convertions.h"

////////////// this function for positive 2 byte number////////////////////////

void word_to_string (unsigned int num,  char *chr1) // must enter 6 element
{
   int i=-1;
   char arr[6];


 do{


    arr[++i]= (num % 10) +0x30;

    num = num / 10;

    if(num==0)
      {
          arr[++i]=0;
          //break;
      }


   }while(arr[i]!=0);



   while(i>0){

      *(chr1++)=arr[--i];

   }

    *chr1=0;
}

///////////////////////////this function for negative or positive  2 byte number///////////////

void int_to_string (int num,  char *chr1)   // must enter 7 element
{
   int i=-1;
   char arr[7];

num =num*(-1);


 do{


    arr[++i]= (num % 10) +0x30;


    num = num / 10;

    if(num==0)
      {
          arr[++i]=0x2d;
          arr[++i]=0;

      }


   }while(arr[i]!=0);


   while(i>0){

      *(chr1++)=arr[--i];

   }

    *chr1=0;
}

//////////////////////////////////this function for positive 1 byte number

void byte_to_string (unsigned int num,  char *chr1)  // must enter 4 element
{
   int i=-1;
   char arr[4];


 do{


    arr[++i]= (num % 10) +0x30;

    num = num / 10;

    if(num==0)
      {
          arr[++i]=0;

      }


   }while(arr[i]!=0);



   while(i>0){

      *(chr1++)=arr[--i];

   }

    *chr1=0;
}

////////////////////this function for positive or negative 1 byte number////////////////////////

void short_to_string (int num,  char *chr1)// must enter 5 element

{
   int i=-1;
   char arr[5];

num =num*(-1);


 do{


    arr[++i]= (num % 10) +0x30;


    num = num / 10;

    if(num==0)
      {
          arr[++i]=0x2d;
          arr[++i]=0;

      }


   }while(arr[i]!=0);


   while(i>0){

      *(chr1++)=arr[--i];

   }

    *chr1=0;
}

/////////////////////// this function for long numbers//////////////////

void long_to_string (long num,  char *chr1)   // must enter 11 element
{
   int i=-1;
   char arr[11];


 do{


    arr[++i]= (num % 10) +0x30;

    num = num / 10;

    if(num==0)
      {
          arr[++i]=0;

      }


   }while(arr[i]!=0);


   while(i>0){

      *(chr1++)=arr[--i];

   }

    *chr1=0;
}

////////////////////this function for float number//////////////////////////

void float_to_string ( float num,  char *chr1)
{

   int i=-1;
   int j;
   int a;
   float negativ_num =num;
   unsigned int real_num ;
   unsigned int fraction_num;
   char arr[15];
             if(num <= 0.0)
                num*=(-1.0);
   //int real_num1 ;
   //int fraction_num1;
     real_num = num;
      fraction_num =(num - real_num)*1000;
 do{


    arr[++i]= (real_num % 10) +0x30;

    real_num = real_num / 10;

    if(real_num==0)
      {
          arr[++i]=0x2e;

          j=i;
          a=j;

      }


   }while(arr[i]!=0x2e);



if(negativ_num < 0.0)
      *(chr1++)=0x2d;                        // 0x2d = '-'
     do{

        *(chr1++)=arr[--i];

       }while(i!=0);
       *(chr1)=0x2e;              // 0x2e ='.'

;
   do{


     arr[++j]= (fraction_num % 10) +0x30;

    fraction_num = fraction_num / 10;

    if(fraction_num==0)
      {
          arr[++j]=0;

      }

    }while(arr[j]!=0);


   while(j!=a)
    {
        *(++chr1)=arr[--j];

       }
       *chr1=0;

}
