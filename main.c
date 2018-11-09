#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

static void sighandler(int signo){
  if(signo == 2){
    int y = open("file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(y, "Program exited due to SIGINT", 29);
    close(y);
    exit(0);
  }
  if(signo == 10){
    printf("Parent process pid: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("Current pid: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
