/* Which: 08Pipes.c 
   What:  a parent and child communicate via a pipe
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Week 7, 1920-CS211
   Why:   an example of using (unix) pipes */
#include <unistd.h>
#include <stdio.h>

int main(void )
{
int child_pid, parent_pid, pipename[2];
pipe(pipename); // make the pipe
child_pid = fork();

if (child_pid != 0) // This is the parent 
{
  parent_pid = getpid();
  printf("I am the parent (%d); My child is %d\n",
     getpid(), child_pid);
  write(pipename[1], &parent_pid, 4);
} 
else   // The child 
{
  read(pipename[0], &parent_pid, 4);
  printf("I'm the child (%d); what I read from pipe: %d\n", 
     getpid(), parent_pid);
}
return (0);
}

