/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: dropCourse.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Prompts user to drop a student from the registered course.
**********************************************************************************************************************************************/
#include <stdio.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: dropCourse
*Purpose: Change registration status for user entered index of registerTable and update the status accordingly
*Function In parameters: registerTable - 2D array that holds studentId and courseId arrays
                        regisStatus - an array to hold registration status 0 as dropped 1 as registered
                        regisIndex - length of registerTable
*Function Out parameters: void
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/

void dropCourse(int** registerTable, int* regisStatus, int regisIndex)
{
    int indexToDrop;

    printf("Please select Index number to drop student registration: ");
    scanf("%i", &indexToDrop);
    if(indexToDrop >= 0 && indexToDrop < regisIndex)
    {
        if(regisStatus[indexToDrop] == 1)
        {
            regisStatus[indexToDrop] = 0;
            printf("Drop course successful.\n");
        }
    }
    else
    {
        printf("Invalid index selected.\n");
    }
}