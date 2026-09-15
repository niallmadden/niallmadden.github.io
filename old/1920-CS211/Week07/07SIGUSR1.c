/* Which: 08SIGUSR1.c
   What:  child process preforms a "time-out" on the parent
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 7, 1819-CS211
   Why:   an example of using signal() */
#include <stdio.h>
#include <unistd.h> // need this for pipe and fork
#include <signal.h>

void timed_out(int sig)
{
  printf("Proc %d called timed_out with signal %d\n", 
	 getpid(), sig);
}

void DoSomeThingComplicated(void)  
{ 
  sleep(10);
}

int main(void )
{
  int pid=fork(); // New process will "watch over old one" and send 
              // signal if timeout expires.

  if (pid != 0 ) // I'm not the watcher
  {
    signal(SIGUSR1, timed_out); // What to do if I get signaled
    DoSomeThingComplicated(); // Something that'll be interrupted
    
    printf("%d got woken \n", getpid());

    // Finished something complicated. Don't need watcher any more
    kill(pid, SIGKILL);   //  tell watcher to terminate.
  }
  else  // I am the watcher
  {
    printf("I am the watcher (%d)\n", getpid());
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


