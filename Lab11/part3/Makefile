rotate: rotate.o rotate_main.o
	gcc -Wall -std=c99 -o rotate rotate.o rotate_main.o

rotate.o: rotate.h rotate.c
	gcc -Wall -std=c99 -c rotate.c

rotate_main.o: rotate.h rotate_main.c
	gcc -Wall -std=c99 -c rotate_main.c

clean:
	rm -f *.o core
