/*---------------------------------------------------*\
|  Use fgetc to count the number of lines in a file.  |
|    For CS211.   Author: NM                          |
\*---------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_length(FILE *);

int main( void)
{
  FILE *file;
  char FileName[30];

  strcpy(FileName, "04CountLinesWithfgetc.c");

  file=fopen(FileName, "r");

  printf("%s has %d lines\n", FileName, file_length(file));

  return(0);
}

int file_length(FILE *file)
{
  int lines;
  char c;

  rewind(file);

  lines=0;
  do {
    c = fgetc(file);
    if (c == '\n')
      lines++;
  } while(c != EOF);

  rewind(file);
  return(lines);
}
