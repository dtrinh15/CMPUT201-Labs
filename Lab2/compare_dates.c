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

Name : compare_dates.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : January 22, 2021 
******************************************************/
#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    int mmIn, ddIn, yyIn;
    int mm,dd,yy;

    
    if(fp == NULL){//File doesn't exist
        fprintf(stderr, "ERROR: the file does not exist or was not inputted\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d%d%d", &mmIn, &ddIn, &yyIn);
    printf("Enter date to compare(mm/dd/yy): ");

    if (scanf("%d/%d/%d", &mm,&dd,&yy) == 3){ // Checks if scanf receives 3 inputs with the correct data type using the '/' as a delimiter for each input.
        if(yy > 0 && yy <= 99){ // Checks if yy is inbetween 1 and 99
            switch (mm) {
                case 1: //January
                case 3: //March
                case 5: //May
                case 7: //July
                case 8: //August
                case 10: //October
                case 12: //December
                    if(dd <= 0 || dd > 31){ //Checks if the days are greater than 31 in months above
                        fprintf(stderr, "Wrong date format\n");
                        fclose(fp);
                        exit(4);
                    }
                    break;
                case 4: //April
                case 6: //June
                case 9: //September
                case 11: //November
                    if(dd <= 0 || dd > 30){ //Checks if the days are greater than 30 in the months above
                        fprintf(stderr, "Wrong date format\n");
                        fclose(fp);
                        exit(4);
                    }
                    break;
                case 2: //February
                    if(dd <= 0 || dd > 28){ // Checks if the days are greater than 28 in February
                        fprintf(stderr, "Wrong date format\n");
                        fclose(fp);
                        exit(4);
                    }
                    break;
                default: //Default error if month value is < 0 or > 12
                    fprintf(stderr, "Wrong date format\n");
                    fclose(fp);
                    exit(4);
            }
        }else{ //Error message if year is below 1 or greater than 99
            fprintf(stderr, "Wrong date format\n");
            fclose(fp);
            exit(4);
        }
    }else{ //If 3 inputs of the correct data type with '/' as the delimiters is not received, give error.
        fclose(fp);
        fprintf(stderr, "Wrong date format/n");
        exit(4);
    }

    if(yyIn > yy){//Checks year, then month, then day to see which date is earlier.
        fprintf(stdout, "%d/%d/%d is earlier than %d/%d/%d\n", mm, dd, yy, mmIn, ddIn, yyIn);
    }else{
        if(mmIn > mm){
            fprintf(stdout, "%d/%d/%d is earlier than %d/%d/%d\n", mm, dd, yy, mmIn, ddIn, yyIn);        
        }else{
            if(ddIn > dd){
                fprintf(stdout, "%d/%d/%d is earlier than %d/%d/%d\n", mm, dd, yy, mmIn, ddIn, yyIn);                
            }else if(ddIn == dd && mmIn == mm && yyIn == yy){
                fprintf(stdout, "%d/%d/%d is equal to %d/%d/%d\n", mm, dd, yy, mmIn, ddIn, yyIn);     
            }else{
                fprintf(stdout, "%d/%d/%d is earlier than %d/%d/%d\n", mmIn, ddIn, yyIn, mm, dd, yy);                   
            }
        }   
    }

    fclose(fp);
    return 0;
}