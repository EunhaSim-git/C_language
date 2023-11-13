/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* List of source and header files: header.h, main.c, validateStudentId.c, validateCourseId.c, registerStudents.c, displayRegis.c, dropCourse.c
* Demo malloc(), calloc() and free() in C, Ansi-style, 
*       arrays, pointers, functions, header files, user inputs, and formatting output among other things.
**********************************************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
/**********************************************************************************************************************************************
*Function name: main
*Purpose: allocating memory using malloc(), display main menu to test the menu options. free all dynamically created arrays at last.
*Function In parameters: void
*Function Out parameters: 0
*Version: 0
*Author: Eunha Sim
**********************************************************************************************************************************************/
int main() {
    int i, j, numOfStudents, numOfCourses;
    int menu = 0, isValid = 0;

    int *studentId;
    char *courseId;
    int** registerTable;
    int* regisStatus;
    int regisIndex = 0;/*index counter for registerTable*/
   
    printf("Welcome to Student Registration System.\n\n");
    
    while(isValid == 0)/*loop for valid integer input*/
    {
        printf("Enter the number of students to register: ");
        isValid = scanf("%i", &numOfStudents);
        if(isValid == 0)
        {
            printf("Please enter integer.\n");
            while(getchar() != '\n');
            continue;
        }
    }
    
    studentId = validateStudentId(numOfStudents);/*invoke the function to handle validation and store in the array*/

    isValid = 0;
    while(isValid == 0)/*loop for valid integer input*/
    {
        printf("\nEnter the number of courses available: ");
        isValid = scanf("%d", &numOfCourses);
        if(isValid == 0)
        {
            printf("Please enter integer.\n");
            while(getchar() != '\n');
            continue;
        }
    }
    
    courseId = validateCourseId(numOfCourses);/*invoke the function to handle validation and store in the array*/

    regisStatus = (int*)malloc(numOfStudents * numOfCourses * sizeof(int));
    if (regisStatus == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 0;
    }

    registerTable = (int**)malloc(numOfStudents * sizeof(int*));/*memory allocating for registerTable*/
    if (registerTable == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    for(i = 0; i < numOfStudents; i++)/*allocate memory for each row*/
    {
        registerTable[i] = (int*)malloc(numOfCourses * sizeof(int));
        if (registerTable[i] == NULL) 
        {
            printf("Memory allocation failed.\n");
            return 0;
        }
    }

    for(i = 0; i < numOfStudents; i++)
    {
        for(j = 0; j < numOfCourses; j++)
        {
            registerTable[i][j] = -1;
        }
    }

    printf("\n");
    while(menu != 4)
    {
        printf("Main Menu:\n");
        printf(" [1] Register a student into a course.\n");
        printf(" [2] Drop a student from a course.\n");
        printf(" [3] Display Registration table.\n");
        printf(" [4] Exit.\n");
        printf(" Enter an option from the menu: ");
        scanf("%i", &menu);

        switch (menu)
        {
            case 1:
                regisIndex = registerStudents(studentId, numOfStudents, courseId, numOfCourses, registerTable, regisStatus, regisIndex);
                break;
            case 2:
                displayRegis(studentId, numOfStudents, courseId, numOfCourses, registerTable, regisStatus, regisIndex);
                dropCourse(registerTable, regisStatus, regisIndex);
                displayRegis(studentId, numOfStudents, courseId, numOfCourses, registerTable, regisStatus, regisIndex);
                break;
            case 3:
                displayRegis(studentId, numOfStudents, courseId, numOfCourses, registerTable, regisStatus, regisIndex);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                while(getchar() != '\n');
                printf("Please enter from 1 to 4");
                break;
        }
    }
    free(studentId);
    free(courseId);
    for(i = 0; i <numOfStudents; i++)
    {
        free(registerTable[i]);
    }
    free(regisStatus);
    return 0;
}