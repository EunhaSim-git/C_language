/**********************************************************************************************************************************************
* Title: Lab4
* File name: createTemp.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: To create an instance of Temp struct
**********************************************************************************************************************************************/

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**********************************************************************************************************************************************
*Function name: createTemp
*Purpose: To create an instance of Temp struct and return the struct of pointer type
*Function In parameters: seconds - timestamp member for the struct
                        type - '1' indicating Temp struct
                        celsius - celsius member for the struct
*Function Out parameters: Temp pointer - the created Temp instance struct
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
Temp* createTemp(long seconds, int type, double celsius){
    Temp* temp;
    temp = malloc(sizeof(Temp));/*memory allocation for a Temp struct*/
    temp->timeStamp  = seconds;
    temp->type = type;
    temp->celsius = celsius;
    return temp;
}