/* Adder.c 1920-CS211, Week 9  */
/* This program is a first step towards studying race conditions.
   It works as follows.
   1. The program creates a child process.
   2. The child tries to sum 4 numbers by placing them in a pipe:
      see the child() function
   3. The parent then reads these, adds them, and sends the result
      back to the child via another pipe: see the adder() function
   4. The child then reads this solution and prints it. 
It should preform exactly as expected: because there is only one child 
process, a race condition is not possible.
See adder_race_condition.c which has more than one child, and 
may feature a race condition. */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int inpipe[2], outpipe[2];  // These are global variables.

void adder(void);  // Reads 4 numbers from "inpipe, sums them and 
                   // writes answer o outpipe
              
int child(int a, int b, int c, int d); 
           // Puts four numbers to be summed into inpipe
           // Reads answer from outpipe.

int main(void )
{
  int ParentsPID, ans;
  pipe(inpipe);  
  pipe(outpipe);
  ParentsPID = getpid(); // now I'll always know who I am
  fork(); //Now have 2 procs. Child will have differnt pid
  if ( getpid() == ParentsPID )
    adder();  // The parent will be the adder
  else
  {
     ans=child(1,2,3,4);
     printf("Child (%d): 1+2+3+4= %d\n", getpid(), ans);
  }
  return(0);
}

void adder(void ) // run by parent
{
  int i, number, sum=0;

  for (i=0; i<4; i++)
  {
    read(inpipe[0], &number, sizeof(int));
    sum += number;
  }
  write(outpipe[1], &sum, sizeof(int));
}
  
int child(int a, int b, int c, int d)
{
  int ans;
  printf("Child (%d) writes four numbers to the pipe()\n", getpid());
  write(inpipe[1], &a, sizeof(int));
  write(inpipe[1], &b, sizeof(int)); 
  sleep(1); // Pause for a second to encourage race condition
  write(inpipe[1], &c, sizeof(int)); 
  write(inpipe[1], &d, sizeof(int));

  printf("Child (%d) reads the answer from a pipe()\n", getpid());
  read(outpipe[0], &ans, sizeof(int));
  return(ans);
}

    

