/* adder_race_condition.c 2021-CS211, Week 9  */
/* This program is a second step towards studying race conditions (see adder()).
   It works as follows.
   1. The program creates two subprocesses.
   2. The subprocs try to sum 4 numbers by placing them in a pipe:
      see the SubProc() function
   3. The parent then reads these, adds them, and sends the result
      back to the subprocs via another pipe: see the Adder() function
   4. The subprocesses then read this solution and prints it. 

However, both subprocesses write to the pipe at the same time, so the numbers 
don't appear in the expected order. Therefore a RACE CONDITION occurs. */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int inpipe[2], outpipe[2];  // These are global variables.

void Adder(void);  // Computes the sum of 4 numbers in "inpipe"
                    // Puts answer into "outpipe"
              
int SubProc(int a, int b, int c, int d); 
           // Puts four numbers to be summed into "inpipe"
           // Reads answer from "outpipe".

int main(void ) {
  int ParentsPID, ans;
  pipe(inpipe);  
  pipe(outpipe);

  ParentsPID = getpid(); // now I'll always know who I am
  
  fork(); // Make 1st subprocess
  if (getpid() == ParentsPID)
    fork(); // Make a second subprocess
  
  if ( getpid() == ParentsPID )
  {
    Adder();  // Add for the 1st subproc
    Adder();  // Add for the 2nd subproc
  }
  else
  {
    ans = SubProc(1,2,3,4);
    printf("SubProc (%d): 1+2+3+4= %d\n", getpid(), ans);
    exit(0); // subprocess should exit after printing the answer
  }
  return(0);
}

void Adder(void )
{
  int i, number, sum=0;

  for (i=0; i<4; i++)
  {
    read(inpipe[0], &number, sizeof(int));
    sum += number;
  }
  write(outpipe[1], &sum, sizeof(int));
}

int SubProc(int a, int b, int c, int d)
{
  int ans;
  printf("SubProc (%d) writes four numbers to the pipe()\n",
	 getpid());
  write(inpipe[1], &a, sizeof(int));
  write(inpipe[1], &b, sizeof(int)); 
  sleep(1); // Pause for a second to encourage race condition
  write(inpipe[1], &c, sizeof(int)); 
  write(inpipe[1], &d, sizeof(int));

  printf("SubProc (%d) reads the answer from a pipe()\n",
	 getpid());
  read(outpipe[0], &ans, sizeof(int));
  return(ans);
}

    
