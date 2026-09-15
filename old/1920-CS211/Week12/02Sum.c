/* CS211 - Week 12 */
/* SumVersion1.c: an example  of passing a pointer as an argument */
#include <stdio.h>
int sum_pointer(int *p, int n);
int sum_array(int a[], int n);
int main()
{
  int a[4] = {1, 99, 40, 60};
  printf("a[0]+a[1]+a[2]=%d\n", sum_array(a,3));
  printf("a[1]+a[2]+a[3]=%d\n", sum_pointer(a+1,3));
  return(0);
}

int sum_pointer(int *p, int n) 
{
  int i, sum=0;
  for (i=0; i<n; i++)
    sum+=*(p+i);
  return(sum);
}

int sum_array(int a[], int n) 
{
  int i, sum=0;
  for (i=0; i<n; i++)
    sum+=a[i];
  return(sum);
}
