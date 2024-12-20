// An example of forking a process
// Using return from fork to work out who is who
#include <unistd.h>
#include <stdio.h>
int main(void )
{
  int pid1, mypid;

  pid1 = fork();      
  mypid = getpid();
  
  if (pid1 != 0)
    printf("I am the parent. My PID is %d, the child's is %d\n", 
	   mypid, pid1);
  else
    printf("I am the child. My PID is %d, my parent's is %d\n", 
	   mypid, getppid());
  return(0);
}
