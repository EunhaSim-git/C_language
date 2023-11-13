/**********************************************************************************************************************************************
* Title: Lab4
* File name: main.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* List of source and header file in the project: header.h, main.c, tokenizeLine.c, createTemp.c, createWindSpeedDir.c, createWindGusts.c, convertTimestamp.c, printData.c
**********************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: main
*Purpose: To read a log file from an IoT device with multiple weather sensors.
            Identify CSV formatted messages, reading line by line using stdin.
            using malloc for each array of struct
            display the data and free the dynamically allocated memory
*Function In parameters: argc - int, the number of command-line arguments passed to the program
                        argv - an array of strings, command-line arguments passed to the program
*Function Out parameters: return 0 if program was successful, otherwise return 1; execution fails
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
int main(int argc, char *argv[]) {
    char line[100];
    int arrSize = 10;/*initial array size*/
    int tempArrSize = 0;/*set up to keep track of array size*/
    int windSpeedDirArrSize = 0;
    int windGustsArrSize = 0;
    Temp* tempArr;/*an array of Temp struct*/
    WindSpeedDir* windSpeedDirArr;/*an array of WindSpeedDir struct*/
    WindGusts* windGustsArr;/*an array of WindGusts struct*/

    tempArr = malloc(sizeof(Temp) * arrSize);
    if (tempArr == NULL){
        printf("Memory allocation failed.");
        return 1;
    }
    windSpeedDirArr = malloc(sizeof(WindSpeedDir) * arrSize);
    if (windSpeedDirArr == NULL){
        printf("Memory allocation failed.");
        return 1;
    }
    windGustsArr = malloc(sizeof(WindGusts) * arrSize);
    if (windGustsArr == NULL){
        printf("Memory allocation failed.");
        return 1;
    }
    while(fscanf(stdin, "%s", line) != EOF){/*read the given file line by line until it reaches EOF*/
        tokenizeLine(line, tempArr, &tempArrSize, windSpeedDirArr, &windSpeedDirArrSize, windGustsArr, &windGustsArrSize);
        if(tempArrSize==arrSize){/*enlarge size of tempArr*/
            tempArr = realloc(tempArr, sizeof(Temp) * arrSize * 2);
        }
        if(windSpeedDirArrSize==arrSize){/*enlarge size of windSpeedDirArr*/
            windSpeedDirArr = realloc(windSpeedDirArr, sizeof(WindSpeedDir) * arrSize * 2);
        }
        if(windGustsArrSize==arrSize){/*enlarge size of windGustsArr*/
            windGustsArr = realloc(windGustsArr, sizeof(WindGusts) * arrSize * 2);
        }        
    }

    printData(tempArr, &tempArrSize, windSpeedDirArr, &windSpeedDirArrSize, windGustsArr, &windGustsArrSize);

    free(tempArr);  /*free dynamically allocated memories*/
    free(windSpeedDirArr);
    free(windGustsArr);
    return 0;
}

