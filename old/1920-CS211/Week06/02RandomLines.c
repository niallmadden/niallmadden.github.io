//  This program reads *this* file and outputs the lines in a random order.
//  For 1920-CS211 Week 6
//  Author: Niall Madden
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void )
{
  int i, NumberOfLines=0, Deleted, WhichLine;
  char lines[100][100], FileName[30];
  FILE *infile;

  strcpy(FileName, "02RandomLines.c");
  infile = fopen(FileName, "r");
  if (infile == NULL)
  {
    printf("Error: can't open %s for reading",
	   FileName);
    exit(EXIT_FAILURE);
  }

  for (i=0; (fgets(lines[i], 99, infile)) != NULL; i++) 
    NumberOfLines++;

  fclose(infile);

  // Now display non-empty lines in a random order
  Deleted=0;
  while(Deleted < NumberOfLines)
  {
    WhichLine = rand()%NumberOfLines;
    if (lines[WhichLine][0] != '\0')
    {
      printf("%s", lines[WhichLine]);
      lines[WhichLine][0]='\0';
      Deleted++;
    }
  }
  return(EXIT_SUCCESS);
}

