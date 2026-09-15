/*  Demonstrate using strings, strcpy, and computing the 
    length of a  string.
    For CS211, Week 04
    Author: NM */

#include <stdio.h>
#include <string.h> // Needed for strcpy

int length(char *);

int main(void )
{
  char greeting[20];
  strcpy(greeting, "Hello. How are you?");
  printf("%s\n", greeting);
  printf("That message was %d chars long.\n", length(greeting) );
  return(0);
}

int length(char *str)
{
  int i, len=0;

  for (i=0; str[i] != '\0'; i++)
    len++;

  return(len);
}
