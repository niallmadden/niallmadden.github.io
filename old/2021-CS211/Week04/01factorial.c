/*--------------------------------------*\
|               01factorial.c            |
| Computing the factorial of a positive  | 
| integer.                               |
| For CS211, March 2021. Author: NM      | 
\*---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n);  // Prototype

int main(void)
{
  int x;
  printf("Enter a positive integer:  ");
  scanf("%d", &x);  // Warning: should do input check
  printf("factorial(%d)=%d\n",
	 x, factorial(x));
  return(0);
}

int factorial(int n)   /* Defination */
{
  int i, fac=1;
  for (i=1; i<=n; i++) 
    fac = fac*i;
  return(fac);
}
