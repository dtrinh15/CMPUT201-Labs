#ifndef STUDENTLIST
#define STUDENTLIST
#define MAX_STUDENTS 5
#define MAX_STRING_SIZE 20

typedef struct Student{
    int studentID;
    char name[MAX_STRING_SIZE];
} Student;

Student *addStudent(int n);
void removeStudent(Student **studentClass,int remove, int currentSize, int *availableSpots);
void  freeMemory(Student **studentClass,int n);
#endif