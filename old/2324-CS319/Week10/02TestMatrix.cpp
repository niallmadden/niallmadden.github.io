// File:     02TestMatrix.h (Set v=A*u)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 10 of 2324-CS319
// What:     Test the implementation Matrix class
// See also: Vector10.h Vector10.cpp Matrix10.h and Matrix10.cpp 

#include <iostream>
#include <stdlib.h>

#include "Vector10.h"
#include "Matrix10.h"

int main(void )
{
  unsigned int N=3;
   
  Matrix A(N);
  Vector x(N), b(N);
  
  for (unsigned int i=0; i<N; i++)
  {
    for (unsigned int j=0; j<N; j++)
      A.setij(i, j, (double)(rand()%10-5));
    x.seti(i, 1.0);
  }

  std::cout << "A=" << std::endl;
  A.print();

  std::cout << std::endl << "x=" << x << std::endl;

  std::cout << std::endl << "Setting b=A*x" <<std::endl;
  b = A*x;
  std::cout << std::endl << "b=" << b << std::endl;

  return (0);
}

