// File:   00Library-CSV.cpp
// Author: Niall Madden 
// Read data stored in a CSV file

#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>
#include <cstdlib> // For EXIT-FAILURE and atoi

int main(void) {
  std::ifstream InFile;
  std::string InFileName="Library.csv";  
  
  InFile.open(InFileName.c_str());

  if (InFile.fail())  {
    std::cerr << "Error - can't open " << InFileName << std::endl;
    exit(EXIT_FAILURE);
  }
 
  // Count the number of entries
  char c;
  int Lines=0;
  InFile.get(c);
  while(!InFile.eof())
  {
    if (c=='\n')
      Lines++;
    InFile.get(c);
  }
  std::cout << "There are " << Lines << " in " <<
    InFileName << std::endl;
  InFile.clear(); // Clear the eof flag
  InFile.seekg(std::ios::beg); // rewind to beginning.

  std::string *Author = new std::string [Lines],
    *Title = new std::string [Lines];
  int *CallNumber = new int [Lines];

  char str_tmp[100]; 
  for (int i=0; i< Lines; i++) {
     InFile.get(str_tmp, 99, ','); 
     Title[i] = str_tmp;
     InFile.ignore();

     InFile.get(str_tmp, 99, ','); 
     Author[i] = str_tmp;
     InFile.ignore();
     
     InFile.get(str_tmp, 99, '\n'); 
     CallNumber[i] = atoi(str_tmp);
     InFile.ignore();
  }

  std::cout << "Here are the 5133 books: " << std::endl;
  for (int i=0; i< Lines; i++)
  {
     if (CallNumber[i] == 5133)
       std::cout << std::setw(20) << Author[i] << ": " 
	     << Title[i] << std::endl;
  }
  return(0);
}
