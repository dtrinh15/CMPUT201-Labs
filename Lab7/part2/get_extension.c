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

Name : get_extension.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : March 6th, 2021
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20
static char *extensions[] = {".txt", ".out", ".bkp", ".dot", ".tx"};

int get_extension(const char *file_name);

int main(int argc, char* argv[]){
	

	//simplifying things and not doing any argument validation
    if(argv[1] == NULL){
        fprintf(stderr,"No file input");
        exit(EXIT_FAILURE);
    }

    printf("The index value of the extension of the input file is: %d\n", get_extension(argv[1]));
}

int get_extension(const char *fileName){
    int len = strlen(fileName);
    int count = 0;
    int extensionSize = sizeof(extensions)/sizeof(extensions[0]);
    fileName += len;

    //Finds the extension with pointers
    while(*fileName != '.'){
        fileName--;
        count++;
    }

    //Compares the extension with the static extension array.
    for(int i = 0; i < extensionSize; i++){
        if((strcmp(fileName,extensions[i]) == 0)){
            fileName -= (len - count);
            return i;
        }
    }
    return -1;
}