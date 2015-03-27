#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// void matrix_add(char block[][], int size, int scalar);

int main(int argc, char* argv[]){
	time_t startTime = time(NULL);
	srand(time(NULL));
	int scalar = (rand() % 101) + 1;
	int blockSize = argc / ( sizeof(argv) / sizeof(argv[0]));
	time_t endTime = time(NULL);
	int elapsedTime = endTime-startTime;
	fprintf(stdout, "TIME: %d\n", elapsedTime );
	return 0;
}

/*void matrix_add(char block[][],int size,int scalar){
	int i,j;
	for(i=0; i<size; i++)
		for(j=0; j<size; j++)
			block[i][j] += scalar;
}*/