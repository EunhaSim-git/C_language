/**********************************************************************************************************************************************
* Title: Lab4
* File name: printData.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: To print/display each array in tabular format
**********************************************************************************************************************************************/

#include <stdio.h>
#include <time.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: printData
*Purpose: To print/display each array in tabular format
*Function In parameters: tempArr - An array of Temp struct, holding instances of Temp structures
                        tempArrSize - of int, to keep track the size of tempArr
                        windSpeedDirArr - An array of windSpeedDirArr struct, holding instances of windSpeedDirArr structures
                        windSpeedDirArrSize - of int, to keep track the size of windSpeedDirArr
                        windGustsArr - An array of windGustsArr struct, holding instances of windGustsArr structures
                        windGustsArrSize - of int, to keep track the size of windGustsArr
*Function Out parameters: void
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
void printData(Temp* tempArr, int* tempArrSize, WindSpeedDir* windSpeedDirArr, int* windSpeedDirArrSize, WindGusts* windGustsArr, int* windGustsArrSize){
    int i;
    printf("Date\t   Time\t      Celsius\n");
    for(i = 0; i < (*tempArrSize); i++){
        convertTimestamp(tempArr[i].timeStamp);/*convert the Unix timestamp*/
        printf("  %.2f\n", tempArr[i].celsius);
    }
    printf("\nDate\t   Time\t     Speed  Direction\n");
    for(i = 0; i < (*windSpeedDirArrSize); i++){
        convertTimestamp(windSpeedDirArr[i].timeStamp);
        printf("  %.2f  %d\n", windSpeedDirArr[i].kmPerH, windSpeedDirArr[i].degrees);
    }
    printf("\nDate\t   Time\t     Wind Change\n");
    for(i = 0; i < (*windGustsArrSize); i++){
        convertTimestamp(windGustsArr[i].timeStamp);
        if((windGustsArr[i].current)-(windGustsArr[i].prev) > 0){
            printf("  Increasing\n");
        }else if((windGustsArr[i].current)-(windGustsArr[i].prev) == 0){
            printf("  Unchanged\n");
        }else{
            printf("  Decreasing\n");
        }  
    }
    
}