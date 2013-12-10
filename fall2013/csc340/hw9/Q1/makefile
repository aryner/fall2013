CC = g++
CFLAGS = -g -Wall

default: shapes

shapes: figure.o rectangle.o triangle.o q1Test.o 
	$(CC) $(CFLAGS) -o shapes figure.o rectangle.o triangle.o q1Test.o 

figure.o: figure.cpp figure.h
	$(CC) $(CFLAGS) -c figure.cpp

rectangle.o: rectangle.cpp rectangle.h
	$(CC) $(CFLAGS) -c rectangle.cpp

triangle.o: triangle.cpp triangle.h
	$(CC) $(CFLAGS) -c triangle.cpp

q1Test.o: q1Test.cpp figure.h rectangle.h triangle.h
	$(CC) $(CFLAGS) -c q1Test.cpp

clean:
	$(RM) shapes *.o *~

