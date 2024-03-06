// File:     Matrix.cpp (Methods for Matrix class)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 9 of 2324-CS319
// See also: Matrix.h and 02TestMatrix.cpp 

#include <iostream>
#include "Matrix.h"

Matrix::Matrix (unsigned int Size) 
{
  N = Size;
  entries = new double [N*N];
}

void Matrix::setij (unsigned int i, unsigned int j, double x)
{
  if (i<N && j<N)
    entries[i*N+j]=x;
  else
    std::cerr << "Matrix::setij(): Index out of bounds."
	      << std::endl;
}

double Matrix::getij (unsigned int i, unsigned int j)
{
  if (i<N && j<N)
    return(entries[i*N+j]);
  else
  {
    std::cerr << "Matrix::getij(): Index out of bounds."
	      << std::endl;
    return(0);
  }
}

void Matrix::print (void)
{
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      std::cout << "[" << entries[i*N+j] << "]";
    std::cout << std::endl;
  }
}
