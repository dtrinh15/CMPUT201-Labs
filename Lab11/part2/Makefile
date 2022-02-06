queue_client: queue.o queue_client.o
	gcc -Wall -std=c99 -o queue_client queue.o queue_client.o

queue.o: queue.h queue.c
	gcc -Wall -std=c99 -c queue.c

queue_client.o: queue.h queue_client.c
	gcc -Wall -std=c99 -c queue_client.c

clean:
	rm -f *.o core
