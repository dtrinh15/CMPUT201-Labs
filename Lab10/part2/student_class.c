#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentList.h"

int main(){
    int foundNull = 0;
    int remove = 0;
    int currentMemory = 2;
    int availableSpots = MAX_STUDENTS;
    Student **studentClass = malloc(currentMemory * sizeof(Student *));
    int choice = 0;

    //Checks if malloc properly allocated memory.
    for(int i = 0; i < currentMemory;i++){
        if(studentClass == NULL){
            printf("malloc failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        studentClass[i] = NULL;
    }
    
    for(;;){
        choice = 0;
        foundNull = currentMemory - 1;
        if(currentMemory > MAX_STUDENTS){
            printf("You have reached the maximum capacity of the class. You have %d students in the class:\n", MAX_STUDENTS);
            for(int i = 0; i < MAX_STUDENTS;i++){
                printf("%d, %s\n",studentClass[i]->studentID ,studentClass[i]->name);
                }
            freeMemory(studentClass,MAX_STUDENTS);
            return 0;                          
        }

        printf("Enter operation: ");
        scanf("%d", &choice);
        getchar();

        //Exit
        if(choice == 0){
            printf("You have %d students in the class\n", MAX_STUDENTS - availableSpots);
            for(int i = 0; i < currentMemory;i++){
                if(studentClass[i] != NULL){
                    printf("%d, %s\n",studentClass[i]->studentID ,studentClass[i]->name);
                }
            }
            freeMemory(studentClass,currentMemory);
            return 0;    

        //Add Student           
        }else if(choice == 1){

            //Finds the first NULL pointer
            for(int i = currentMemory - 1; i >= 0;i--){
                if(studentClass[i] == NULL){
                    foundNull = i;                
                }         
            }

            studentClass[foundNull] = addStudent(availableSpots);
            availableSpots--;
                        
            //If no NULL pointers are found within the bounds of the current array
            if(foundNull == currentMemory - 1){
                //Reallocate memory to allow another student into the class.
                currentMemory++;
                if(currentMemory <= MAX_STUDENTS){          
                    studentClass = realloc(studentClass,currentMemory*sizeof(Student *));    
                    if(studentClass == NULL){
                        printf("realloc failed to allocate memory\n");
                        exit(EXIT_FAILURE);
                    }
                studentClass[currentMemory-1] = NULL;     
                }     
            }

        //Remove Student
        }else if(choice == 2){
            printf("Enter ID to remove: ");
            scanf("%d", &remove);
            getchar();
            removeStudent(studentClass,remove,MAX_STUDENTS - availableSpots, &availableSpots);
        }
    }
    return 0;
}