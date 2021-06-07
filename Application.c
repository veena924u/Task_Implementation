

/*---------------------------------------------------------------------------*/
/*
			\file		Application.c
			
			\brief		Application functionality is implemented here



*//*-------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#include "Application.h"
#include "Application_rte.h"
#include "FuelTankDriver.h"


/* ------------------ #defines and Macros ------------------ */


/* variable to count the message from each driver*/
/* Logic for counter overflow is not taken into consideration */
static int App_FTankMsgCount = 0;
static int App_TempMsgCount = 0;
static int App_SpeedMsgCount = 0;

/* variable to store the data from each driver */
static int App_FTankData = 0;
static int App_TempData = 0;
static int App_SpeedData = 0;

/* variable to store the status of each driver */
static int App_FTankStatus = 0;
static int App_TempStatus = 0;
static int App_SpeedStatus = 0;

/* Callback function used to read the data from each driver via RTE */
void App_RTEFuelDriverCbk(void);
void App_RTETempDriverCbk(void);
void App_RTESpeedDriverCbk(void);

/*----------------------------------- FUNCTIONS------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Appl_Init

		Description :	Function to read the status of all the drivers from RTE


*//*-------------------------------------------------------------------------------*/

void Appl_Init()
{
	#ifdef DEBUG_PRINT
	printf("Entered Appl_Init\n");
    #endif
	
	Rte_registerCbk(&App_RTEFuelDriverCbk, FUELTANK_DRIVERID);
	Rte_registerCbk(&App_RTETempDriverCbk, TEMPERATURE_DRIVERID);
	Rte_registerCbk(&App_RTESpeedDriverCbk, SPEEDOMETER_DRIVERID);
	
}

/*------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	App_RTEFuelDriverCbk

		Description :	Function to read Fuel Data from RTE and compute the messages rxd


*//*----------------------------------------------------------------------------*/
void App_RTEFuelDriverCbk(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered App_RTEFuelDriverCbk\n");
    #endif
	Rte_Read_FuelData(&App_FTankData);
	App_FTankMsgCount++;
}

/*------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	App_RTETempDriverCbk

		Description :	Function to read Temp Data from RTE and compute the messages rxd


*//*----------------------------------------------------------------------------*/
void App_RTETempDriverCbk(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered App_RTETempDriverCbk\n");
    #endif
	Rte_Read_TempData(&App_TempData);
	App_TempMsgCount++;
}

/*---------------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	App_RTESpeedDriverCbk

		Description :	Function to read Speed Data from RTE and compute the messages rxd


*//*--------------------------------------------------------------------------------------*/
void App_RTESpeedDriverCbk(void)
{
	#ifdef DEBUG_PRINT
	printf("Entered App_RTESpeedDriverCbk\n");
    #endif
	Rte_Read_SpeedData(&App_SpeedData);
	App_SpeedMsgCount++;
}
/*------------------------------------------------------------------------------*/
/*
		FUNCTION 	:	Appl_Main

		Description :	Function to check whether all drivers are running and to process the device data



*//*----------------------------------------------------------------------------*/

void Appl_Main()
{
	#ifdef DEBUG_PRINT
	printf("Entered Appl_Main\n");
    #endif
	
	Rte_Read_FuelDataStatus(&App_FTankStatus);
	Rte_Read_TempDataStatus(&App_TempStatus);
	Rte_Read_SpeedDataStatus(&App_SpeedStatus);
	
	if((TRUE == App_FTankStatus) && (TRUE == App_TempStatus) && (TRUE == App_SpeedStatus))
	{
		printf("\nAll the drivers are running \n\n"); /* Logic for processing the device data */
		printf("\nFuel Tank : Message Count = %d, Message Data = %d \n",App_FTankMsgCount, App_FTankData);
		printf("\nTemp : Message Count = %d, Message Data = %d \n",App_TempMsgCount, App_TempData);
		printf("\nSpeed : Message Count = %d,  Message Data = %d \n",App_SpeedMsgCount, App_SpeedData);
	}
	else
	{
		while(1) /* When atleast one of the devices is not running, system goes into panic */
		{
			printf("PANIC : One of the drivers are not running \n"); 
		}
		
	}
}

/*-------------------------------------------------------------*/
/*
		FUNCTION 	:	Appl_Stop


		Description :	Function to stop Application


*//*-----------------------------------------------------------*/
void Appl_Stop()
{
	#ifdef DEBUG_PRINT
	printf("Entered Appl_Stop\n");
    #endif
}
