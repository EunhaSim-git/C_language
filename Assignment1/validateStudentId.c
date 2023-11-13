/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: validateStudentId.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Prompts user to enter in studentId as numOfStudents. 
            Handle validation for studentId
**********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: validateStudentId
*Purpose: Loops until user enters a studentId in required format 
*Function In parameters: numOfStudents - number of studentIds in total
*Function Out parameters: studentId - a type of pointer int to store valid studentIds
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/

int* validateStudentId (int numOfStudents) 
{
    int i, j, isValid, alreadyOnList;
    int studentDigits = 5;/*studentId digits*/
    int* studentId;

    studentId = (int*)malloc( numOfStudents * sizeof(int) * studentDigits);
    if (studentId == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    for (i = 0; i < numOfStudents; i++)
    {
        isValid = 1;
        do
        {
            alreadyOnList = 0;
            printf("Enter the student index[%d] student id [5-digits]: ", i);
            isValid = scanf("%d", &studentId[i]);
            for (j = 0; j < i; j++)
            {
                if(studentId[i] == studentId[j])
                {
                    printf("Already on record.\n");
                    alreadyOnList = 1;
                    while(getchar() != '\n');/*retrieve invalid input*/
                    break;
                }
            }
            if(!isValid || *studentId < 10000 || *studentId > 99999)
            {
                printf("Student ID must be 5 digits.\n");
                isValid = 0;
                while(getchar() != '\n');/*retrieve invalid input*/
            }
        }while(!isValid || alreadyOnList);
    }
    return studentId;
}