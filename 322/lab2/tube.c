#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* found how to copy argv[] here
https://stackoverflow.com/questions/5206840/duplicating-an-array-of-strings-or-copying-them-to-another-array/5206927#5206927*/


// define constants
#define READ_END  0
#define WRITE_END 1
// for error checking
#define PIPE 0
#define DUP  1

// define helper functions
int checkForkStatus(int *forkVal, int child){
	if((*forkVal) == -1){
		fprintf(stderr, "ERROR: Fork of Child %d failed!\n", child);
		return 1;
	}
}

void errorHandler(int i){
	// pipe
	if(i == PIPE)
		fprintf(stderr, "ERROR: Pipe Failed!\n");
	// dup
	if(i == DUP)
		fprintf(stderr, "EROR: Dup Failed!\n");
}

void printExecError(int i){
	fprintf(stderr, "ERROR child %d exec failed!\n", i);
}

void printChildId(char *s, int id){
	fprintf(stderr, "%s \t$$ %d\n", s, id);
}

void printRetVal(char *s, int value){
	fprintf(stderr, "%s \t$$ %d\n", s, value);
}

int main(int argc, char* argv[]){
	int child1Status;
	int child2Status;
	int argvOffset;

	// check to see if more than one argument
	if(argc<1){
		fprintf(stderr, "ERROR: Please supply %s with more arguments\n", argv[0]);
	}

	// figure out the offset
	int i;
	for(i = 0; i< argc; i++){
		if(*argv[i] == ','){
			argvOffset = i;
		}
	}
	// check to see if the second argument is valid
	if(argv[argvOffset+1] == NULL){
		fprintf(stderr, "ERROR: Please supply %s with more arguments\n", argv[0]);
		return 1;
	}

	// pipeFd[0] read, pipeFd[1] write
	int pipeFd[2];
	int pipeVal = pipe(pipeFd);
	if(pipeVal == -1)
		errorHandler(PIPE);

	// parent fork a child

	// producer
	pid_t child1 = fork();
	if(checkForkStatus(&child1, 1) < 0){
		return 1;
	}

	// producer map your STDOUT to the WRITE_END of the pipe
	if(child1 == 0){

		if(dup2(pipeFd[WRITE_END], STDOUT_FILENO) == -1)
			errorHandler(DUP);
		close(pipeFd[READ_END]);


		// set up producer argv
		int j;
		char **argv1 = malloc( sizeof(char *) * (argvOffset));
		// offset - 1 signifies one less than the comma
		for (j = 0; j < argvOffset-1; j++) {
		    argv1[j] = argv[j + 1];
		}
		// we need to set the last valie in argv1 to null
		// or else chaos
		argv1[argvOffset] = NULL;

		// execute commands
		if(execv(argv1[0], argv1) < 0){
			printExecError(1);
		}
		// free up the memory
		free(argv1);
		// return the value to parent
		exit(7);
	}
	else{
		// parent fork another child

		// consumer
		pid_t child2 = fork();
		if(checkForkStatus(&child2, 2) < 0){
			return 1;
		}

		// consumer map your STDIN to the READ_END of the pipe
		if(child2 == 0){
			if(dup2(pipeFd[READ_END], STDIN_FILENO) == -1)
				errorHandler(DUP);
			close(pipeFd[WRITE_END]);

			// set up consumer argv
			// argc contains number of arguments, argvOffset contains
			// the array position in which the comma exists.
			// recall argvOffset is array position, argvOffset + 1 is actual
			// count position
			int k;
			char **argv2 = malloc( sizeof(char *) * (argc - argvOffset + 1));
			// we want it one short than the actual size of the array
			int arg2End = (argc - argvOffset)-1;
			for(k = 0; k < arg2End; k++){
				// we start to copy from the (offset + 1) and move along until k
				argv2[k] = argv[(argvOffset + 1) + k];
			}
			// make the lat element to NULL
			// to avoid chaos
			argv2[arg2End+1] = NULL;
			// execute commands
			if(execv(argv2[0], argv2) < 0){
				printExecError(2);
			}
			// free up the memory
			free(argv2);
			// return value to parent
			exit(8);
		}
		// parent close pipe
		close(pipeFd[READ_END]);
		close(pipeFd[WRITE_END]);
		// print children IDs
		printChildId(argv[1],child1);
		printChildId(argv[argvOffset+1],child2);
		// get children return values
		waitpid(child1, &child1Status, WEXITSTATUS(child1Status));
		waitpid(child2, &child2Status, WEXITSTATUS(child2Status));
		// print children return values.
		printRetVal(argv[1],child1Status);
		printRetVal(argv[argvOffset+1],child2Status);
	}
	return 0;
}