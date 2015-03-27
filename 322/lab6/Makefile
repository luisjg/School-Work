# Name: Luis Guzman
# Project: Daemon

FLAGS=-g
CC=gcc

all: mole spiritd

mole:
	$(CC) $(FLAGS) -c $@.c
	$(CC) $(FLAGS) -o $@ $@.o

spiritd:
	$(CC) $(FLAG) -c $@.c
	$(CC) $(FLAG) -o $@ $@.o

run:
	./spiritd

clean:
	rm -f mole spiritd lab6.log *.o *~