# Name: Luis Guzman
# Project: Elephant

all: matrix_add matrix_gen

matrix_add:
	$(CC) -c $@.c
	$(CC) -o $@ $@.o

matrix_gen:
	$(CC) -c $@.c
	$(CC) -o $@ $@.o

clean:
	rm -f matrix_add matrix_gen *.o *~