CC = g++
CFLAGS = -g -Wall

default: personnel

personnel: dayOfYear.o person.o personnel.o student.o
	$(CC) $(CFLAGS) -o personnel dayOfYear.o person.o personnel.o student.o

student.o: student.h student.cpp
	$(CC) $(CFLAGS) -c student.cpp

person.o: person.h person.cpp
	$(CC) $(CFLAGS) -c person.cpp

dayOfYear.o: dayOfYear.h dayOfYear.cpp
	$(CC) $(CFLAGS) -c dayOfYear.cpp

personnel.o: personnel.cpp student.h person.h dayOfYear.h
	$(CC) $(CFLAGS) -c personnel.cpp

clean:
	$(RM) personnel *.o *~

