/* Which: 02Thread_MemoryIsShared.c
   Why:   make a thread that  will then increment a shared variable.
   Who :  Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 9, 2021-CS211
   Why :  Try to show that a thread shares its parent's memory.  */ 

#include <stdio.h>
#include <assert.h>
#include <pthread.h> // Where the pthread functions are defined
#include <unistd.h>

int GlobalVar = 0; // Global variable; will check if really shared

void *mythread(void *arg) // This is the function the thread will call
{
  GlobalVar++;
  printf("This is Thread with pid=%d, and I think GlobalVariable = %d\n",
	 getpid(), GlobalVar);
  return(NULL);
}

int main(void)
{
  printf("------------------------------------------\n");
  printf("  An example showing that a pthread   \n");
  printf("       shares its parent's memory   \n");

  printf("START:\t This is Parent Process (PID=%d), and GlobalVar=%d\n",
	 getpid(), GlobalVar);

  pthread_t p1; // declare the thread's ID
  pthread_create(&p1, NULL, mythread, "N");  // create the thread
  pthread_join(p1, NULL);                    // wait for it to finish

  printf("END:\t This is Parent Process (PID=%d), and GlobalVar=%d\n",
	 getpid(), GlobalVar);
  return(0);
 }

