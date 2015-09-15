#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *inputFile;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int n;
	inputFile = fopen("input.txt", "r");
	if(inputFile == NULL)
		exit(EXIT_FAILURE);
	while((read = getline(&line, &len, inputFile)) != -1){
		fprintf(stdout, "%s", line);
	}
	free(line);
	fclose(inputFile);
	return 0;
}