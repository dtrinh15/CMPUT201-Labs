#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentList.h"
Student *addStudent(int availableSpots){
    Student *newStudent = malloc(sizeof(Student));
    char tempString[MAX_STRING_SIZE];
    int studentID = 0;
    int size = 0;
    char name[20];
    
    printf("Enter ID to add(%d spots available): ", availableSpots);
    fgets(tempString,MAX_STRING_SIZE,stdin);
    studentID = atoi(tempString);

    //Make sure the input is a proper integer.
    while(tempString[0] != '0' && studentID == 0){
        printf("Not a valid ID, please try again: ");
        fgets(tempString,MAX_STRING_SIZE,stdin);
        studentID = atoi(tempString);
    }
    
    printf("Enter name: ");
    fgets(name,MAX_STRING_SIZE,stdin);
    //Makes sure the input can never exceed the array.
    size = strlen(name);
    if(size == MAX_STRING_SIZE - 1){
        while(getchar() != '\n');
    }
    
    //Makes sure the string is null terminated.
    for(int i = 0; i < size;i++){
        if(name[i] == '\n'){
            name[i] = '\0';
        }
    }

    newStudent->studentID = studentID;
    strncpy(newStudent->name,name, MAX_STRING_SIZE);
    return newStudent; 
}

void removeStudent(Student **studentClass, int remove, int currentSize, int *availableSpots){
    Student *temp = NULL;
    for(int i = 0; i < currentSize;i++){
        if(studentClass[i]->studentID == remove){
            free(studentClass[i]);
            studentClass[i] = temp;
            (*availableSpots)++;
            return;
        }
    }
    printf("ID was not found\n");
    return;
}

void freeMemory(Student **studentClass, int currentMemory){
    for(int i = 0; i < currentMemory;i++){
        if(studentClass[i] != NULL){
        free(studentClass[i]);
        }
    }
    free(studentClass);    
}