/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: displayRegis.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Display registerTable in the order of registration with its current registration status
**********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: displayRegis
*Purpose: Display the latest updated registerTable with its registration status
*Function In parameters: studentId - an array that holds studentIds, numOfStudents - number of studentIds
                        courseId - an array that holds courseIds, numOfCourses - number of CourseIds
                        registerTable - 2D array that holds studentId and courseId arrays
                        regisStatus - an array to hold registration status 0 as dropped 1 as registered
                        regisIndex - length of registerTable
*Function Out parameters: void
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/

void displayRegis(int* studentId, int numOfStudents, char* courseId, int numOfCourses, int** registerTable, int* regisStatus, int regisIndex)
{
    int i, j, courseDigits = 8;
    int index = 0;/*counter for regisIndex*/
    
    if(index < regisIndex)
    {
        printf("\n\t\t\tRegistration Table\n");
        printf("Registration Index\tStudent ID\tCourse ID\tRegistration Status\n");
        for(i = 0; i < numOfStudents; i++)
        {
            for(j = 0; j < numOfCourses; j++)
            {
                if(registerTable[i][j] == 1 || registerTable[i][j] == 0)
                { 
                    printf("\t%-9d\t%-11d\t%-10s\t", index, studentId[i], courseId + (j * courseDigits));
                    if(regisStatus[index] == 1)
                    {
                        printf("R\n");
                        registerTable[i][j] = 1;
                    }
                    else if(regisStatus[index] == 0)
                    {
                        printf("D\n");
                        registerTable[i][j] = 0;/*update registerTable*/
                    }
                    index++;                
                }
            }
        }
    }
    else
    {
        printf("No student registered.\n");
        return;
    }
}