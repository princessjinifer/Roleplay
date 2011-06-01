# compiler to use:
CC=g++
# flags to use:
CFLAGS=-c -Wall

all: main

main: main.o shops.o hotels.o
	$(CC) main.o shops.o hotels.o -o roleplay

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

shops.o: shops.cpp
	$(CC) $(CFLAGS) shops.cpp

hotels.o: hotels.cpp
	$(CC) $(CFLAGS) hotels.cpp

clean:
	rm -rf *o
