/* Which: 02_fopen.c 
   What:  a parent and child (try to) access the same file.
   Who:   Niall Madden (Niall.Madden@NUIGalway.ie)
   When:  Lab 5,  2021-CS211
   Why:   Answer Exer 5.2 from the Textbook 
   http://pages.cs.wisc.edu/~remzi/OSTEP/  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void )
{
  int i;
  char c;
  FILE *test_file;
  
  test_file = fopen("test.txt", "w");
  if (test_file == NULL)
  {
    printf("Error - can't open that file\n");
    exit(0);
  }
  else
    printf("Opened test.txt for writing\n");

  int child_pid;
  child_pid = fork();
  
  if (child_pid != 0) // This is the parent 
  {
    for (i=0; i<10; i++)
    {
      sleep(1);
      fprintf(test_file, "%d", i);
      fprintf(stdout, "%d", i);
      fflush(test_file);
      fflush(stdout);
    }

  }
  else   // The child 
  {
    for (c='a'; c<='j'; c++)
    {
      sleep(1);
      fprintf(test_file, "%c", c);
      fprintf(stdout, "%c", c);
      fflush(test_file);
      fflush(stdout);
    }
    exit(0); // causes child to exit here
  }
  fclose(test_file);
}

