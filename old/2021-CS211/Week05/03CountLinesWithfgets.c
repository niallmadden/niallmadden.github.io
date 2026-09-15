/*  Use fgets to count the number of lines in a file.
    For CS211; Week 05 
    Author: NM */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_length(FILE *);

int main( void)
{
  char FileName[30];
  FILE *file;

  strcpy(FileName, "03CountLinesWithfgets.c");

  file=fopen(FileName, "r");

  printf("%s has %d lines\n", FileName, file_length(file));

  return(EXIT_SUCCESS);
}

int file_length(FILE *file)
{
  int lines;
  char dummy[100];

  rewind(file);

  lines=0;
  while( fgets(dummy, 100, file) != NULL)
    lines++;

  rewind(file);

  return(lines);
}
