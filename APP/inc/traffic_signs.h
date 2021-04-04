/*
 * traffic_signs.h
 *
 * Created: 4/4/2021 1:16:30 AM
 *  Author: Hossam Mohamed
 */ 

/***This progect to simulate the trafic lights***/
/*The modules which used*/
//GPIOs
//Timer
//LED
//LCD

#ifndef TRAFFIC_SIGNS_H_
#define TRAFFIC_SIGNS_H_

#include "bit_handle.h"
#include "data_types.h"
#include "timer.h"
#include "lcd.h"
#include "board.h"

#define TIMER_NOTI_PERIOD	1000		//1000 ms = 1 sec
/*Signs time in seconds*/
#define RED_SIGN_TIME		15			
#define YELLOW_SIGN_TIME	5			
#define GREEN_SIGN_TIME		10			
/*TRAFFIC SIGN LEDS Masks*/
#define TRAFFIC_SIGN_LEDS	0x07
#define RED_SIGN_LED		0x01
#define YELLOW_SIGN_LED		0x02
#define GREEN_SIGN_LED		0x04
/*TRAFFIC SIGN Status*/
typedef enum
{
	RED,
	YELLOW,
	GREEN	
}traffic_sign_status_t;

void traffic_signs_init(void);
void traffic_signs_start(void);


#endif /* TRAFFIC_SIGNS_H_ */