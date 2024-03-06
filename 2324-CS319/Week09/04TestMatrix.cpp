// File:     02TestMatrix.h (Set v=A*u)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 9 of 2324-CS319
// What:     Test the implementation Matrix class
// See also: Vector.h Vector.cpp Matrix.h and Matrix.cpp 

#include <iostream>
#include <stdlib.h>

#include "Vector.h"
#include "Matrix.h"

//  Compute a matrix-vector product (v=A*u)
void MatVec(Matrix &A, Vector &u, Vector &v);

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

  std::cout << std::endl << "x=" << std::endl;
  x.print();

  std::cout << std::endl << "Setting b=A*x" <<std::endl;

  MatVec(A, x, b);
  std::cout << std::endl << "b=" << std::endl;
  b.print();

  return (0);
}


//////////////////
//  Set v=A*u
void MatVec(Matrix &A, Vector &u, Vector &v)
{
  unsigned int N;
  N = A.size();
  if ( (N != u.size()) || ( N != v.size() ) )
    std::cerr << "dimension mismatch in MatVec " << std::endl;
  else
    for (unsigned int i=0; i<N; i++)
    {
      double x=0;
      for (unsigned int j=0; j<N; j++)
	x += A.getij(i,j)*u.geti(j);
      v.seti(i,x);
    }
}
