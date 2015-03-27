#include <fcntl.h>         // O Constatns
#include <limits.h>        // PATH_MAX
#include <unistd.h>        // fork
#include <signal.h>        // signal
#include <stdlib.h>        // exit
#include <stdio.h>         // fprintf
#include <sys/resource.h>  // rlimit
#include <sys/stat.h>      // umask
#include <sys/time.h>      // rlimit
#include <sys/types.h>     // umask
#include <time.h>          // time

#define RANDOMRANGE 2

static int mFlag=-1;

void signalHandler(int sig);
void executeMole(int i, char dir[]);
void setFlag(int child);
int getFlag();

int main(int argc, char* argv[]){
	
	// set umask to 0
	umask(0);
	// fork a child
	pid_t forkVal = fork();
	if(forkVal == -1)
		fprintf(stderr, "ERROR Fork Failed!");

	if(forkVal != 0){
		// parent dies
		exit(0);
	}
	// I'm the child.
	// set the signal handlers
	signal(SIGTERM, signalHandler);
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	// seed the random number
	srand( (unsigned int) time(NULL));

	// save current working directory
	char workingDir[PATH_MAX];
	if(getcwd(workingDir, PATH_MAX) == NULL)
		fprintf(stdout, "ERROR: getcwd Failed!\n");
	// set a new session
	pid_t sid = setsid();
	if(sid == -1){
		fprintf(stderr, "ERROR: New session not created.\n");
	}
	pid_t pid = getpid();
	if(pid == -1){
		fprintf(stderr, "ERROR: Could not get process ID.\n");
	}
	fprintf(stdout, "PID %d\n", pid);
	// change the directory
	chdir("/");
	/*
	// close all the fds
	struct rlimit fdLimit;
	getrlimit(RLIMIT_NOFILE, &fdLimit);
	int i;
	for(i=0; i< fdLimit.rlim_cur; i++)
		close(i);
	int fd=open("/dev/null",O_RDONLY);
	// remap the standard 0-2 fds to the logfile
	dup(fd);
	dup(fd);
	*/
	// run for the first time
	for( ;; ){
		// static int firstRun=0;
		static int chld1=0;
		/*if (firstRun == 0){
			pid_t child=fork();
			if(child == 0){
				int result = ( rand()%RANDOMRANGE )+1;
				executeMole(result, workingDir);
				firstRun=1;
			}
			else{
			    chld1=child;
			}
		}*/
		pause();
		if(getFlag() == 0){
			kill(0, SIGTERM);
			break; 
		}
		else if(getFlag() == 1){
			kill(chld1,0);
			chld1=0;
			pid_t child=fork();
			if(child == 0){
				int result = (rand()%RANDOMRANGE)+1;
				executeMole(result, workingDir);
			}
			else{
				chld1=child;
			}
		}
		else if(getFlag() == 2){
			kill(chld1,0);
			chld1=0;
			pid_t child=fork();
			if(child == 0){
				int result = (rand()%RANDOMRANGE)+1;
				executeMole(result, workingDir);
			}
			else{
				chld1=child;
			}
		}
		else{
			setFlag(-1);
		}
	}
}

void signalHandler(int sig){
	signal(sig, signalHandler);
	if(sig == SIGTERM){ setFlag(0); }
	if(sig == SIGUSR1){ setFlag(1); }
	if(sig == SIGUSR2){ setFlag(2); }
}

void executeMole(int i, char dir[]){
	int status;
	chdir(dir);
	if(i == 1){
		status=execl("mole","mole1", dir,(char *) NULL);
		if(status == -1)
			fprintf(stderr, "Exec: mole1 Failed\n");
	}
	if(i == 2){
		status=execl("mole","mole2", dir,(char *) NULL);
		if(status == -1)
			fprintf(stderr, "Exec: mole2 Failed\n");
	}
}

void setFlag(int child){
	mFlag = child;
}

int getFlag(){
	return mFlag;
}