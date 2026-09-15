// An example using getppid
#include <unistd.h>
#include <stdio.h>

int main(void )
{
  int pid1;
  pid1 = fork();      
  printf("I am %d\t; fork returned %d\t; My parent is %d\n",
	 getpid(), pid1, getppid());
  return(0);
}
