// An example of forking a process
#include <unistd.h>
#include <stdio.h>

int main(void )
{
  int pid1, mypid;

  pid1 = fork();      
  mypid = getpid();
  
  printf("I am %d\t", mypid);
  printf("Fork returned %d\n", pid1);
  return(0);
}
