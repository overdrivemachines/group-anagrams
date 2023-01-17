
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

group-anagrams: group-anagrams.o
	$(CC) $(CFLAGS) -o group-anagrams group-anagrams.o

group-anagrams.o: group-anagrams.cpp
	$(CC) $(CFLAGS) -c group-anagrams.cpp

clean:
	rm -rf group-anagrams group-anagrams.o
