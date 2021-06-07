

/*---------------------------------------------------------------------------*/
/*
			\file		Speedometer Driver.c
			
			\brief		Speedometer Driver functionality is implemented here



*//*-------------------------------------------------------------------------*/


#include <stdio.h>
#include <ctype.h>

#include "SpeedometerDriver.h"
#include "Application.h"
#include "Application_rte.h"

/*----------------------------- #defines and Macros ------------------------*/

/*It is read only for SW, but will be updated by the driver ISR. It is volatile so as to avoid compiler optimizations */
volatile int SpeedometerData = 0; 

/* counter to monitor the aliveness of the driver */
static int SpeedAliveCntr = 0;

/*------------------------------------ FUNCTIONS ----------------------------------*/
/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	SpeedometerDriver_Init

		Description :	Function to initialise the driver


*//*-------------------------------------------------------------------------------*/
void SpeedometerDriver_Init(void)
{
	/* Device Configuration */
	#ifdef DEBUG_PRINT
	printf("Entered SpeedometerDriver_Init\n");
    #endif
	Rte_SpeedDrvStatus_Rx(TRUE);
	
}

/*--------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	SpeedometerDriver_Main

		Description :	Function to monitor the Alive Counter and set the Driver Status accordingly


*//*------------------------------------------------------------------------------------------------*/

void SpeedometerDriver_Main(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered SpeedometerDriver_Main\n");
    #endif
	SpeedAliveCntr++;				  /* Alive Counter is incremented for every 500ms */
	if(SpeedAliveCntr > 3)
	{
		Rte_SpeedDrvStatus_Rx(FALSE); /* Driver Status is set to not initialised if ISR is not rxd for 2sec */
	}
	else
	{
		Rte_SpeedDrvStatus_Rx(TRUE); /* Driver Status is set to initialised if ISR is rxd within 2sec */
	}
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	SpeedometerDriver_Stop

		Description :	Function to stop the driver


*//*-------------------------------------------------------------------------------*/

void SpeedometerDriver_Stop(void)
{
	/* Close the communication with the device */
	#ifdef DEBUG_PRINT
	printf("Entered SpeedometerDriver_Stop\n");
    #endif
}

/*------------------------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	SpeedometerDriver_ISR

		Description :	Interrupt Service Routine to send the message from Driver to RTE and to reset Alive Counter


*//*----------------------------------------------------------------------------------------------------------------*/

void SpeedometerDriver_ISR(void)
{
	SpeedometerData = 100;
	SpeedAliveCntr = 0;
	#ifdef DEBUG_PRINT
	printf("Entered SpeedometerDriver_ISR\n");
	printf("\nSpeed Input = %d\n", SpeedometerData);
    #endif
	Rte_SpeedDrv_Rx(SpeedometerData);
}


