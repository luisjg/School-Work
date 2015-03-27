#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXSIZE 10240 // 10 page max

int main(int argc, char* argv[]){
	if(argc <= 1){
		fprintf(stderr, "ERROR: Please provide %s with a size\n", argv[0]);
		return 1;
	}else if(atoi(argv[1]) <= MAXSIZE){
		int size = atoi(argv[1]);
		srand(time(NULL));
		int i,j;
		for(i=0; i<size; i++){
			for(j=0; j<size; j++){
				int random = (rand() % 201) + (-100);
				fprintf(stdout, "%d ", random);
			}
			fprintf(stdout,"\n");
		}
	}
	else{
		fprintf(stderr, "ERROR: Size is too big\n");
	}
	return 0;
}