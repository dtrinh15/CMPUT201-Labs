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

Name : reverse_half.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : February 28th, 2021
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100

int main(){
    char message[ARRAY_SIZE], *index;
    int size = 0;
    char ch;
    index = message;
    printf("Enter a message: ");

    //Gets the next character until the nextline or the size of the string exceeds 100 characters.
    while(ch != '\n' && size < 100){
        ch = getchar();
        if(ch != '\n'){
            *index = ch;
            index++;
            size++;
        }
    }
    
    //Checks for odd and even indexes for rounding issues.
    if(size%2){
        size = size/2;
        index -= size + 1;
    }else{
        size = size/2;
        index -= size;
    }

    while(size > 0){
        index--;
        size--;
        printf("%c", *index);
    }
    printf("\n");
    return 0;
}