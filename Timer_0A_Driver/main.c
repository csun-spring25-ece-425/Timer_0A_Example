/*
 * @file main.c
 *
 * @brief Main source code for the Timer0A_Example program.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "Timer_0A_Interrupt.h"

// Declare the function prototype for the user-defined function for Timer 0A
void Timer_0A_Periodic_Task(void);

// Initialize a global variable for Timer 0A to keep track of elapsed time in milliseconds
static uint32_t ms_elapsed = 0;

// Initialize a global variable for an 8-bit counter
static uint8_t counter = 0;

int main(void)
{
	// Initialize the LEDs on the EduBase board (Port B)
	EduBase_LEDs_Init();
	
	// Initialize the RGB LED (Port F)
	RGB_LED_Init();
	
	// Initialize Timer 0A to generate periodic interrupts every 1 ms
	Timer_0A_Interrupt_Init(&Timer_0A_Periodic_Task);
	
	while(1)
	{

	}
}

/**
 * @brief
 *
 * @param
 *
 * @return
 */
void Timer_0A_Periodic_Task(void)
{
	ms_elapsed = ms_elapsed + 1;
	
	if (ms_elapsed == 500)
	{
		ms_elapsed = 0;
		
		if (counter >= 15)
		{
			counter = 0;
		}
		else
		{
			counter = counter + 1;
		}
		
		EduBase_LEDs_Output(counter);
	}
}
