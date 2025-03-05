// File:   02CountChars.cpp
// Date:   March 2025
// First example of a C++ program that uses file streams. 
// See also  CPlusPlusTerms.txt   
// For more information: 
//    see https://www.niallmadden.ie/2425-CS319/#Week08

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(void )
{
  char c;
  std::ifstream InFile;
  InFile.open("CPlusPlusTerms.txt");
  std::cout << "Processing the contents of CPlusPlusTerms.txt"
	    << std::endl;

  std::ofstream OutFile;
  OutFile.open("Output.txt");
  std::cout << " See file Output.txt for more information."
	    << std::endl;

  int i=0;
  InFile.get( c );

  while( ! InFile.eof() ) {
    i++;
    InFile.get( c );
  }
  
  OutFile <<
    "CPlusPlusTerms.txt contains " 
	  << i << " characters \n";

  InFile.close();
  OutFile.close();

  return(0);
} 
