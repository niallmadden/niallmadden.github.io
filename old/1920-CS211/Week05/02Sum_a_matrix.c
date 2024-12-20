/* 02Sum_a_matrix.c
 WHAT: Experiments with two-dimensional arrays in C, bu showing how to
       add all the entries in a 2D int array.
 WHEN: Week 05 of 1920-CS211
 WHO:  Niall.Madden@NUIGalway.ie    */
#include <stdio.h>

int sum(int A[][4]);

int main(void )
{
  int n;
  int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

  n = sum(A);

  printf("The sum of the entries in A is %d \n", n);
  return(0);
}
  
int sum(int A[][4])
{
  int i,j, ans=0;
  for (i=0; i < 3; i++)
    for (j=0; j< 4; j++)
      ans += A[i][j];

  return(ans);
}
