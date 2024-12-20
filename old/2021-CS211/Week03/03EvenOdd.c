/*--------------------------------------------------
 | Program: 01EvenOdd.c                             |
 | Why:  Show how to use if/else if/else statements |
 | How:  Use example of determining if a number is  |
 |          even or odd, and positive or negative   |
 | Who:  Niall Madden, Niall.Madden@NUIGalway.ie    |
 | Also: Introduces random number generation        |
 | When: Feb 2021. NM                               |
 --------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h> // for rand and srand
#include <time.h>

int main(void)
{
  srand(time(NULL));

  // Check Even or Odd
  int a=rand()%10; // a is a random number between 0 and 9.
  printf("a=%d\n", a);
  if ( (a % 2) == 0)
    printf("a is even\n");
  else
    printf("a is odd\n");
  
  // Check positive, negative or zero
  a=rand()%7-3; // a is a random number between -3 and 3.
  printf("a=%d\n", a);
  if ( a>0 )
    printf("a is (strictly) positive\n");
  else if ( a<0) 
    printf("a is (strictly) negative\n");
  else
    printf("a is zero\n");
  
  return(0);
}
