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

Name : search.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : January 26, 2021 
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    FILE *fp = fopen(argv[1], "r");
    char alphabet[26];
    char charArr[10];
    int count[26] = {0};
    int threshold = 0;
    bool passedThreshold = false;

    if(fp == NULL){ //Error if the file has not been opened.
        fprintf(stderr, "Error: cannot find %s", argv[1]);
        exit(EXIT_FAILURE);
    }else{
        if(argc <= 2 || argc > 3){ //Error is thrown if the incorrect number of arguments is given.
            fprintf(stderr, "Usage: ./search <input file> <threshold>");
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        threshold = atoi(argv[2]);
        while(!feof(fp)){ //Loops until the end of the file is reached.
            fscanf(fp, "%s", charArr);
            for(int i = 0; charArr[i] != '\0'; i++){
                alphabet[charArr[i]-'a'] = charArr[i]; //subtracts the ascii value of the character.
                count[charArr[i]-'a'] = count[charArr[i]-'a'] + 1; //counts how many times the character is repeated in the file.
            }
        }
    }
    
    for(int i = 0; i < 26;i++){ //Checks if any of the characters count surpasses the thershold given.
        if(count[i] > threshold){
            printf("%c appears %d times\n", alphabet[i], count[i]);
            passedThreshold = true;
        }
    }

    if(passedThreshold == false){//If the threshold is not passed, return this message.
        printf("There are no letters that exceed this threshold");
    }

    fclose(fp);
    return 0;

}