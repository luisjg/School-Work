#include <fcntl.h>     // FILE
#include <stdio.h>     // fprintf
#include <unistd.h>    // chdir
#include <signal.h>
#include <stdlib.h>

#define LOGFILE "lab6.log"

int main(int argc, char* argv[]){
	chdir(argv[1]);
	FILE *logFile=fopen(LOGFILE, "w+");
	fprintf(logFile, "Pop %s\n", argv[0]);
	fclose(logFile);
	return 0;
}