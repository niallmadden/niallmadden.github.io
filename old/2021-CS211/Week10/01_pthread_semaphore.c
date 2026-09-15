/* Which: 01_pthread_semaphore.c
   What:  create a semaphore, make a thread when takes the semaphore 
          making the parent wait 10 seconds.
   Who :  Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 10, 2021-CS211
   Why :  show how to use the POSIC sem_wait and sem_post functions. 
   Also:  (0) This example is just for completeness; if not interested, 
              you can safely ignore it.
          (1) Review example in Week08's 02Thread_MemoryIsShared.c 
          (2) Compile with -pthread, or use https://www.onlinegdb.com/
          (3) This is based on Figure 31.6 in OSTEP */

#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Where the pthread functions are defined

sem_t s;

void *mythread(void *arg) // This is the function the thread will call
{
  printf("Thread with (%d): wait,  then sleep 10, then post\n",
	 getpid());
  sem_wait(&s); // wait here for child
  sleep(10);
  printf("Thread done sleeping. Will post now\n");
  sem_post(&s);
  return(NULL);
}

int main(int argc, char *argv[])
{
  printf("START:\t This is Parent Process (PID=%d)\n",
	 getpid());
  sem_init(&s, 0, 1); // what should X be?
  pthread_t p1; // declare the thread's ID

  printf("parent: begin\n");
  pthread_create(&p1, NULL, mythread, "N");
  sleep(2);
  printf("Parent (%d) waiting...\n", getpid());
  sem_wait(&s); // wait here for child
  printf("Parent (%d) done waiting!\n", getpid());

  printf("Parent: end\n");
  return (0);
}
