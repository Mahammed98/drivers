/*
*
*
*
   Macros.h  *
             *
             *
             */
#ifndef Macros_H
#define Macros_H


 #define set_bin(reg,bit) (reg|=1<<bit)
 #define reset_bin(reg,bit) (reg&=~(1<<bit))
 #define Toggel_bin(reg,bit) (reg^=1<<bit)
 #define set_port(reg) (reg=0xff)
 #define reset_port(reg) (reg=0x00)


 #endif