CC=g++
CFLAGS=-c -W

main: main.o 
	${CC} main.o -o main

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp

clean:
	rm *.o main