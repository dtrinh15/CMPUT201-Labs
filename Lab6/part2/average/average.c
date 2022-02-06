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
	
	for(int i = 0; i < size++; i++)
		sum += numbers[i];

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
