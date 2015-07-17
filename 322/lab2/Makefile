# L G
# Project: Launch-Tube

FLAGS=-g
CC=gcc

all: tube launch

tube:
	$(CC) $(FLAGS) -c $@.c
	$(CC) $(FLAGS) -o $@ $@.o

launch:
	$(CC) $(FLAGS) -c $@.c
	$(CC) $(FLAGS) -o $@ $@.o

clean:
	rm -f launch tube *.o *~
