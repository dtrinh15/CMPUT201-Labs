student_class: studentList.o student_class.o
	gcc -std=c99 -Wall -o student_class student_class.o studentList.o

student_class.o: student_class.c studentList.h
	gcc -std=c99 -Wall -c -o student_class.o student_class.c

studentList.o: studentList.h studentList.c
	gcc -std=c99 -Wall -c -o studentList.o studentList.c

clean:
	rm -f *.o studentClass core