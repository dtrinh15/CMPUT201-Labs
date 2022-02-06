#include <stdio.h>

int main(){
    #ifdef ENGLISH
        printf("Insert Disk 1\n");
    #elif defined(FRENCH)
        printf("Inserez Le Disque 1\n");
    #elif defined(SPANISH)
        printf("Inserte El Disco 1\n");
    #else
        printf("No Supported Language chosen.\n");
    #endif
    return 0;
}