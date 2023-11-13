/**********************************************************************************************************************************************
* Title: Lab4
* File name: convertTimestamp.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/17/2023
* Submission date: 11/12/2023
* Purpose: To convert a Unix timestamp to the format "yyyy/mm/dd hh:mm:ss" and display
**********************************************************************************************************************************************/

#include <stdio.h>
#include <time.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: convertTimestamp
*Purpose: To convert a Unix timestamp to the format "yyyy/mm/dd hh:mm:ss"
            using 'gmtime' function to convert the timestamp to a 'struct tm'
            and 'strftime' to format as a string.
*Function In parameters: timestamp - of type long, a Unix timestamp format to be converted to "yyyy/mm/dd hh:mm:ss"
*Function Out parameters: void
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
void convertTimestamp(long timestamp){
    struct tm *timeInfo;
    int timeZoneOffset = -4;
    char formattedTime[20];
    timeInfo = gmtime(&timestamp);
    if(timeInfo != NULL){/*check if conversion was successful*/
        timeInfo->tm_hour += timeZoneOffset;/*adjust time to GMT -4*/                
        strftime(formattedTime, sizeof(formattedTime), "%Y/%m/%d %H:%M:%S", timeInfo);
        printf("%s", formattedTime);
    }else{
        printf("Error converting timestamp to struct tm\n");
    }
}