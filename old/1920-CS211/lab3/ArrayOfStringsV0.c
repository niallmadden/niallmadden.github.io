/* This is a simple example of an array of strings in C
   For 1920-CS211 Lab 3+4. 
   Author: Niall Madden */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char ListOfWords[5][20] = 
    {"Operating", "System", "and", "Programming", "CS211"};
  int k, n=5;

  for (k=0; k<n; k++)
    printf("ListOfWords[%d] = %s\n", k, ListOfWords[k]);

  return(0);
}
  
