qsort: qsort.o quicksort.o
	gcc -std=c99 -Wall -o qsort quicksort.o qsort.o
qsort.o: quicksort.c qsort.c
	gcc -std=c99 -Wall -c qsort.c
quicksort.o: quicksort.c quicksort.h
	gcc -std=c99 -Wall -c quicksort.c
clean: 
	rm *.o -f qsort core