#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>


int main(){
  printf("This is the parent speaking \n");
  int status, f;
  f = fork();
  srand(time(NULL));
  if(f) {
    f = fork();
  }
  if(f) {
    int w, status;
    w = wait(&status);
    printf("child: %d\tasleep for %d seconds\n", w, WEXITSTATUS(status));
    printf("End of parent\n");
    printf("End of program\n");
  } else {
    printf("Child PID:%d \n", getpid());
    int r = rand()%3+2;
    sleep(r);
    printf("Child is finished \n");
    return r;
  }
  return 0;
}
