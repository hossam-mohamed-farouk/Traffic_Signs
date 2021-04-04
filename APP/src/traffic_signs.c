/*
 * traffic_signs.c
 *
 * Created: 4/4/2021 1:36:15 AM
 *  Author: Hossam Mohamed
 */ 

#include "traffic_signs.h"

static void time_adjust(void);

static void red_sign(void);
static void yellow_sign(void);
static void green_sign(void);

volatile int sec_counter = 0;
volatile int rem_time = RED_SIGN_TIME;
traffic_sign_status_t sign_status = RED;

void traffic_signs_init(void)
{
	lcd_init();
	lcd_clear();
	lcd_disp_str("Remaining Time ");
	lcd_disp_strXY(2, 8, "SEC");
	timer0_init(MODE_NORMAL);
	leds_init(TRAFFIC_SIGN_LEDS);
	leds_on(RED_SIGN_LED);
	lcd_disp_intXY(2,3,rem_time);
	timer0_set_notification(time_adjust,TIMER_NOTI_PERIOD,NOTIFY_CONTINUOUS);
}

void traffic_signs_start(void)
{
		if((sec_counter == RED_SIGN_TIME) && (sign_status == RED))
		{
			sec_counter = 0;
			sign_status = YELLOW;
			yellow_sign();
			rem_time = YELLOW_SIGN_TIME;
			lcd_disp_intXY(2,3,rem_time);
		}
		else if((sec_counter == YELLOW_SIGN_TIME) && (sign_status == YELLOW))
		{
			sec_counter = 0;
			sign_status = GREEN;
			green_sign();
			rem_time = GREEN_SIGN_TIME;
			lcd_disp_intXY(2,3,rem_time);
		}
		else if((sec_counter == GREEN_SIGN_TIME) && (sign_status == GREEN))
		{
			sec_counter = 0;
			sign_status = RED;
			red_sign();
			rem_time = RED_SIGN_TIME;
			lcd_disp_intXY(2,3,rem_time);
		}
}

static void red_sign(void)
{
	leds_on(RED_SIGN_LED);
	leds_off(GREEN_SIGN_LED);
}

static void yellow_sign(void)
{
	leds_on(YELLOW_SIGN_LED);
	leds_off(RED_SIGN_LED);
}

static void green_sign(void)
{
	leds_on(GREEN_SIGN_LED);
	leds_off(YELLOW_SIGN_LED);
}

static void time_adjust(void)
{
	sec_counter ++;
	rem_time --;
	lcd_disp_strXY(2,3,"  ");
	lcd_disp_intXY(2,3,rem_time);
}