// An example using getppid
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void )
{
  int pid1;
  pid1 = fork();      
  printf("I am %d\t", getpid());
  printf("fork returned %5d\t", pid1);
  printf("My parent is %d\n", getppid());
  return(0);
}
