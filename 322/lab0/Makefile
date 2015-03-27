# Name: Luis Guzman
# Project: Time and Forking Children

FLAGS=-g
CC=gcc

all: one-zero

one-zero:
	$(CC) $(FLAGS) -c $@.c
	$(CC) $(FLAGS) -o $@ $@.o

run:
	./one-zero filename

clean:
	rm -f one-zero *.o *~