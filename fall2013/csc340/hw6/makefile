CC = g++
CFLAGS = -g -Wall

default: hw6

hw6:	hw6.o hw6test.o
	$(CC) $(CFLAGS) -o hw6 hw6.o hw6test.o

hw6.o:	hw6test.cpp hw6.h
	$(CC) $(CFLAGS) -c hw6.cpp

hw6test.o:	hw6.o hw6.h
	$(CC) $(CFLAGS) -c hw6test.cpp

clean:
	$(RM) hw6 *.o *~
