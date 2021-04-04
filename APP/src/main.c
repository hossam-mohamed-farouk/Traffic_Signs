/*
 * traffic_signs.c
 *
 * Created: 4/4/2021 12:51:37 AM
 * Author : Hossam Mohamed
 */ 


#include <avr/io.h>
#include "traffic_signs.h"

int main(void)
{
	sei();
	traffic_signs_init();
	
    /* Replace with your application code */
    while (1) 
    {
		traffic_signs_start();	
    }
}

