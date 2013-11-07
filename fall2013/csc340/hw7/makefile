CC = g++
CFLAGS = -g -Wall

default: list

list:	list.o testList.o
	$(CC) $(CFLAGS) -o list list.o testList.o

list.o:	testList.cpp list.h listException.h
	$(CC) $(CFLAGS) -c list.cpp

testList.o:	list.o list.h listException.h
	$(CC) $(CFLAGS) -c testList.cpp

clean:
	$(RM) list *.o *~

