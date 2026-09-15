/*-----------------------------------------------------------*\
|                      05Largest.c                            |
| an example of how to create a random list of integers and   |
| then find the largest one. For CS211, Feb 2021. Author: NM  | 
\*-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Header file for rand function

int main(void)
{
  int k, m, a[8];

  printf("\nThe list is: ");
  for (k=0; k<8; k++)
  {
    a[k] = rand()%21;
    printf("\t%d", a[k]);
  }
  m = a[0];
  for (k=1; k<8; k++)
    if (m < a[k])
      m = a[k];

  printf("\nThe largest element is: %d\n", m);

  return(0);
}



