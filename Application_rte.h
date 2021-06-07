

/*---------------------------------------------------------------------------*/
/*
			\file		Application_rte.h
			
			\brief		Declarations for RTE functionality



*//*-------------------------------------------------------------------------*/


/*--------------- standard includes ------------- */

/*--------------- project includes ------------- */


/*--------------- #defines and MACROS ----------*/

#define FUELTANK_DRIVERID 		0
#define TEMPERATURE_DRIVERID 	1
#define SPEEDOMETER_DRIVERID 	2
#define MAXDRIVERID	 			3

/*--------------- PROTOTYPES OF FUNCTIONS -------------*/

void RTE_Init(void);
void RTE_Stop(void);

void Rte_FuelDrvStatus_Rx(int Status);
void Rte_TempDrvStatus_Rx(int Status);
void Rte_SpeedDrvStatus_Rx(int Status);

void Rte_Read_FuelDataStatus(int *Status);
void Rte_Read_TempDataStatus(int *Status);
void Rte_Read_SpeedDataStatus(int *Status);

void Rte_Read_FuelData(int *Data);
void Rte_Read_TempData(int *Data);
void Rte_Read_SpeedData(int *Data);

void Rte_FuelDrv_Rx(int FuelData);
void Rte_TempDrv_Rx(int TemperatureData);
void Rte_SpeedDrv_Rx(int SpeedData);

void Rte_registerCbk(void (*Rte_AppDrv_Cbk)(void), int driverID);