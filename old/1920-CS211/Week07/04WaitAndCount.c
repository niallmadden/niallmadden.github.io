// 03CountTo10.c
// An example of non-deterministic execution.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void )
{
  int pid1=fork();
  srand(getpid());
  if (pid1 != 0) // Parent follows this path
    wait(NULL);
  
  printf("Watch me (%d) count to 10: ", getpid());
  for (int i=1; i<=10; i++)
  {
    sleep(rand()%2); // sleep for 0 or 1 seconds
    printf("%3d...", i);
    fflush(stdout);
  }
  printf("\n");
  return(0);
}
