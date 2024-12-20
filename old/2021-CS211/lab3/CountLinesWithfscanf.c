// CountLinesWithfscanf.c: count the number of lines in 
// "SmallDictionary.txt" using the fscanf function
// For 2021-CS211 - Lab 3+4
// Who:  Niall Madden
// When: 15 March 2021
// Why:  Help students get started in Lab 3
// More: Contact Niall.Madden@NUIGalway.ie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *file;
  char FileName[30], NewWord[50];
  int NumberOfWords;

  printf("\n---------------------------------------------------\n");
  printf("This is CountLinesWithfscanf.c - written for 2021-CS211 Lab 3+4\n");

  strcpy(FileName, "SmallDictionary.txt");
  file=fopen(FileName, "r");
  if (file ==NULL)
  {
    printf("Sorry - can't open %s for reading\n", FileName);
    return(1);
  }
  else
    printf("Successfully opened %s for reading\n", FileName);

  NumberOfWords=0;
  while( fscanf(file, "%s", NewWord) != EOF)
  {
//    printf("Word %3d is %20s, and has length %ld\n",
//	   NumberOfWords, NewWord, strlen(NewWord));
    NumberOfWords++;
  }

  printf("File %s stores %d words\n",
	 FileName, NumberOfWords);

  fclose(file);

}
