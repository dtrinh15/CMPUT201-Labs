#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *add_to_list(struct node *list, int n, char marker){
	struct node *new_node;
	new_node = malloc(sizeof(struct node));

	if(new_node == NULL){
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->marker = marker;
	new_node->next = list;

	return new_node;
}

struct node *find_last(struct node *list, int n){
	struct node *found = NULL;

	if(list == NULL){
		return list;
	}

	while(list->next != NULL){
		if(list->value == n){
			found = list;
		}
		list = list->next;
	}

	if(list->next == NULL && list->value == n){
		return list;
	}
	
	if(found != NULL){
		return found;
	}

	return NULL;
}

//linked list deconstructor
void freeMemory(struct node *list){
	struct node *tmp;
	tmp = list;

	if(list == NULL){
		return;
	}
	
	while(list->next != NULL){
		list = list->next;
		free(tmp);
		tmp = list;
	}

	free(tmp);
	return;

}