// File:   02CountChars.cpp
// Date:   March 2024
// First example of a C++ program that uses file streams. 
// See also  CPlusPlusTerms.txt   
// For more information: 
//    see http://www.maths.nuigalway.ie/~niall/CS319/Week05

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(void )
{
  std::ifstream InFile;
  std::ofstream OutFile;
  char c;

  std::cout << "Processing the contents of CPlusPlusTerms.txt"  << std::endl;
  std::cout << " See file Output.txt for more information." << std::endl;
  InFile.open("CPlusPlusTerms.txt");
  OutFile.open("Output.txt");

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
