#include <stdio.h>

typedef enum {CLUBS, DIAMONDS, HEARTS,  SPADES} SUIT;

int main(void )
{
  SUIT s1=CLUBS, s2;

  for (s2=0; s2<10;s2++)
  {
    printf("s1=%d\n", s1);
    s1++;
  }
}
