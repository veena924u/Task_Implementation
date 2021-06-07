

/*---------------------------------------------------------------------------*/
/*
			\file		Test.c
			
			\brief		Function to test the system is implemented here



*//*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#include "Application.h"
#include "FuelTankDriver.h"
#include "TemperatureDriver.h"
#include "SpeedometerDriver.h"

/*----------------------- #defines and Macros -------------------------------*/

/*---------------------------------FUNCTIONS --------------------------------------*/

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	main()

		Description :	Function to test the system


*//*-------------------------------------------------------------------------------*/
int main()
{
	
	long long int counter = 1;

	/* All the drivers are initialised */
	FuelTankDriver_Init();
	TemperatureDriver_Init();
	SpeedometerDriver_Init();
	
	Appl_Init();
	
	
	printf("!!!!!!!!!!!!!!!!!! System is up and running !!!!!!!!!!!!!!! \n\n");
	
	while(1)
	{
		/* For every 250ms */
		FuelTankDriver_ISR();
		TemperatureDriver_ISR();
		SpeedometerDriver_ISR();
		
		if(counter%2 == 0)
		{
			/* For every 500ms */
			FuelTankDriver_Main();
			TemperatureDriver_Main();
			SpeedometerDriver_Main();
		}
		
		if(counter%4 == 0)
		{	
			/* For every 1000ms */
			Appl_Main();
		}
		
		counter++;
		
		usleep(250000);
		
	}
}

