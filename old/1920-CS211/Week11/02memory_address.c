#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (void)
{
  int x;
  fork();
  x = getpid();
  printf("x is stores the value %d at %p\n", x, &x);
  return(0);
}
	
