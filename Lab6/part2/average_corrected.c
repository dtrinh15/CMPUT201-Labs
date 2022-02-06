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

Name : average_corrected.c
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

#define MAX_SIZE 20 /* maximum 20 digits in file */
#define MAX_LINE 6 /* maximum 4 digits (+ 1 for newline) for each number. fgets reads n-1 chars*/

void read_numbers(FILE* fp, int numbers[], int* size){

	*size = 0;
	char line[MAX_LINE];

	while(fgets(line, MAX_LINE , fp) != NULL){
    	numbers[(*size)++] = atoi(line); //note that this is missing error checking
  	}
}

double average(FILE* fp, char* fileName){
	int size;
	int numbers[MAX_SIZE];
	double sum = 0;

	read_numbers(fp, numbers, &size);

	for(int i = 0; i < size; i++){
		sum += numbers[i];
	}
	return sum/size;
}

int main(int argc, char* argv[]){
	
	if (argc != 2){
    	fprintf(stdout, "Usage: ./avg <input_file>\n");
    	exit(EXIT_FAILURE);
	}

	FILE* input;

	input=fopen(argv[1], "r");
	if (input == NULL){
		fprintf(stderr, "Problem opening file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	double avg;
	avg = average(input, argv[1]);
	printf("The average is %g\n", avg);

	return 0;

}
