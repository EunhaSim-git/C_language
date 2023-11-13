/**********************************************************************************************************************************************
* Title: Lab4
* File name: createWindSpeedDir.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: To create an instance of WindSpeedDir struct
**********************************************************************************************************************************************/
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**********************************************************************************************************************************************
*Function name: createWindSpeedDir
*Purpose: To create an instance of WindSpeedDir struct and return the struct of pointer type
*Function In parameters: seconds - timestamp member for the struct
                        type - '2' indicating WindSpeedDir struct
                        kmPerH - kmPerH member for the struct
                        degrees - degrees member for the struct
*Function Out parameters: WindSpeedDir pointer - the created WindSpeedDir instance struct
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
WindSpeedDir* createWindSpeedDir(long seconds, int type, double kmPerH, int degrees){
    WindSpeedDir* windSpeedDir;
    windSpeedDir = malloc(sizeof(WindSpeedDir));/*memory allocation for a Temp struct*/
    windSpeedDir->timeStamp  = seconds;
    windSpeedDir->type = type;
    windSpeedDir->kmPerH = kmPerH;
    windSpeedDir->degrees = degrees;
    return windSpeedDir;
}
