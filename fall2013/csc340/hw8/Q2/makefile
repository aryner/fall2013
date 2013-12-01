CC = g++
CFLAGS = -g -Wall

default: list

list: linkedList.o linkedTest.o
	$(CC) $(CFLAGS) -o list linkedList.o linkedTest.o

linkedList.o: linkedTest.o linkedList_structNode.h listException.h
	$(CC) $(CFLAGS) -c linkedList.cpp

linkedTest.o: linkedList.cpp linkedList_structNode.h listException.h
	$(CC) $(CFLAGS) -c linkedTest.cpp

clean:
	$(RM) list *.o *~
