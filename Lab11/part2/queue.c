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

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct node
{
    Item data;
    struct node *next;
};

struct queue_type
{
    struct node* front;
    struct node* end;
};

void enqueue(Queue *queue, Item x)
{
    struct node *newNode;
    if(*queue == NULL){
        *queue = malloc(sizeof(struct queue_type));
        if(*queue == NULL){
            printf("Error: Queue not initialized\n");
            exit(EXIT_FAILURE);
        }
        (*queue)->end = NULL;
        (*queue)->front = NULL;
    }
    //implement the function here 
    newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
            printf("Error: Node not initialized\n");
            exit(EXIT_FAILURE);        
    }

    newNode->data = x;

    if((*queue)->front == NULL){
        newNode->next = NULL;
        (*queue)->front = newNode;
        (*queue)->end = (*queue)->front;
    }else{
        newNode->next = ((*queue)->end);
        (*queue)->end = newNode;
    }
     
}

void dequeue(Queue *queue)
{
    struct node *tempNode;
    if((*queue)->front == NULL){
        printf("Nothing to dequeue");
        return;
    }
    
    if((*queue)->front == (*queue)->end){
        free((*queue)->front);
        free(*queue);
        *queue = NULL;
    }else{
        tempNode = (*queue)->end;
        while(tempNode->next != (*queue)->front){
            tempNode = tempNode->next;
        }

        tempNode->next = NULL;
        free((*queue)->front);
        (*queue)->front = tempNode;
    }


        //implement the function here 
}

void print_queue(Queue queue)
{   
    struct node *tempNode = queue->front;
    struct node *tempPrev = queue->end;

    if(queue->front != NULL){
        while(tempNode != queue->end){
            printf("%d\n", tempNode->data);
            while(tempPrev->next != tempNode){
                tempPrev = tempPrev->next;
            }
            tempNode = tempPrev;
            tempPrev = queue->end;
        }
        printf("%d\n", tempNode->data);
    }else{
        printf("No queue to print.");
    }
        //implement the function here 
}
