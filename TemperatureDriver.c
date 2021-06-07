

/*---------------------------------------------------------------------------*/
/*
			\file		Temperature Driver.c
			
			\brief		Temperature Driver functionality is implemented here



*//*-------------------------------------------------------------------------*/


#include <stdio.h>
#include <ctype.h>

#include "TemperatureDriver.h"
#include "Application.h"
#include "Application_rte.h"

/*------------------------------- #defines and Macros ----------------------------*/

/*It is read only for SW, but will be updated by the driver ISR. It is volatile so as to avoid compiler optimizations */
volatile int TemperatureData = 0; 

/* counter to monitor the aliveness of the driver */
static int TempAliveCntr = 0; 

/*------------------------------------ FUNCTIONS ----------------------------------*/
/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	SpeedometerDriver_Init

		Description :	Function to initialise the driver


*//*-------------------------------------------------------------------------------*/
void TemperatureDriver_Init(void)
{
	/* Device Configuration*/
	#ifdef DEBUG_PRINT
	printf("Entered TemperatureDriver_init\n");
	#endif
	Rte_TempDrvStatus_Rx(TRUE);
}

/*--------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	TemperatureDriver_Main

		Description :	Function to monitor the Alive Counter and set the Driver Status accordingly


*//*------------------------------------------------------------------------------------------------*/

void TemperatureDriver_Main(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered TemperatureDriver_main\n");
	#endif
	TempAliveCntr++;				 /* Alive Counter is incremented for every 500ms */
	if(TempAliveCntr > 3)
	{
		Rte_TempDrvStatus_Rx(FALSE); /* Driver Status is set to not initialised if ISR is not rxd for 2sec */
	}
	else
	{
		Rte_TempDrvStatus_Rx(TRUE);  /* Driver Status is set to initialised if ISR is rxd within 2sec */
	}
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	TemperatureDriver_Stop

		Description :	Function to stop the driver


*//*-------------------------------------------------------------------------------*/
void TemperatureDriver_Stop(void)
{
	/* Close the communication with the device */
	#ifdef DEBUG_PRINT
	printf("Entered TemperatureDriver_stop\n");
	#endif
}

/*------------------------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	TemperatureDriver_ISR

		Description :	Interrupt Service Routine to send the message from Driver to RTE and to reset Alive Counter


*//*----------------------------------------------------------------------------------------------------------------*/

void TemperatureDriver_ISR(void)
{
	TemperatureData = 45;
	TempAliveCntr  = 0;
	#ifdef DEBUG_PRINT
	printf("Entered TemperatureDriver_ISR\n");
	printf("\nTemperature Input = %d\n", TemperatureData);
	#endif
	Rte_TempDrv_Rx(TemperatureData);
}


