#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 4096 // 4KB = 2^12 = 4096 Bytes
#define MEMSIZE 4294967296 // 2^32 addressable Bytes (32 bit address)

void printInfo();

int main(int argc, char* argv[]){
	printInfo();
	// these should all be positive numbers
	unsigned long int addressNum;
	unsigned int pageNum;
	unsigned int offSet;
	// check to see if there is a minimum of two items passed in
	if(argc > 1 && argc <= 2){
		// convert the address passed in from string to int
		// prototype
		// unsigned long int strtoul(const char *nptr, char **endptr, int base);
		addressNum = strtoul(argv[1], NULL, 10);
		if(addressNum < MEMSIZE){
			// Integer division discards the floating point
			// giving the page number
			pageNum=addressNum / PAGESIZE;
			// Integer modulus returns the remainder
			// giving the offset
			offSet=addressNum % PAGESIZE;
			// Print the address number passed in
			fprintf(stdout, "The address %d contains:\n", addressNum);
			// Print the calculated page number
			fprintf(stdout, "page number = %d\n", pageNum);
			// Print the calculated offset
			fprintf(stdout, "offset = %d\n", offSet);
		}
		else{
			// Invalid Memory location
			fprintf(stderr, "ERROR Invalid Memory Address\n");
			return 1;
		}
	}
	else{
		// Invalid arguments
		fprintf(stderr, "ERROR Please provide %s with an address\n", argv[0]);
		return 1;
	}
	return 0;
}

void printInfo(){
	// Print info about the program to the screen.
	fprintf(stdout,"\nThis program calculates the page number\n"
	 "and the offset within the page for a\nmachine with a 32-bit "
	 "virtual memory\naddress space and a 4KB page size.\n\n");
}