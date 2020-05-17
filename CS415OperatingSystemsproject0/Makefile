

TARGET = anagram anagramtest
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall 


all: anagram anagramtest

anagram.o: anagram.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

anagram: anagram.o main.o
	$(CC) -Wall $(LIBS) $^ -o $@

anagramtest: anagram.o test.o
	$(CC) -Wall $(LIBS) $^ -o $@

clean:
	-rm -f *.o
	-rm -f anagram anagramtest
