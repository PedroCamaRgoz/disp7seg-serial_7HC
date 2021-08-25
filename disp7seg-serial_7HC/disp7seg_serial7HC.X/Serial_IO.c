/*
 * File:   Serial_IO.c
 * Author: Pedro
 *
 * Created on 23 de Agosto de 2021, 16:03
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "Serial_IO.h"

typedef union
{ 
    struct 
    {
        char DS :PORTB0;
        char ST :PORTB1;
        char SH :PORTB2;
        char    :SOBRA ;
    };
    
}portb;

volatile portb serial __at (0x006);

void serial_init (void)
{
    ANSELH = 0x00;
    TRISBbits.TRISB0 = OUTPUT;
    TRISBbits.TRISB1 = OUTPUT;
    TRISBbits.TRISB2 = OUTPUT;
    PORTB = 0;
}

void serial_SH (void)
{
     serial.SH = TRUE;     serial.SH = FALSE;   
}

void serial_ST (void)
{
     serial.ST = TRUE ;    serial.ST = FALSE;
}

void Serial_IO (char i)
{
    char mask = 0x01;
    
    while(mask)
    {
        if(i & mask) serial.DS =  TRUE;
        else         serial.DS = FALSE;
 
        mask<<=1;        
        serial_SH();
    }
    serial_ST(); 
}

