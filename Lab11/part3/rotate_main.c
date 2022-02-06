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

Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : April 9th, 2021
******************************************************/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rotate.h"

void check(unsigned int input, int bits, unsigned int expected_output_left, unsigned int expected_output_right)
{
    
    printf("Rotate 0x%x left by %d. Expected: 0x%x - ", input, bits, expected_output_left);
    assert(rotate_left(input, bits) == expected_output_left);
    printf("Pass\n");
    printf("Rotate 0x%x right by %d. Expected: 0x%x - ", input, bits, expected_output_right);
    assert(rotate_right(input, bits) == expected_output_right);
    printf("Pass\n");
}

int main(int argc, char* argv[]){
    unsigned int input, expected_output_left,expected_output_right;
    int bits;

    if (argc != 2)
    {
        printf("Usage: ./rotate.c number\n");
        return -1;
    }
    int test = atoi(argv[1]);
    switch(test) 
    {
    case 0:
        input = 0x55667788;
        bits = 1;
        expected_output_left = 0xaaccef10;
        expected_output_right = 0x2ab33bc4;
        check(input, bits, expected_output_left,expected_output_right);
        break;
    case 1:
        input = 0x12349876;
        bits = 12;
        expected_output_left = 0x49876123;
        expected_output_right = 0x87612349;
        check(input, bits, expected_output_left,expected_output_right);
        break;
    case 2:
        input = 0x66667777;
        bits = 8;
        expected_output_left = 0x66777766;
        expected_output_right = 0x77666677;
        check(input, bits, expected_output_left,expected_output_right);
        break;
    case 3:
        input = 0x25667782;
        bits = 10;
        expected_output_left = 0x99de0895;
        expected_output_right = 0xe089599d;
        check(input, bits, expected_output_left,expected_output_right);
        break;
    }

    return 0;
}
