/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 1/27/2014 12:22:11 AM
 *  Author: Islam
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "lcd_4bit.h"
#include <util/delay.h>

/* ================================= CODE 1 ======================================== */

void task1 (void)
{
for(;;)
	{
		for (int i =12 ; i>0 ; i--)
			{
			lcd_disp_string_xy("Hello" , 0 , i);
			lcd_disp_string_xy("World" , 1, 12-i);
			_delay_ms(100);
			lcd_clrScreen();
			}
		for (int i =0 ; i<12 ; i++)
			{
			lcd_disp_string_xy("Hello" , 0 , i);
			lcd_disp_string_xy("World" , 1, 12-i);
			_delay_ms(100);
			lcd_clrScreen();
			}
	}
}
int main(void)
{	
xTaskHandle xHANDLE;
xTaskCreate(task1,NULL,50,NULL,1,&xHANDLE);
lcd_init();
vTaskStartScheduler();

	return 0;   
}


/* ========================================  CODE 2 =============================================== */

/*
	xTaskHandle xHANDLE;
	xTaskHandle xHANDLE2;

void task1 (void)
{

static int i = 0;
static flag =0;
	for(;;)
	{					
		lcd_disp_string_xy("Hello" , 0, i);
		if(flag==0)
		i++;
		if(flag ==1)
		i--;
		if (i==12)
		flag=1;
		if (i==0)
		flag=0;
		_delay_ms(100);
		
			vTaskPrioritySet(xHANDLE,1);
			vTaskPrioritySet(xHANDLE2,2);
	}
}
void task2 (void)
{
	static int i=12;
	static flag =0;
	for(;;)
	{
		lcd_disp_string_xy("World" ,1, i);
		if (flag ==0)
		i--;
		if (flag==1)
		i++;
		if(i==0)
		flag=1;
		if(i==12)
		flag=0;
		_delay_ms(100);
		
		lcd_clrScreen();	
			vTaskPrioritySet(xHANDLE,2);
			vTaskPrioritySet(xHANDLE2,1);
	}	
}
int main(void)
{
	xTaskCreate(task1,NULL,50,NULL,2,&xHANDLE);
	xTaskCreate(task2,NULL,50,NULL,1,&xHANDLE2);
	lcd_init();
	vTaskStartScheduler();
	
	return 0;
}
*/