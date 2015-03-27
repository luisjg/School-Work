# Name: Luis Guzman
# Project: Rice, Rice and Rice

CC=gcc
FLAG=-g -pthread

all: dining-p

dining-p:
	$(CC) -c $@.c $(FLAG)
	$(CC) -o $@ $@.o $(FLAG)

clean:
	rm -f dining-p *.o *~