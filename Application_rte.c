

/*---------------------------------------------------------------------------*/
/*
			\file		Application_rte.c
			
			\brief		RTE functionality is implemented here



*//*-------------------------------------------------------------------------*/


#include <stdio.h>

#include "Application_rte.h"
#include "Application.h"

#include "FuelTankDriver.h"
#include "TemperatureDriver.h"
#include "SpeedometerDriver.h"

/*------------------------------------ #defines and Macros ---------------------- */


/* Function pointer declaration */
typedef void (*Rte_AppDrv_Cbk) (void);

/* Function pointer points to an array of driver function callbacks */
Rte_AppDrv_Cbk driverPtr[MAXDRIVERID];


/* RTE Buffer to store the data from each driver */
int Rte_FuelInputData;
int Rte_TempInputData;
int Rte_TempInputData;

static int Rte_FuelDrvInitStatus = 0;
static int Rte_TempDrvInitStatus = 0;
static int Rte_SpeedDrvInitStatus = 0;


/*---------------------------------- FUNCTIONS ------------------------------------*/

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	RTE_Init

		Description :	Function to initialise the RTE


*//*-------------------------------------------------------------------------------*/

void RTE_Init(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered RTE_Init\n");
    #endif
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_FuelDrvStatus_Rx

		Description :	Function to receive the Fuel Tank Status from Driver


*//*-------------------------------------------------------------------------------*/

void Rte_FuelDrvStatus_Rx(int Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_FuelDrvStatus_Rx\n");
    #endif
	Rte_FuelDrvInitStatus = Status;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_TempDrvStatus_Rx

		Description :	Function to receive the Temperature Status from Driver


*//*-------------------------------------------------------------------------------*/
void Rte_TempDrvStatus_Rx(int Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_TempDrvStatus_Rx\n");
    #endif
	Rte_TempDrvInitStatus = Status;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_SpeedDrvStatus_Rx

		Description :	Function to receive the Speedometer Status from Driver

*//*-------------------------------------------------------------------------------*/
void Rte_SpeedDrvStatus_Rx(int Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_SpeedDrvStatus_Rx\n");
    #endif
	Rte_SpeedDrvInitStatus = Status;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_FuelDataStatus

		Description :	Function to send the Fuel Tank Status to Application


*//*-------------------------------------------------------------------------------*/

void Rte_Read_FuelDataStatus(int *Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_FuelDataStatus\n");
    #endif
	 *Status = Rte_FuelDrvInitStatus;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_TempDataStatus

		Description :	Function to send the Temp Driver Status to Application


*//*-------------------------------------------------------------------------------*/

void Rte_Read_TempDataStatus(int *Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_TempDataStatus\n");
    #endif
	*Status = Rte_TempDrvInitStatus;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_SpeedDataStatus

		Description :	Function to send the Speedometer Driver Status to Application


*//*-------------------------------------------------------------------------------*/

void Rte_Read_SpeedDataStatus(int *Status)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_SpeedDataStatus\n");
    #endif
	*Status = Rte_SpeedDrvInitStatus;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_FuelDrv_Rx

		Description :	Function to read the Fuel Input Data from Driver


*//*-------------------------------------------------------------------------------*/

void Rte_FuelDrv_Rx(int FuelData)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_FuelDrv_Rx\n");
    #endif
	Rte_FuelInputData = FuelData;
	driverPtr[FUELTANK_DRIVERID]();
} 

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_TempDrv_Rx

		Description :	Function to read the Fuel Input Data from Driver


*//*-------------------------------------------------------------------------------*/

void Rte_TempDrv_Rx(int TemperatureData)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_TempDrv_Rx\n");
    #endif
	Rte_TempInputData = TemperatureData;
	driverPtr[TEMPERATURE_DRIVERID]();
} 

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_SpeedDrv_Rx

		Description :	Function to receive the Speed Data from Driver


*//*-------------------------------------------------------------------------------*/

void Rte_SpeedDrv_Rx(int SpeedData)
{
    #ifdef DEBUG_PRINT
	printf("Entered Rte_SpeedDrv_Rx\n");
    #endif

	Rte_TempInputData = SpeedData;
	driverPtr[SPEEDOMETER_DRIVERID]();
} 

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_FuelData

		Description :	Function to receive the Fuel Data from RTE Buffer


*//*-------------------------------------------------------------------------------*/

void Rte_Read_FuelData(int *Data)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_FuelData\n");
    #endif
	 *Data = Rte_FuelInputData;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_TempData

		Description :	Function to receive the Temp Data from RTE Buffer


*//*-------------------------------------------------------------------------------*/
void Rte_Read_TempData(int *Data)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_TempData\n");
    #endif
	*Data = Rte_TempInputData;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_Read_SpeedData

		Description :	Function to read the Fuel Input Data from RTE Buffer


*//*-------------------------------------------------------------------------------*/

void Rte_Read_SpeedData(int *Data)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_Read_SpeedData\n");
    #endif
	*Data = Rte_TempInputData;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Rte_registerCbk

		Description :	Function to read the status of all the drivers from RTE


*//*-------------------------------------------------------------------------------*/
void Rte_registerCbk(void (*Rte_AppDrv_Cbk)(void), int driverID)
{
	#ifdef DEBUG_PRINT
	printf("Entered Rte_registerCbk\n");
    #endif
	driverPtr[driverID] = Rte_AppDrv_Cbk;
}

/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	RTE_Stop

		Description :	Function to stop RTE running


*//*-------------------------------------------------------------------------------*/
void RTE_Stop(void)
{
	printf("Entered RTE_stop\n");
}

