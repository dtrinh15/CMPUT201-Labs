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

Name : random_walk.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : February 4th, 2021 
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define DIRECTION 4;
void generate_random_walk(int n, int m, char walk[n][m]);
void print_array(int n, int m, char walk[n][m]);

int main(void){
    int rows = 0, columns = 0;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    char walk[rows][columns];

    generate_random_walk(rows,columns,walk);
    return 0;
}

void generate_random_walk(int n, int m, char walk[n][m]){
    int rows = 0, columns = 0;
    bool upBlocked = false,downBlocked = false, leftBlocked = false, rightBlocked = false;
    char letter = 'A';
    int randomDirection;

    if(n == 0 || m == 0){// Closes the program if n and m are not an integer that is > 0.
        printf("\nRow and/or Columns were initialized at 0, terminating program.\n");
        exit(EXIT_FAILURE);
    } 

    for(int rows = 0; rows < n;rows++){//Initializes every value in the 2d array to '.'
        for(int columns = 0; columns < m;columns++){
            walk[rows][columns] = '.';
        }
    }    

    walk[0][0] = letter;
    srand( (unsigned) time(NULL));
    while(rows < n && columns < m && rows >= 0 && columns >= 0 && letter < 'Z'){//Stops looping once rows,columns or 'Z' is out of bounds.
        if(upBlocked && downBlocked && leftBlocked && rightBlocked){//If every direction is blocked, leave the while loop.
            break;
        }
        randomDirection = rand() % DIRECTION;//Gives the program a random direction represented by 0-3.
        switch(randomDirection){ 
            case 0:
                if(rows-1 >= 0 && walk[rows-1][columns] == '.'){//Moves up
                    upBlocked = false, downBlocked = false, leftBlocked = false, rightBlocked = false;//If the x or y is moved, reset the blocked checks.
                    rows--;
                    letter++;
                    walk[rows][columns] = letter;
                    break;
                }
                upBlocked = true;//If the position can't be reached, the position "up" is blocked.
                break;
            case 1:
                if(rows+1 < n && walk[rows+1][columns] == '.'){//Moves down
                    upBlocked = false, downBlocked = false, leftBlocked = false, rightBlocked = false;
                    rows++;
                    letter++;
                    walk[rows][columns] = letter;
                    break;
                }
                downBlocked = true;//If the position can't be reached, the position "down" is blocked.
                break;                
            case 2:
                if(columns-1 >= 0 && walk[rows][columns-1] == '.'){//Move left
                    upBlocked = false, downBlocked = false, leftBlocked = false, rightBlocked = false;
                    columns--;
                    letter++;
                    walk[rows][columns] = letter;
                    break;
                }
                leftBlocked = true;//If the position can't be reached, the position "left" is blocked.
                break;
            case 3:
                if(columns+1 < m && walk[rows][columns+1] == '.'){//Move right
                    upBlocked = false, downBlocked = false, leftBlocked = false, rightBlocked = false;
                    columns++;
                    letter++;
                    walk[rows][columns] = letter;
                    break;
                }
                rightBlocked = true;//If position can't be reached, the position "right" is blocked.
                break;      
        }
    }   
    printf("Walked until letter %c\n\n", letter);
    print_array(n,m,walk);
}

void print_array(int n, int m, char walk[n][m]){//Prints the array
    for(int rows = 0; rows < n ;rows++){
        for(int columns = 0; columns < m; columns++){
            printf("%c " , walk[rows][columns]);
        }
        printf("\n");
    }
}