// An example of overlaying a process using execlp
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void )
{
  int pid1 = fork();      
  
  if (pid1 == 0) // this is the child
  {
    printf("This is process %d\t", getpid());
    printf("Here is a directory listing:\n");
    execlp("ls", "ls", NULL);
  }
  else // parent
  {
     wait(NULL); 
     printf("This is process %d\t", getpid());
     printf("Subprocess %5d has completed\n", pid1);
  }
  return(0);
}
