/*--------------------------------------------------------*\
|  SelectionSort.c                                          |
|  A simple implementation of a simple Sorting Algorithm    |
|  It works by                                              |
|   1. Creating a list of 8 random integers between 0 and 30|
|   2. Sorting them using Selection Sort, as described on   |
|        the lab sheet                                      |
|  For CS211, Lab 2, March 2021                             |
|   Author: Niall Madden (Niall.Madden@NUIGalway.ie)        |
\*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Header file for library that includes rand function

void Swap(int *i, int *j);

int main(void)
{
  int i, j, a[8], MinIndex;
  
  printf("\nThe list is:\t\t");
  for (i=0; i<8; i++)
  {
    a[i] = rand()%31;
    printf("%8d", a[i]);
  }
  printf("\n");

  // Selection Sort algorithm:
  // Go through all list and find the smallest entry
  // Swap it with the one at the currently in first place.
  for (i=0; i<=6; i++)
  {
    MinIndex=i; 
    for (j=i+1; j<=7; j++)
      if (a[j] < a[MinIndex])
	MinIndex=j;
    Swap( &a[MinIndex], &a[i]);
    printf("\n Step %d : List is :\t", i); // This line is just for exposition
    for (int k=0; k<8; k++)
      printf("%8d", a[k]);
  }
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
