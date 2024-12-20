/*------------------------------------------------------*\
|  Using fseek to  output the content of a file backwards|
|  For CS211 Week 06.                                    |
|  Author: Niall Madden (Niall.Madden@NUIGalway.ie)      |
\*------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main( void)
{
  FILE *InFile;
  char c;
  
  InFile=fopen("01Reverse.c", "r");
  if ( InFile == NULL )
  {
    printf("Error - could not open the file\n");
    exit(1);
  }
  
  // First go to the end of the file
  fseek(InFile, 0, SEEK_END);
  
  // Now read lines in reverse order
  while (ftell(InFile) != 0) 
  {
    c=fgetc(InFile);
    putchar(c);
    fseek(InFile, -2, SEEK_CUR);
  }
  
  fclose(InFile);
  return(0);
}
