#ifndef __LINKED_LIST__
#define __LINKED_LIST__

struct node{
    int value;
    char marker;
    struct node *next;
};


struct node *add_to_list(struct node *list, int n, char marker);
struct node *find_last(struct node *list, int n);
void freeMemory(struct node *list);
#endif