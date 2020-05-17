

TARGET = part1 part2 part3
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall 

all: part1 part2 part3 part4

part1.o: part1.c
	$(CC) $(CFLAGS) -c $< -o $@

part2.o: part2.c
	$(CC) $(CFLAGS) -c $< -o $@

part3.o: part3.c
	$(CC) $(CFLAGS) -c $< -o $@

part4.o: part4.c
	$(CC) $(CFLAGS) -c $< -o $@

part1: part1.o
	$(CC) -Wall $(LIBS) $^ -o $@

part2: part2.o
	$(CC) -Wall $(LIBS) $^ -o $@

part3: part3.o
	$(CC) -Wall $(LIBS) $^ -o $@

part4: part4.o
	$(CC) -Wall $(LIBS) $^ -o $@

clean:
	-rm -f *.o 
	-rm -f part1 part2 part3 part4

