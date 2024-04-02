// File:   01Matrix-CSV.cpp
// Author: Niall Madden 
// Read and write data for a matrix to/from a CSV file
// WARNINGS:
//  1. We assume the matrix is square (same number of rows as columns)
//  2. We determine the size by counting the number of commas in the first line
//  3. Errors in the CSV file are not identified.
//  4. The code uses Matrix10.cpp and Matrix10.h , bu with a minor big-fix
//     for the overloaded assignment operator.

#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>

#include "Matrix11.h"
#include "Vector10.h"

// Headers for functions for reading and writing matrices
Matrix ReadMatrixCSV(std::string FileName);
void WriteMatrixCSV(Matrix M, std::string FileName, int p=5);

int main(void)
{
  Matrix M;
  M = ReadMatrixCSV("matrix1.csv");   // Read a matrix from a file
  std::cout << "Matrix read from matrix1.csv. It is: "
	    << std::endl;
  M.print();

  // Make the transpose of that matrix
  Matrix T(M.size());
  for (unsigned i=0; i<M.size(); i++)
    for (unsigned j=0; j<M.size(); j++)
      T.setij(j,i, M.getij(i,j));

  std::cout << "\nTranspose of M is : " << std::endl;
  T.print();
  // Write that matrix to a file, to 8 digits of precision
  std::cout << "Writing the tranpose to transpose.csv\n";
  WriteMatrixCSV(T, "transpose.csv", 8);
  
  return(0);
}

// Function to read a matrix stored in a CSV file.
// Input: string containing the file name
// Output: Matrix object 
Matrix ReadMatrixCSV(std::string InputFileName)
{
  std::ifstream InputFile;

  // open InputFileName for reading
  InputFile.open(InputFileName.c_str());
  if (InputFile.fail())
  {
    std::cerr << "Error - can't open " << InputFileName
	      << std::endl;
    exit(1);
  }

  // We'll determine the size of the matrix by reading the
  // first line and counting the commas
  unsigned N=0;
  char c; // 
  InputFile.get(c);
  while((c!='\n') && (!InputFile.eof()) )
  {
    if (c==',')
      N++;
    InputFile.get(c);
  }
  N++;
  std::cout << InputFileName << " has " << N << " columns.\n";
  Matrix M(N); // make an N-N matrix
  M.zero();

  InputFile.clear(); // Clear the eof flag
  InputFile.seekg(std::ios::beg); // reset point to start of file
  double f;
  for (unsigned i=0; i<N; i++)
    for (unsigned j=0; j<N; j++)
    {
      InputFile >> f;
      if (InputFile.eof())
      {
	std::cout << "WARNING: end of file before matrix read";
	break;
      }
      M.setij(i,j,f);
      InputFile >> c;
    }
  
  //M.print();
  InputFile.close();
  return(M);
}

// Write a matrix to a csv file
// Inputs: Matrix object, string with file name, int with precision
void WriteMatrixCSV(Matrix M, std::string FileName, int p) {
  std::ofstream OutputFile;

  OutputFile.open(FileName.c_str());
  if (OutputFile.fail())  {
    std::cerr << "Error - can't open " << FileName << std::endl;
    exit(1);
  }
  OutputFile.precision(p);

  unsigned N=M.size();
  for (unsigned i=0; i<N; i++)
    for (unsigned j=0; j<N; j++) {
      OutputFile << M.getij(i,j);
      if (j<(N-1))
	OutputFile << ",";
      else
	OutputFile << std::endl;
    }
  OutputFile.close();
}

