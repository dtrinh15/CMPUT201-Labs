#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(){
	
	struct node *linked_list = NULL;
	linked_list = add_to_list(linked_list, 5, 'a');
	linked_list = add_to_list(linked_list, 10, 'b');
	linked_list = add_to_list(linked_list, 4, 'c');
	linked_list = add_to_list(linked_list, 10, 'd');
	linked_list = add_to_list(linked_list, 5, 'e');
	linked_list = add_to_list(linked_list, 7, 'f');
	linked_list = add_to_list(linked_list, 5, 'g');
	linked_list = add_to_list(linked_list, 3, 'h');
	int search_number;
	printf("Enter number you want to search for:");
	scanf("%d", &search_number);

	struct node *last_node = find_last(linked_list, search_number);
	if (last_node != NULL)
	{
		printf("Node found: value = %d and marker = %c\n", last_node->value, last_node->marker);
	}else{
		printf("Number not found!\n");
	}
	
	freeMemory(linked_list);
	return 0;
	//running your program using valgrind will show you memory leaks. You need to make sure
    //you free any allocated memory before you exit the program
}

