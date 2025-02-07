// File:   03FlipPBM.cpp
// Data:   March 2024
// Read an image stored in PBM format, and output the negative
// For more information: 
//    see http://www.maths.nuigalway.ie/~niall/CS319/Week05

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(void )
{
  std::ifstream InFile;
  std::ofstream OutFile;
  std::string InFileName, OutFileName;

  std::cout << "Input the name of a PBM file: " << std::endl;
  std::cin >> InFileName;
  InFile.open(InFileName.c_str());

  while (InFile.fail() )
  {
     std::cout << "Cannot open " << InFileName << " for reading."
	       << std::endl;
     std::cout << "Enter another file name : ";
     std::cin >> InFileName;
     InFile.open(InFileName.c_str());
  }
  std::cout << "Successfully opened " << InFileName << std::endl;

  // Open the output file
  OutFileName = "Negative_"+InFileName;
  OutFile.open(OutFileName.c_str());
  
  std::string line;
  // Read the "P1" at the start of the file
  InFile >> line;
  OutFile << "P1" << std::endl;

  // Read the number of columns and rows
  unsigned int rows, cols;
  InFile >> cols >> rows;
  OutFile << cols << " " << rows << std::endl;
  
  std::cout << "read: cols=" << cols << ", rows="
	    << rows <<std::endl;

  for (unsigned int i=0; i<rows; i++)
  {
    for (unsigned int j=0; j<cols; j++)
    {
      int pixel;
      InFile >> pixel;
      OutFile << 1-pixel << " ";
    }
    OutFile << std::endl;
  }
  InFile.close();
  OutFile.close();

  std::cout << "Negative of " << InFileName << " written to "
	    << OutFileName << std::endl;
  return(0);
} 
