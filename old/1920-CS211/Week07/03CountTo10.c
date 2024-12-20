// 03CountTo10.c
// An example of non-deterministic execution.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void )
{
  int i;
  fork();
  srand(getpid()); // different seed for each process
  printf("Watch me (%d) count to 10: ", getpid());
  for (i=1; i<=10; i++)
  {
    sleep(rand()%2); // sleep for 0 or 1 seconds
    printf("%3d...", i);
    fflush(stdout);
  }
  printf("\n");
  return(0);
}
