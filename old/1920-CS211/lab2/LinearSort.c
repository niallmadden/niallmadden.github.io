/*--------------------------------------------------------*\
|  LinearSort.c                                             |
|  A simple implementation of (a simple) Sorting Algorithm  |
|  It works by                                              |
|   1. Creating a list of 8 random integers between 0 and 30|
|   2. Sorting them using Linear Sort, as described on the  |
|        lab sheet                                          |
|  For CS211, Lab 2, Feb 2020.                              |
|   Author: Niall Madden (Niall.Madden@NUIGalway.ie)        |
\*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Header file for rand function

void Swap(int *i, int *j);

int main(void)
{
  int i, j, a[8];
  
  printf("\nThe list is:\t\t");
  for (i=0; i<8; i++)
  {
    a[i] = rand()%31;
    printf("%8d", a[i]);
  }
  printf("\n");
  
  for (i=0; i<7; i++)
    for (j=i+1; j<8; j++)
      if (a[j] < a[i])
	Swap( &a[i], &a[j]);

  printf("\nThe sorted list is:\t");
  for (i=0; i<8; i++)
    printf("%8d", a[i]);

  printf("\n");
  return(0);
}

void Swap(int *i, int *j)
{
  int tmp;
  tmp = *i;
  *i = *j;
  *j = tmp;
}
