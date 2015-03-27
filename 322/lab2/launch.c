#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define FORK 0
#define EXEC 1

void printHandler(int i){
	if(i == FORK)
		fprintf(stderr, "\nERROR: fork failed\n");
	if(i == EXEC)
		fprintf(stderr, "ERROR execv failed!\n");
}

int main(int argc, char* argv[]){
	int childStatus;
	pid_t forkVal = fork();

	if(forkVal == -1){
		// Fork failed.
		printHandler(FORK);
		return 1;
	}
	// I'm the child
	else if (forkVal == 0){
		// check for valid arguments
		if(argc <= 1)
			fprintf(stderr, "\nUsage: Provide %s a task\n", argv[argc]);
		else if(argc >= 2){
			int execStatus = execv(argv[1], argv+1);
			if(execStatus == -1)
				printHandler(EXEC);
		}
		exit(7);
	}
	// I'm the parent
	else{
		// wait for child to terminate and print Child PID
		// Child return value to stderr.
		int childID = forkVal; // for clarity
		fprintf(stderr, "%s \t$$ %d\n",argv[1], childID);

		wait(&childStatus);
		fprintf(stderr, "%s \t$? %d\n", argv[1], childStatus);
	}
	return 0;
}