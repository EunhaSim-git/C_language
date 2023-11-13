/**********************************************************************************************************************************************
* Title: Lab4
* File name: createWindGusts.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: To create an instance of WindGusts struct
**********************************************************************************************************************************************/

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**********************************************************************************************************************************************
*Function name: createWindGusts
*Purpose: To create an instance of WindGusts struct and return the struct of pointer type
*Function In parameters: seconds - timestamp member for the struct
                        type - '3' indicating WindGusts struct
                        prev - prev member for the struct
                        current - current member for the struct
*Function Out parameters: WindGusts pointer - the created WindGusts instance struct
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
WindGusts* createWindGusts(long seconds, int type, double prev, double current){
    WindGusts* windGusts;
    windGusts = malloc(sizeof(WindGusts));/*memory allocation for a WindGusts struct*/
    windGusts->timeStamp  = seconds;
    windGusts->type = type;
    windGusts->prev = prev;
    windGusts->current = current;
    return windGusts;
}

