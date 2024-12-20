/* 02uppitty.c
 WHAT: Convert chars from lower to upper case.
 WHY:  An example of working with chars in C
 WHEN: Week 04 of 1920-CS211
 WHO:  Niall.Madden@NUIGalway.ie 
 See also: there is a standard function "toupper" in <ctype.h>
      that does the same thing (but better)
*/

#include <stdio.h>

char uppitty(char c);

int main(void ) {
  char c;

  while( (c=getchar()) != '\n')
      printf("uppitty( %c ) = %c \n", c, uppitty(c));

  return(0);
}

char uppitty(char a)
{
  // Check if it is a lower-case character
  if ((a >= 'a') && (a <= 'z'))
    return(a - 'a' + 'A');
  else 
    return(a);
}
      
