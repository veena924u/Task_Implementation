README
***********

Softwares to install :
----------------------------
GCC for Windows - MingW
GitHub

Steps to build the system :
------------------------------
In the current directory:
Run command : gcc -o App.exe Application.c Application_rte.c FuelTankDriver.c SpeedometerDriver.c TemperatureDriver.c Test.c

Run App.exe


Steps to display the debug information:
------------------------------------------ 
Define macro DEBUG_PRINT in Application.h file
Follow the steps to build the system section

File Descriptions :
---------------------
Docs/TestApplication_SequenceDiagram.pdf - Contains the sequence diagram of the entire solution system.
Docs/Task_Description.pptx 				 - Contains the Software Architecture of the system.

Application.c, Application.h 				- Contains the logic to count the number of messages
Application_rte.c , Application_rte.h 		- Abstraction Layer between the Application layer and BSW
FuelTankDriver.c , FuelTankDriver.h 		- Driver logic for the fuel tank sensor
TemperatureDriver.c, TemperatureDriver.h 	- Driver logic for the temperature sensor
SpeedometerDriver.c , SpeedometerDriver.h 	- Driver logic for the speedometer sensor
Test.c 										- System Emulator
