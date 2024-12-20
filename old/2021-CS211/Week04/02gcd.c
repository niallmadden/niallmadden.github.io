/*----------------------------------------------------*\
|                   02gcd.c                            |
| Computing the greatest common divisor of two numbers | 
| An example of writing a function in C                |
| For CS211, Mar 2021. Author: NM                      | 
\*----------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b); // Prototype

int main(void)
{
  int a, b;
  printf("Enter a and b: ");
  scanf("%d", &a);  
  scanf("%d", &b);
  printf("gcd(a,b)=%d\n", gcd(a,b));
  return(EXIT_SUCCESS);
}

int gcd(int a, int b)
{
  int x=a, y=b, r;

  while(y != 0)
  {
    r = x%y;
    x=y;
    y=r;
  }
  return(x);
}
