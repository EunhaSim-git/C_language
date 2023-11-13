/**********************************************************************************************************************************************
* Title: Lab4
* File name: tokenizeLine.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: Identify each message read from sensors_output.txt,
            then group each structures into corresponding array
**********************************************************************************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: tokenizeLine
*Purpose: Tokenize each message, convert each field into corresponding data types,
        invoke creating an instance of struct function, add the struct into corresponding array
*Function In parameters: line - of type string, to be tokenize
                        tempArr - An array of Temp struct, to hold instances of Temp structures
                        tempArrSize - of int, to keep track the size of tempArr
                        windSpeedDirArr - An array of windSpeedDirArr struct, to hold instances of windSpeedDirArr structures
                        windSpeedDirArrSize - of int, to keep track the size of windSpeedDirArr
                        windGustsArr - An array of windGustsArr struct, to hold instances of windGustsArr structures
                        windGustsArrSize - of int, to keep track the size of windGustsArr
*Function Out parameters: void
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
void tokenizeLine(char* line, Temp* tempArr, int* tempArrSize, WindSpeedDir* windSpeedDirArr, int* windSpeedDirArrSize, WindGusts* windGustsArr, int* windGustsArrSize){
    Temp* temp; WindSpeedDir* windSpeedDir; WindGusts* windGusts;
    time_t seconds; int type;
    double celsius;
    double kmPerH; int degrees;
    double prev, current;
    char *token, *comma = ",";

    token = strtok(line, comma);/*tokenize a line*/
    seconds = atoi(token);/*convert string to an int; timeStamp*/
    token = strtok(NULL, comma);/*tokenize to get 'type'*/
    type = atoi(token);/*convert string to an int; type*/

    if (type == 1){/*Temp*/
        token = strtok(NULL, comma);/*tokenize to get Celsius*/
        celsius = atof(token);/*convert string to float*/  
        
        temp = createTemp(seconds, type, celsius);/*invoke to create an instance of corresponding struct*/
        tempArr[*tempArrSize] = *temp;
        (*tempArrSize)++;        

    }else if(type == 2){/*WindSpeedDir*/
        token = strtok(NULL, comma);/*tokenize to get KmPerH*/
        kmPerH = atof(token);/*convert string to float*/
        token = strtok(NULL, comma);/*tokenize to get Degrees*/
        degrees = atoi(token);

        windSpeedDir = createWindSpeedDir(seconds, type, kmPerH, degrees);/*invoke to create an instance of corresponding struct*/
        windSpeedDirArr[*windSpeedDirArrSize] = *windSpeedDir;
        (*windSpeedDirArrSize)++;
    
    }else{/*WindGusts*/
        token = strtok(NULL, comma);/*tokenize to get prev*/
        prev = atof(token);/*convert string to float*/
        token = strtok(NULL, comma);/*tokenize to get Current*/
        current = atof(token);

        windGusts = createWindGusts(seconds, type, prev, current);/*invoke to create an instance of corresponding struct*/
        windGustsArr[*windGustsArrSize] = *windGusts;
        (*windGustsArrSize)++;
    }
}