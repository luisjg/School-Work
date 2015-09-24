#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *inputFile;
	int n;
	inputFile = fopen("input.txt", "r");

	while(fgetc(inputFile) != -1){
		n = fgetc(inputFile);
		fprintf(stdout, "%d\n", n);
	}
	fclose(inputFile);
	return 0;
}