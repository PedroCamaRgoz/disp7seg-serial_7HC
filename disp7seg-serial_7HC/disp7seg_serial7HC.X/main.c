/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 23 de Agosto de 2021, 20:23
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "display7segmentos.h"

void main(void)
{
    char cont = 0;
    char i = 0;
    disp7seg_init();
   
    
    while( 1 )
    {
        disp7seg_serial(cont); 
        delay(500);
        cont = ++cont % 16;   
    }
}
