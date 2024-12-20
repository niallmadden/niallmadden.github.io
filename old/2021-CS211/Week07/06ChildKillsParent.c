/* Which: 06ChildKillsParent.c
   What:  a parent is sent a kill signal from their child 
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 7, 2021-CS211
   Why:   an example of using kill() */
#include <stdio.h>
#include <unistd.h> 
#include <signal.h>

int main(void )
{
  printf("Parent process has pid=%d\n", getpid());
  int child_pid = fork();
  if (child_pid == 0) // child path
  {
    sleep(3);
    printf("%d telling parent process (%d) to terminate\n",
	   getpid(), getppid() );
    kill(getppid(), SIGKILL);
  }
  else // parent path
  {
    sleep(20); // sleep for 20 seconds
    printf("**%d: never gets to this line, do we?\n",
	   getpid() );
  }
  return(0);
}





