#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("Received SIGINT: Exiting...\n");
    printf("Why you gotta be so rude?\n");
    exit(1);
  }
  if (signo == SIGUSR1) {
    printf("Recieved SIGUSR1: PPID = %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1) {
    printf("PID = %d\n", getpid());
    sleep(1);
  }

  return 0;
}
