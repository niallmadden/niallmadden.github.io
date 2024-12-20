// 03DeleteLines.c 
// Read lines from an input file, and store every 5th one 
// in an output file.
// For 2021-CS211 Week 7
// Author: Niall Madden

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *infile, *outfile;
  char InFileName[99], OutFileName[99], Line[99];
  int i;

  printf("Enter the name of the input file: ");
  scanf("%s", InFileName);
  printf("Enter the name of the output file: ");
  scanf("%s", OutFileName);

  infile = fopen(InFileName, "r");
  if (infile == NULL)
  {    
    printf("Can't open %s in read mode\n",
	   InFileName);
    exit(EXIT_FAILURE);
  }
  outfile = fopen(OutFileName, "w");
  if (outfile == NULL)
  {    
    printf("Can't open %s in write mode\n",
	   OutFileName);
    exit(EXIT_FAILURE);
  }

  i=0;
  while ( fgets(Line, 99, infile) != NULL )
  {
    i++;
    if (i%5 == 0)
      fputs(Line, outfile);
  }

  fclose(infile);
  fclose(outfile);
  
  return(EXIT_SUCCESS);
}

