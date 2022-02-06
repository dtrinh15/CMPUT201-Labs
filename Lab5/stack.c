/***
 * CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Derek Trinh

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.
This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.
Copying any part of this solution without including this copyright notice is illegal.
If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.
This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email addresses:
***/

/*****************************************************

Name : stack.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : February 21st, 2021
******************************************************/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

char stackArray[SIZE];
int top = 0;

void makeEmpty(){
    top = 0;
}

bool isFull(){
    return top == SIZE; 
}

bool isEmpty(){
    return top == 0;
}

void push(int bracket){
    if(isFull()){
        stackOverflow();
    }
    stackArray[top++] = bracket;
}

char pop(){
    if(isEmpty()){
        nestingError();
    }
    return stackArray[--top];
}

void stackOverflow(){
    fprintf(stderr, "Stack Overflow\n");
    exit(EXIT_FAILURE);
}

void nestingError(){
    fprintf(stderr, "Parentheses are not nested properly\n");
    exit(EXIT_FAILURE);
}