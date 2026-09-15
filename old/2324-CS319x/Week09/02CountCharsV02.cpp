// File:   02CountCharsV02.cpp
// Data:   March 2024
// Version 02 of our programme that reads the contents of the file
// CPlusPlusTerms.txt and reports the number of characters and lines.
// This one also outputs the running directory
// For more information: 
//    see http://www.maths.nuigalway.ie/~niall/CS319/Week05

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  std::cout << "Note: this program is running as " << argv[0];
  std::cout << "\nMake sure you download the input file to the same folder";
  std::cout << std::endl;
  
  std::ifstream InFile;
  std::string InFileName;
  char c;
  int CharCount=0, LineCount=0;

  std::cout << "Input the name of a file: " << std::endl;
  std::cin >> InFileName;
  InFile.open(InFileName.c_str());

  while (InFile.fail() )
  {
     std::cout << "Cannot open " << InFileName << " for reading." << std::endl;
     std::cout << "Enter another file name : ";
     std::cin >> InFileName;
     InFile.open(InFileName.c_str());
  }
  std::cout << "Successfully opened " << InFileName << std::endl;
  InFile.get( c );

  while( ! InFile.eof() ) {
    CharCount++;
    if (c == '\n')
       LineCount++;
    InFile.get( c );
  }
  std::cout  << InFileName << " contains " 
       << CharCount << " characters and "
       << LineCount << " lines.\n";

  InFile.close();

  return(0);
} 
