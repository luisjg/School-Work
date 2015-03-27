#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <stdlib.h>

void printTimes(struct tms strucTimes){
	/*since this progam executes very quickly these values _should_ all report 0*/
	printf("USER: %d, SYS: %d\n", strucTimes.tms_utime, strucTimes.tms_stime);
	printf("CUSER: %d, CSYS: %d\n", strucTimes.tms_cutime, strucTimes.tms_cstime);
}

void printProcessInfo(int childPid, int childStatus){
	/*this get's the ppid and pid of the current running
	process*/
	printf("PPID: %d, PID: %d", getppid(), getpid());
	/*since childStatus contains the return value of the child it should
	not be 0*/
	if(childStatus > 0){
		printf(", CPID: %d, RETVAL: %d", childPid, childStatus);
	}
	printf("\n");
}

int main(){
	// initialize to zero to ensure only child info is printed
	int childStatus=0;
	time_t epochTime = time(NULL);
	struct tms strucTimes;
	printf("START: %d\n", epochTime);
	pid_t forkVal = fork();
	if(forkVal == -1){
		// Fork failed.
		perror("\nERROR: fork failed\n");
		return 1;
	}
	else if (forkVal == 0){
		// at this point forkVal = childStatus = 0
		printProcessInfo(forkVal,childStatus);
		exit(7);
	}
	else{
		/*returns the return value, which causes forkVal to have
		the child pid*/
		wait(&childStatus);
		// at this point forkVal = child pid (found out by printf(forkVal)), childStatus = 7
		printProcessInfo(forkVal,childStatus);
		times(&strucTimes);
		printTimes(strucTimes);
	}
	printf("STOP: %d\n", epochTime);
	return 0;
}