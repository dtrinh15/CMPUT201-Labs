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

Name : palindrome.c
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
#include <string.h>

int check_palindrome(char *str, int len);

int main(){
    char *p;
    char str[101];
    int len;
    int isPalindrome = 0;

    printf("Enter a message: ");
    fgets(str,101,stdin);
    p = str;
    len = strlen(p);

    //If the string has a newline, replace it with '\0'
    while(*p != '\0'){
        if(*p == '\n'){
            *p = '\0';
        }
        p++;
    }

    p -= len;
    len -= 1;
    isPalindrome = (check_palindrome(p, len));

    if(isPalindrome == 1){
        printf("Palindrome");
    }else{
        printf("Not a palindrome");
    }
}

int check_palindrome(char *str, int len){
    char *strEnd = str + (len-1);
    int convertToLower = 32;
    //Converts all letters in a string into lowercase.
    while (*str != '\0'){
        if(*str >= 'A' && *str <= 'Z'){
            *str += convertToLower;
        }
        str++;
    }
    str -= len;
    //If the string has 1 letter, it is a palindrome.
    if(len == 1 && *str >= 'a' && *str <= 'z'){
        return 1;
    }

    while(*str != '\0'){  
                if(str == strEnd){
            return 1;
        }
        //As long as the 2 pointers have the same character, it is a palindrome.
        if(*str == *strEnd){
            str++;

            strEnd--; 
        }else{         
            //If the current character being pointed to is not a letter, skip it.
            while(*str < 'a' || *str > 'z'){
                str++;
            }

            while(*strEnd < 'a' || *strEnd > 'z'){
                strEnd--;    
            }
            if(*str != *strEnd){
                return 0;
            }        
        }
    }
    return 1;
}