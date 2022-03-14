/* adder_race_condition.c 2122-CS211, Lab 5  */
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

int subproc_to_parent[2], parent_to_subproc[2];  // Global variables.

void Adder(void);   // 1. Takes 4 numbers from the "subproc_to_parent" pipe
                    // 2. Adds them together
                    // 3. Sends  answer to "parent_to_subproc" pipe
              
int SubProc(int a, int b, int c, int d); 
           // Puts four numbers to be summed into "subproc_to_parent"
           // Reads answer from "parent_to_subproc".

int main(void ) {
  int ParentsPID, ans;
  pipe(subproc_to_parent);  
  pipe(parent_to_subproc);

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
    read(subproc_to_parent[0], &number, sizeof(int));
    sum += number;
  }
  write(parent_to_subproc[1], &sum, sizeof(int));
}

int SubProc(int a, int b, int c, int d)
{
  int ans;
  printf("SubProc (%d) writes four numbers to the pipe()\n",
	 getpid());
  write(subproc_to_parent[1], &a, sizeof(int));
  write(subproc_to_parent[1], &b, sizeof(int)); 
  sleep(1); // Pause for a second to encourage race condition
  write(subproc_to_parent[1], &c, sizeof(int)); 
  write(subproc_to_parent[1], &d, sizeof(int));

  printf("SubProc (%d) reads the answer from a pipe()\n",
	 getpid());
  read(parent_to_subproc[0], &ans, sizeof(int));
  return(ans);
}

    
