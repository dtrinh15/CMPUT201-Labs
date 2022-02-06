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

Name : check_nesting.c
Author : Derek Trinh 
OneCard : 1680787
CCID : dtrinh1
Instructor : Sarah Nadi
TA : Ryan Hang, Rafsanjany Kushol, Michael Greber
Lecture Section : B2
Lab Section : H01
Date : February 21st, 2021
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stdbool.h"

void readInput();
void checkNesting(char firstParenthesis);

int main (){
    printf("Enter parentheses and/or braces: ");
    readInput();
    return 0;
}

void readInput(){
    char c;
    bool inputInStack;

    while(c !=  '\n'){
        c = getchar();
        
        if(c == '\n'){
            //No brackets found
            if(inputInStack != true){
                fprintf(stderr, "No parentheses/bracekts found\n");
                exit(EXIT_FAILURE);
            }

            //Stack has unbalanced brackets in it.
            if(isEmpty() != true){
                nestingError();
            }

            printf("Parentheses are nested properly\n");
        }

        //Push left hand brackets into stack
        if(c == '{' || c == '(' || c == '['){
            inputInStack = true;
            push(c);
        }

        //Push right hand brackets into stack to balance the left hand bracket
        if(c == '}' || c == ')' || c ==']'){
            inputInStack = true;
            push(c);
            checkNesting(pop());
        }
    }
}

void checkNesting(char firstParenthesis){
    char parenthesis;

    //Only one value, there can not be balance
    if(isEmpty() == true){
        if(firstParenthesis == '}' || firstParenthesis == ')' || firstParenthesis == ']'){
            nestingError();
        }
    }

    while(isEmpty() != true){
        parenthesis = pop();

        //Compares right hand parenthesis with the left hand side,
        //if both sides are right hand parenthesis, there is a nesting error
        switch(firstParenthesis){
            case '}':
                if(parenthesis == '{'){
                    return;
                }
                nestingError();
                break;
            case ')':
                if(parenthesis == '('){
                    return;
                }
                nestingError();
                break;
            case ']':
                if(parenthesis == '['){
                    return;
                }
                nestingError();
                break;
        }
    }
    return;    
}
