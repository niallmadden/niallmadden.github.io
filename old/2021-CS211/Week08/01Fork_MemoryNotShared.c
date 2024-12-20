/* Which: 01Fork_MemoryNotShared.c
   Why:   fork a subproc which will then increment a shared variable.
   Who :  Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 9, 2021-CS211
   Why :  Try to show that a fork()'ed subproc and its parent do 
          not share memory.   */ 

#include <stdio.h>
#include <assert.h>
#include <pthread.h> // not used here, but needed in Example 2
#include <unistd.h>

int GlobalVar = 0; // Global variable; will check if really shared

int main(void)
{
  printf("--------------------------------------\n");
  printf("  An example showing that fork()'ed   \n");
  printf(" subprocess has a copy of its parents \n");
  printf("     memory, but it is not shared.    \n");
  printf("START:\t This is Parent Process (PID=%d), and GlobalVar=%d\n",
	 getpid(), GlobalVar);
	 
  int pid = fork();
  if (pid == 0) // This is the subprocess
  {
    GlobalVar++;
    printf("This is Subprocess %d, and I think GlobalVariable = %d\n",
	   getpid(), GlobalVar);
  }
  else // Parent
  {
    sleep(1); // just to make sure the subprocess does its thing first
    printf("END:\t This is Parent Process (PID=%d), and GlobalVar=%d\n",
	   getpid(), GlobalVar);
  }
  return(0);
}
