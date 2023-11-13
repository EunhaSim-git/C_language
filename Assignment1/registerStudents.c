/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: registerStudents.c
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Prompts user list of studentId and courseId to register a student in conjunction with the course chosen.
            handle input validation, add 0 to registerTable when successfully registered otherwise prompt message
**********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: registerStudents
*Purpose: Display lists of studentIds and courseIds,
            register a student to registerTable if student is not registered and not dropped from a course
*Function In parameters: studentId - an array that holds studentIds, numOfStudents - number of studentIds
                        courseId - an array that holds courseIds, numOfCourses - number of CourseIds
                        registerTable - 2D array that holds studentId and courseId arrays
                        regisStatus - an array to hold registration status 0 as dropped 1 as registered
                        regisIndex - length of registerTable
*Function Out parameters: regisIndex - to keep track of number of registered students
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/

int registerStudents(int* studentId, int numOfStudents, char* courseId, int numOfCourses, int** registerTable, int* regisStatus, int regisIndex) {
    int i, isValid;
    int courseDigits = 8;
    int studentToRegister;
    char courseToRegister[8];
    int studentIndex, courseIndex;

    printf("List of Student Ids\n");
    for (i = 0; i < numOfStudents; i++)
    {
        printf("Index %i\t\t%d\n", i, studentId[i]);
    }

    isValid = 1;
    do
    {
        printf("Enter the Student's Id to register a course: ");
        isValid = scanf("%5d", &studentToRegister);
        if((!isValid) || getchar() != '\n'|| (studentToRegister < 10000) || (studentToRegister > 99999))
        {
            printf("Student ID must be 5 digits.\n");
            isValid = 0;
            while(getchar() != '\n');/*retrieve invalid input*/
        }
    }while(!isValid);

    printf("List of Available Course Id\n");
    for (i = 0; i < numOfCourses; i++)
    {
        printf("Index %i\t\t%8s\n", i, (courseId + (i * courseDigits)));
    }

    do
    {
        printf("Enter the course id [3-Alphas][4-digits]: ");
        isValid = scanf("%7s", courseToRegister);
        if(isValid == 0 || strlen(courseToRegister) < 7 || getchar() != '\n')
        {
            printf("Incorrect Course Id length [7-charcater Id]\n");
            isValid = 0;
            while (getchar() != '\n');
        }
    }while(!isValid);

    studentIndex = -1;/*set up to find the entered studentId and courseId*/
    courseIndex = -1;
    
    for(i = 0; i < numOfStudents; i++)
    {
        if(studentId[i] == studentToRegister)
        {
            studentIndex = i;
            break;
        }
    }

    for(i = 0; i <numOfCourses; i++)
    {
        if(strcmp((courseId + (i * courseDigits)), courseToRegister) == 0)
        {
            courseIndex = i;
            break;
        }
    }

    if(studentIndex != -1 && courseIndex != -1)
    {
        if(registerTable[studentIndex][courseIndex] == 0)/*registration status in registerTable is dropped from the course*/
        {
            printf("Student id %5i have dropped out from course %7s.\n", studentId[studentIndex], (courseId + (courseIndex * courseDigits)));
            printf("Student id %5i cannot register to course course %7s.\n", studentId[studentIndex], (courseId + (courseIndex * courseDigits)));
            printf("Registration unsuccessful\n");
            return regisIndex;
        }
        else if(registerTable[studentIndex][courseIndex] == 1)/*already in registerTable*/
        {
            printf("Already on record.\n");
            printf("Student id %5i cannot register to course %7s.\n", studentId[studentIndex], (courseId + (courseIndex * courseDigits)));
            printf("Registration unsuccessful\n");
            return regisIndex;
        }/*update into registerTable*/
        registerTable[studentIndex][courseIndex] = 1;
        regisStatus[regisIndex] = registerTable[studentIndex][courseIndex];
        regisIndex++;
        printf("Registration Successful\n");
    }
    else
    {
        printf("Student id or Course id does not exist.\n\n");
    }
    return regisIndex;
}