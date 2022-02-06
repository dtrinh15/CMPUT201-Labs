check_nesting: stack.o check_nesting.o
	gcc -std=c99 -Wall -o check_nesting stack.o check_nesting.o

check_nesting.o: check_nesting.c stack.c
	gcc -std=c99 -Wall -c check_nesting.c

stack.o: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c

clean:
	rm -f *.o check_nesting core