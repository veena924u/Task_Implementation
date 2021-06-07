

/*---------------------------------------------------------------------------*/
/*
			\file		Application.h
			
			\brief		Declarations for the Application functionality



*//*-------------------------------------------------------------------------*/


/*--------------- standard includes ------------- */

/*--------------- project includes ------------- */

/*--------------- #defines and MACROS ----------*/

#define TRUE 1
#define FALSE 0
//#define DEBUG_PRINT

/*--------------- PROTOTYPES OF FUNCTIONS -------------*/

void Appl_Main(void);
void Appl_Init(void);
void Appl_Stop(void);


void App_RTEFuelDriverCbk(void);
void App_RTETempDriverCbk(void);
void App_RTESpeedDriverCbk(void);


