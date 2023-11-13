/**********************************************************************************************************************************************
* Title: Lab4
* File name: header.h
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: Declare all functioin prototypes
**********************************************************************************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <time.h>

typedef struct{
    time_t timeStamp;
    int type;
    double celsius;
}Temp;

typedef struct{
    time_t timeStamp;
    int type;
    double kmPerH;
    int degrees;
}WindSpeedDir;

typedef struct{
    time_t timeStamp;
    int type;
    double prev;
    double current;
}WindGusts;

void tokenizeLine(char* line, Temp* tempArr, int* tempArrSize, WindSpeedDir* windSpeedDirArr, int* windSpeedDirArrSize, WindGusts* windGustsArr, int* windGustsArrSize);
Temp* createTemp(long seconds, int type, double celsius);
WindSpeedDir* createWindSpeedDir(long seconds, int type, double kmPerH, int degrees);
WindGusts* createWindGusts(long seconds, int type, double prev, double current);
void convertTimestamp(long timestamp);
void printData(Temp* tempArr, int* tempArrSize, WindSpeedDir* windSpeedDirArr, int* windSpeedDirArrSize, WindGusts* windGustsArr, int* windGustsArrSize);

#endif