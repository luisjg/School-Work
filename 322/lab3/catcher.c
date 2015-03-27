#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define HANDLER 0
#define MAIN    1

// checks to see if the loop needs to terminate

int checkLoop(int source){
  static int FLAG=0;
  // source is the handler
  // that means that the handler
  // has specified to terminate
  // so we set the flag to terminate
  if(source == HANDLER){
    // set this to true
    FLAG = 1;
  }
  if(source == MAIN){
    // if the source comes from main return
    // the flag
    return FLAG;
  }
  // always return -1
  return -1;
}

// include the code from the Goodle Doc file.

int sig_name2number(char *s) {
  int signumber = -1;

  if (!strcmp(s, "HUP"))     { signumber = SIGHUP; }
  if (!strcmp(s, "INT"))     { signumber = SIGINT; }
  if (!strcmp(s, "QUIT"))    { signumber = SIGQUIT; }
  if (!strcmp(s, "ILL"))     { signumber = SIGILL; }
  if (!strcmp(s, "TRAP"))    { signumber = SIGTRAP; }
  if (!strcmp(s, "ABRT"))    { signumber = SIGABRT; }
  if (!strcmp(s, "IOT"))     { signumber = SIGIOT; }
  if (!strcmp(s, "BUS"))     { signumber = SIGBUS; }
  if (!strcmp(s, "FPE"))     { signumber = SIGFPE; }
  if (!strcmp(s, "KILL"))    { signumber = SIGKILL; }
  if (!strcmp(s, "USR1"))   { signumber = SIGUSR1 ; }
  if (!strcmp(s, "SEGV"))   { signumber = SIGSEGV ; }
  if (!strcmp(s, "USR2"))   { signumber = SIGUSR2 ; }
  if (!strcmp(s, "PIPE"))   { signumber = SIGPIPE ; }
  if (!strcmp(s, "ALRM"))   { signumber = SIGALRM ; }
  if (!strcmp(s, "TERM"))   { signumber = SIGTERM ; }
  if (!strcmp(s, "STKFLT")) { signumber = SIGSTKFLT; }
  if (!strcmp(s, "CHLD"))   { signumber = SIGCHLD ; }
  if (!strcmp(s, "CONT"))   { signumber = SIGCONT ; }
  if (!strcmp(s, "STOP"))   { signumber = SIGSTOP ; }
  if (!strcmp(s, "TSTP"))   { signumber = SIGTSTP ; }
  if (!strcmp(s, "TTIN"))   { signumber = SIGTTIN ; }
  if (!strcmp(s, "TTOU"))   { signumber = SIGTTOU ; }
  if (!strcmp(s, "URG"))    { signumber = SIGURG ; }
  if (!strcmp(s, "XCPU"))   { signumber = SIGXCPU ; }
  if (!strcmp(s, "XFSZ"))   { signumber = SIGXFSZ ; }
  if (!strcmp(s, "VTALRM")) { signumber = SIGVTALRM ; }
  if (!strcmp(s, "PROF"))   { signumber = SIGPROF ; }
  if (!strcmp(s, "WINCH"))  { signumber = SIGWINCH ; }

  return signumber;
}

// this compares the signal and returns the proper string

char* sig_number2name(int sig){
  if (sig == SIGHUP){ return "HUP"; } 
  if (sig == SIGINT) { return "INT"; }
  if (sig == SIGQUIT) { return "QUIT"; }
  if (sig == SIGILL) { return "ILL"; }
  if (sig == SIGTRAP) { return "TRAP"; }
  if (sig == SIGABRT) { return "ABRT"; }
  if (sig == SIGIOT) { return "IOT"; }
  if (sig == SIGBUS) { return "BUS"; }
  if (sig == SIGFPE) { return "FPE"; }
  if (sig == SIGKILL) { return "KILL"; }
  if (sig == SIGUSR1) { return "USR1"; }
  if (sig == SIGSEGV) { return "SEGV"; }
  if (sig == SIGUSR2) { return "USR2"; }
  if (sig == SIGPIPE) { return "PIPE"; }
  if (sig == SIGALRM) { return "ALRM"; }
  if (sig == SIGTERM) { return "TERM"; }
  if (sig == SIGSTKFLT) { return "STKFLT"; }
  if (sig == SIGCHLD) { return "CHLD"; }
  if (sig == SIGCONT) { return "CONT"; }
  if (sig == SIGSTOP) { return "STOP"; }
  if (sig == SIGTSTP) { return "TSTP"; }
  if (sig == SIGTTIN) { return "TTIN"; }
  if (sig == SIGTTOU) { return "TTOU"; }
  if (sig == SIGURG) { return "URG"; }
  if (sig == SIGXCPU) { return "XCPU"; }
  if (sig == SIGXFSZ) { return "XFSZ"; }
  if (sig == SIGVTALRM) { return "VTALRM"; }
  if (sig == SIGPROF) { return "PROF"; }
  if (sig == SIGWINCH) { return "WINCH"; }
}

// signal handler

void catchSignal(int sig){
  // re-register the handler
  signal(sig,catchSignal);
  // to keep the term count from being re-written on creation
  static int TERMCOUNT=0;
  // get the time since epoch
  time_t epochTime = time(NULL);
  // print which signal was caught at time
  fprintf(stdout,"%s caught at time %d\n", sig_number2name(sig), epochTime);
  // check if one of the signals is sigterm
  if(sig == SIGTERM){
    // increment TERMcount
    TERMCOUNT++;
  }
  else{
    // reset the TERMcount
    TERMCOUNT=0;
  }
  // set the flag
  if(TERMCOUNT == 3){
    if(checkLoop(HANDLER) != -1)
      fprintf(stderr, "ERROR: Program termination error");
  }
}

int main(int argc, char* argv[]){
  int sigCount=0;
  if(argc <= 1){
    fprintf(stderr,"ERROR: provide %s a signal to catch.\n", argv[0]);
    return 1;
  }
  else{
    fprintf(stderr, "%s: \t$$ = %d\n", argv[0], getpid());
    // register the handlers
    int i;
    for(i=1; i<argc; i++){
      // only register if they are the appropriate ones
      // as defined on the Google Doc
      if(sig_name2number(argv[i]) != -1)
        signal(sig_name2number(argv[i]), catchSignal);
      // ignore the signal
      // this is optional...
      else
        signal(sig_name2number(argv[i]), SIG_IGN);
    }


    // wait for the handlers and increment handler count
    for( ;; ){
      pause();
      sigCount++;
      // check to see if it's time to end the loop.
      if(checkLoop(MAIN) == 1){ break; }
    }
    // print out the total signals caught by the program.
    fprintf(stderr, "%s: Total signals caught = %d\n", argv[0], sigCount);
    return 0;
  }
}