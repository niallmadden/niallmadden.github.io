/*----------------------------------------------------\
 | Program: 04Fibanacci.c                             |
 | Why:  Show how to use a for loop, and array        |
 | How:  Use example of determining of computing some |
 |            terms in the Fibonacci Sequence         |
 | Who:  Niall Madden, Niall.Madden@NUIGalway.ie      |
 | When: Feb 2021. NM                                 |
 \---------------------------------------------------*/

#include <stdio.h>
int main(void )
{
  int i, Fib[10];
  Fib[0]=1;  printf("Fib[0] = %d\n", Fib[0]);
  Fib[1]=1;  printf("Fib[1] = %d\n", Fib[1]);

  for (i=2; i<=9; i++)
  { 
     Fib[i] = Fib[i-1] + Fib[i-2];
     printf("Fib[%d] = %d\n", i, Fib[i]);
  }
  return(0);
}
