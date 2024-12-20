// CrossWordHelperV01.c: A really bad crossword helper 
// For 2021-CS211 - Lab 3+4
// Who:  Niall Madden
// When: 15 March 2021
// Why:  Help students get started in Lab 3+4
// More: Contact Niall.Madden@NUIGalway.ie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Match(char Guess[], char clue[]);  // The function take char arrays 
   // Guess and clue and returns 1 if they match. Otherwise, return 0.

int main(void)
{
  char clue[20];
  char ListOfWords[5][20] = 
    {"Algorithm", "Binary", "Compiler", "Debug", "Ethernet"};
  int k, n=5;

  printf("\n---------------------------------------------------\n");
  printf("This is CrossWordHelperV01 - written for CS211 Lab 3+4\n");
  printf("To enter a crossword string, use ? to represent an unknown letter\n");
  printf("This will then be matched against a dictionary word. \n");
  printf("This BASIC version will only match with words of the same length.\n");

  printf("Enter a crossword string: ");
  scanf("%s", clue); // Note we don't use  &clue, because if clue[]
  // is an array, then clue (without []) is its address. 
  
  for (k=0; k<n; k++)
    if (Match(ListOfWords[k], clue) == 1)
      printf("%s matches %s\n", clue, ListOfWords[k]);
  
  return(0);
}
  
int Match(char Guess[], char clue[]) // Try to match the clue with the guess.
// In this version we only check if the words have the same number of letters
{
  if (strlen(Guess) != strlen(clue))
    return(0);
  else 
    return(1);
}
