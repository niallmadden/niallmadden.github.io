/* Which: 02_fopen.c 
   What:  a parent and child (try to) access the same file.
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Lab 5,  1920-CS211
   Why:   Answer Exer 5.2 from the Textbook 
   http://pages.cs.wisc.edu/~remzi/OSTEP/  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void )
{
  int i;
  char c;
  FILE *infp;
  
  infp = fopen("test.txt", "w");
  if (infp == NULL)
  {
    printf("Error - can't open that file\n");
    exit(0);
  }

  int child_pid;
  child_pid = fork();
  
  if (child_pid != 0) // This is the parent 
  {
    for (i=0; i<10; i++)
    {
      sleep(1);
      fprintf(infp, "%d", i);
      fprintf(stdout, "%d", i);
      fflush(infp);
      fflush(stdout);
    }

  }
  else   // The child 
  {
    for (c='a'; c<='z'; c++)
    {
      sleep(1);
      fprintf(infp, "%c", c);
      fprintf(stdout, "%c", c);
      fflush(infp);
      fflush(stdout);
    }
    exit(0);
  }
  fclose(infp);
}

