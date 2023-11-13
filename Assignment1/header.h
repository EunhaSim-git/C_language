/**********************************************************************************************************************************************
* Title: Assignment #1 - Student Registration System
* File name: header.h
* Course: CST8234 C Language
* @Author: <<< Eunha Sim (041-078-020) >>>
* Lab Section: 301
* Professor: Natalie Gluzman
* Due date: 11/22/2023
* Submission date: 11/08/2023
* Purpose: Declare all functioin prototypes
**********************************************************************************************************************************************/

int* validateStudentId (int numOfStudents);
char* validateCourseId(int numOfCourses);
int registerStudents(int* studentId, int numOfStudents, char* courseId, int numOfCourses, int** registerTable, int* regisStatus, int regisIndex);
void displayRegis(int* studentId, int numOfStudents, char* courseId, int numOfCourses, int** registerTable, int* regisStatus, int regisIndex);
void dropCourse(int** registerTable, int* regisStatus, int regisIndex);
