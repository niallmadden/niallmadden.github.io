// An example of a do-while loop.
// For CS211. Jan 2020
#include <stdio.h>

int main(void)
{
  int a;

  do 
  {
    printf("Enter an even number : ");
    scanf("%d", &a);
  } while ( a%2 != 0);
  
  printf("Number %d accepted.\n", a);

  return(0);
}
