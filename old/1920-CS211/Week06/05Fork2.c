// An example of forking two processes

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void )
{
  int pid1, pid2, mypid;

  pid1 = fork();      
  pid2 = fork();      
  mypid = getpid();
  
  printf("I am %d\t", mypid);
  printf("1st fork returned %d\t", pid1);
  printf("2nd fork returned %d\n", pid2);
  return(0);
}
