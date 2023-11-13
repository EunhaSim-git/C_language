/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: validataCourseId.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Prompt user to enter in courseId as numOfcourses. 
            Handle validation for courseId
**********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: validateCourseId
*Purpose: Loops until user enters a courseId in required format as [3-Alphas][4-digits]
            allocate memory dynamically to courseId to copy from input[] 
*Function In parameters: numOfCourses - number of courseIds in total
*Function Out parameters: courseId - an array that holds valid courseIds
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/

char* validateCourseId(int numOfCourses) {
    int i, j, isValid, alreadyOnList;
    int courseDigits = 8;/*actual length + '/0' null terminater*/
    char* courseId;
    char input[8];

    courseId = (char*)malloc(numOfCourses * courseDigits);
    if (courseId == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    for (i = 0; i < numOfCourses; i++)
    {
        do
        {
            isValid = 1;
            alreadyOnList = 0;
            printf("Enter the course index[%i] course id [3-Alphas][4-digits]: ", i);
            isValid = scanf("%7s", input);

            for (j = 0; j < i; j++)
            {
                if(strcmp(courseId + (j * courseDigits), input) == 0)
                {
                    printf("Already on record.\n");
                    alreadyOnList = 1;
                    break;
                }
            }
            if(!isValid || strlen(input) < 7 || getchar() != '\n')/*validate length*/
            {
                printf("Incorrect Course Id length [7-charcater Id]\n");
                while (getchar() != '\n');
                isValid = 0;
                continue;
            }
            else
            {
                for (j = 0; j < 3; j++)/*loop to get 3 character digits*/
                {
                    if (!isalpha(input[j]))
                    {
                        isValid = 0;
                        break;/*out of current for-loop to get courseId again*/
                    }
                }
                if(isValid)
                {
                    for (j = 3; j < 7; j++)/*loop to get 4 int digits*/
                    {           
                        if (!isdigit(input[j]))
                        {
                            isValid = 0;
                            break;/*out of current for-loop to get courseId again*/
                        }
                    }
                }
                if(!isValid)
                {
                    printf("Incorrect Course Id input [3-Alphas][4-digits]\n");
                }
                else
                {
                    strcpy(courseId + (i * courseDigits), input);/*copy a courseId from input array*/   
                }
            }
        }while(!isValid || alreadyOnList);/*loop if storing a valid courseId fails*/
    }
    return courseId;
}