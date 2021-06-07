

/*---------------------------------------------------------------------------*/
/*
			\file		FuelTankDriver.c
			
			\brief		Fuel Tank Driver functionality is implemented here



*//*-------------------------------------------------------------------------*/


#include <stdio.h>
#include <ctype.h>

#include "FuelTankDriver.h"
#include "Application.h"
#include "Application_rte.h"

/*--------------------------- #defines and Macros ----------------------------------------*/

/*It is read only for SW, but will be updated by the driver ISR. It is volatile so as to avoid compiler optimizations */
volatile int FuelTankData = 0; 

/* counter to monitor the aliveness of the driver */
static int FTankAliveCntr = 0;

/*---------------------------------- FUNCTIONS ------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	FuelTankDriver_Init

		Description :	Function to initialise the driver


*//*-------------------------------------------------------------------------------*/
void FuelTankDriver_Init(void)
{
	/* Device Configuration */
	#ifdef DEBUG_PRINT
	printf("Entered FuelTankDriver_Init\n");
    #endif
	Rte_FuelDrvStatus_Rx(TRUE);
	
}

/*---------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	FuelTankDriver_Main

		Description :	Function to monitor the Alive Counter and set the Driver Status accordingly


*//*-------------------------------------------------------------------------------------------------*/

void FuelTankDriver_Main(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered FuelTankDriver_Main\n");
    #endif
	
	FTankAliveCntr++;				 /* Alive Counter is incremented for every 500ms */
	if(FTankAliveCntr > 3)
	{
		Rte_FuelDrvStatus_Rx(FALSE); /* Driver Status is set to not initialised if ISR is not rxd for 2sec */
	}
	else
	{
		Rte_FuelDrvStatus_Rx(TRUE); /* Driver Status is set to initialised if ISR is rxd within 2sec */
	}
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	FuelTankDriver_Stop

		Description :	Function to stop Fuel Tank Driver


*//*-------------------------------------------------------------------------------*/

void FuelTankDriver_Stop(void)
{
	/* Close the communication with the device */
	#ifdef DEBUG_PRINT
	printf("Entered FuelTankDriver_Stop\n");
    #endif
}

/*-----------------------------------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	FuelTankDriver_ISR

		Description :	Interrupt Service Routine to send the message from Driver to RTE and to reset Alive Counter


*//*-----------------------------------------------------------------------------------------------------------------*/

void FuelTankDriver_ISR(void)
{
	FuelTankData = 10;
	FTankAliveCntr = 0;
	#ifdef DEBUG_PRINT
	printf("Entered FuelTankDriver_ISR\n");
	printf("\nFuel Tank Input = %d\n", FuelTankData);
    #endif
	Rte_FuelDrv_Rx(FuelTankData);
}
