/* CS211 Week 12 */
/* Dynamic.c  : Summing Elements of an array with dynamic allocation */
#include <stdio.h>
#include <stdlib.h>

int sum(int *v, int n);

int main(void )
{
  int *v, n,  i, ans;
  printf("How many elements are there in v? :");
  scanf("%d", &n);
  v=(int *)calloc(n, sizeof(int));
  for (i=0; i < n; i++)
  {
    printf("Enter v[%d]: ", i);
    scanf("%d", &v[i]);
  }
  ans= sum(v, n);
  printf("The sum of the entries of v is %d \n", ans);
  free(v);
  return(0);
}
  
int sum(int *u, int n)
{
  int i, ans=0;
  for (i=0; i < n; i++)
      ans += u[i];
  return(ans);
}
