// An example of using break and continue
// For CS211. Feb 2021
#include <stdio.h>

int main(void)
{
  int a;
  
  for (a=0; a<=100; a++) 
  {
    if (a%2 != 0)
      continue;
    printf("a=%d\n", a);
    
    if (a>=10)
      break;
  };
  
  return(0);
}
