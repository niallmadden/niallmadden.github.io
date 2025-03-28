/* 01Matrix.c
 WHAT: Experiments with two-dimensional arrays in C
 WHEN: Week 05 of 2021-CS211
 WHO:  Niall.Madden@NUIGalway.ie    */
#include <stdio.h>

int main(void )
{
  int A[3][4]={{1,2,3,4},
	       {5,6,7,8},
	       {9,10,11,12}};

  // Here are 4 different ways to access the "7" in this array.
  printf("A[1][2] = %d\n", A[1][2]);
  printf("*(A[1]+2) = %d\n", *(A[1] + 2));
  printf("*(*(A+1)+2) = %d\n", *( *(A + 1) + 2));
  printf("*(&A[0][0] + 4 + 2) = %d\n", *( &A[0][0] + 4 + 2));

  return(0);
}
  
