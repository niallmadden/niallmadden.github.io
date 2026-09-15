/* Which: 07SIGUSR1.c
   What:  Showing how to use signal and SIGUSR1
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 7, 2021-CS211
   Why:   an example of using signal() */
#include <stdio.h>
#include <unistd.h> // need this for fork
#include <signal.h> // defines signalo()

void signal_handler1(int sig);

int main(void )
{
  int child_pid=fork(); // New process will send signal to parent

  if (child_pid != 0 )                // I'm the parent
  {
    signal(SIGUSR1, signal_handler1); // What to do if I get signaled
    sleep(100);                       // Wait potentially a long time
    printf("%d got woken \n", getpid());
    kill(child_pid, SIGKILL);         //  tell watcher to terminate.
  }
  else  // I am the child
  {
    printf("I am the child (%d)\n", getpid());
    printf("Should %d signal parent (%d)? ('y'/'n')\n", 
	   getpid(), getppid());
    if (getchar() == 'y')
    {
      printf("Sending siguser 1 to parent\n");
      kill(getppid() , SIGUSR1); 
    }
  }
  return(0);
}

void signal_handler1(int sig) {
  printf("Proc %d called signal_handler1() with signal %d\n", 
	 getpid(), sig);
}
