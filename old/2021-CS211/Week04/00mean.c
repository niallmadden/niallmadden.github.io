/*--------------------------------------*\
|               00Mean.c                 |
| Computing the mean of two numbers      | 
| An example of writing a function in C  |
| For CS211, March 2021. Author: NM      | 
\*---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

float mean(float, float);  // Prototype

int main(void)
{
  float a, b;
  printf("Enter (floating-point) numbers a and b: ");
  scanf("%f", &a);  
  scanf("%f", &b);
  printf("mean(a,b)=%f\n", mean(a,b));
  return(0);
}

float mean(float a, float b)
{
  return( (a+b)/2.0);
}
