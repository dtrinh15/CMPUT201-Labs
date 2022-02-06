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
Counts how many bills are needed for the dollar amount. 
Name : bill._calculator.c 
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Check eClass Contact Information page.
Lecture Section : B2
Lab Section : H01
Date : January 16, 2021 
******************************************************/

#include <stdio.h>

int main(void){
    int dollar, twenty, ten, five, one;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar); // Allows the user to input an integer using scanf.
    twenty = dollar/20;
    ten = (dollar%20)/10;
    five = (dollar%20)%10/5; //Finds the remainder of (dollar / 20) / 10, and then divide it by 5 dollar bills.
    one = ((dollar%20)%5);
    
    printf("\n $20 bills: %d\n $10 bills: %d\n $5 bills: %d\n $1 bills: %d\n", twenty, ten, five, one); //prints every type of bill onto a new line.
    return 0;
}