#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>

#define RANGE 5000000
#define SEM_FILE1  "/luis_chopstick_1"
#define SEM_FILE2  "/luis_chopstick_2"

sem_t *rightStick;
sem_t *leftStick;

int mFlag;
void setFlag();
int getFlag();

void signalHandler(int);
void eat(int);
void think(int);

int main(int argc, char* argv[]){
	if(argc < 3){
		fprintf(stdout, "ERROR: Please privide %s with seats and position.\n", argv[0]);
		return 1;
	}
	else{
		static int eatThink=0;
		signal(SIGTERM, signalHandler);
		srand( (unsigned int) time(NULL));
		rightStick=sem_open(SEM_FILE1, O_CREAT|O_EXCL, 0660, 1);
		if(rightStick == SEM_FAILED)
			rightStick = sem_open(SEM_FILE1, 0);

		leftStick=sem_open(SEM_FILE2, O_CREAT|O_EXCL, 0660, 1);
		if(leftStick == SEM_FAILED)
			leftStick = sem_open(SEM_FILE2, 0);


		eat(atoi(argv[argc-1]));
		// wait on semaphore
		sem_wait(rightStick);
		sem_wait(leftStick);

		think(atoi(argv[argc-1]));
		// signal that it's free
		sem_post(rightStick);
		sem_post(leftStick);
		eatThink++;
		if(getFlag()){
			fprintf(stderr, "\nPhilosopher %d completed %d cycles.\n", atoi(argv[argc-1]), eatThink);
			sem_unlink(SEM_FILE1);
			sem_unlink(SEM_FILE2);
		}
	}
return 0;
}

void signalHandler(int sig){
	setFlag();
}

void eat(int p){
	int eatTime = rand()%RANGE+1;
	fprintf(stdout, "Philosopher #%d is eating.\n", p);
	usleep( (useconds_t) eatTime);
}

void think(int p){
	int thinkTime = rand()%RANGE+1;
	fprintf(stdout, "Philosopher #%d is thinking.\n", p);
	usleep( (useconds_t) thinkTime);
}

void setFlag(){
	mFlag = 1;
}

int getFlag(){
	return mFlag;
}