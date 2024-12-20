/* 01ASCII.c: Generate a table of ASCII characters.
   For CS211, Feb 2020 */

#include <stdio.h>
#include <stdlib.h>

int main(void ) {
  int i, start, step=16;
  
  for (start=32; start < 127; start+=step)
  {
    printf("\n%12s", "Code:");
    for (i=start; i < start+step; i++)  
      printf("%4i", i);
    
    printf("\n%12s", "Character:");
    for (i=start; i < start+step; i++)  
      printf("%4c", i);
    printf("\n");
  }
  printf("\n");
  
  return(0);
}
