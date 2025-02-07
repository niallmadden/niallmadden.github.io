// 00triplet_example.cpp 2324-CS319 Week 11
//   What: Demonstrate the use the Triplet class.
//         It generates a linear system, and solves it
//         using a Jacobi Method.
// Author: Niall Madden

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>

#include "Vector10.h"
#include "Matrix11.h"
#include "Triplet.h"

Triplet full2Triplet(Matrix &F, unsigned int NNZ_MAX);

void Jacobi(Matrix &A, Vector &b, Vector &v,
	    unsigned int &count, double tol=1e-6, unsigned int MaxIts=4);
void Jacobi(Triplet &A, Vector &b, Vector &v,
	    unsigned int &count, double tol=1e-6, unsigned int MaxIts=4);

void Banner(void);

int main(void )
{
  unsigned int N=100, Max_Its=200;
  double TOL=1e-8;
  Banner();

  Matrix A(N);
  Triplet T(N, 3*N);
  Vector x(N), b(N);
   
  // Form system Matrix, A, and solution Vector x
  // We'll initially make  A as a "full" Matrix, and then
  // convert to Triplet
  A.zero();

  A.setij(0,0, 1.0);
  x.seti(0, 1.0 );
  for (unsigned int i=1; i<N-1; i++)
  {
    A.setij(i,i-1, -1.0);
    A.setij(i,i,    2.5);
    A.setij(i,i+1, -1.0);
    x.seti(i, 1.0 );
  }
  A.setij(N-1,N-1,  2.0);
  x.seti(N-1, 1.0 );

  b=A*x;  // Choose the right-hand side, b, so x solves Ax=b

  T=full2Triplet(A, 3*N);

//    If you would like to see the Matrix and Vectors, uncomment the
//       next lines;
//  std::cout << "The Matrix A is:" << std::endl;
//  A.print();
//  std::cout << "The Triplet Matrix is T="<< std::endl;
//  T.print();
//  std::cout << "The Vector x is " << x << std::endl;


  ////////////////////////////////////
  // Start of solver section.
  // For the Jacobi iteration, need an initial guess, Vector "est",
  //   and Vector for difference between true and esst
  Vector est(N), error(N);
  est.zero();
  unsigned int iterations;
//  clock_t start, stop;

  // First apply Jacobi to the "full" Matrix
  auto start = std::chrono::high_resolution_clock::now();
  Jacobi(A, b, est, iterations, TOL, Max_Its);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> full_duration = end - start;
  std::cout << "Jacobi for full Matrix took " << iterations <<
    " iterations. (" << full_duration.count() << " seconds)." << std::endl;
  error = x-est;
  std::cout << "Norm of error is : " <<  error.norm() << std::endl;

  // Now verify that we get the same solution from the Triplet Matrix
  est.zero();
  start = std::chrono::high_resolution_clock::now();
  Jacobi(T, b, est, iterations, TOL, Max_Its);
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> sparse_duration = end - start;

  error = x-est;
  std::cout << "Jacobi for Triplet took " << iterations <<
    " iterations. (" << sparse_duration.count() << " seconds)." << std::endl;
  std::cout << "Norm of error is : " <<  error.norm() << std::endl;

  std::cout << "Speed up: " <<  full_duration.count()/sparse_duration.count()
	    << std::endl;
  return (0);
}


// Use Jacobi's method to solve Ax=b,
// On entry: x is the initial guess
// On exit : x is the estimate for the solution
//  **** Full Matrix Version ****
void Jacobi(Matrix &A, Vector &b, Vector &x,
	    unsigned int &count, double tol, unsigned int Max_Its)
{
  unsigned int N= A.size();
  count =0;
  if ( (N != b.size()) || (N != x.size() ) )
    std::cout << "Jacobi: error - A must be the same size as b,x\n";

  // Form the diagonal and off-diagonal matrices
  Matrix Dinv(N), T(N);
  for (unsigned int i=0; i<N; i++)
    for (unsigned int j=0; j<N; j++)
      if (j != i)
      {
	T.setij(i,j, -A.getij(i,j));
	Dinv.setij(i,j,0.0);
      }
      else
      {
	T.setij(i,j, 0.0);
	Dinv.setij(i,j, 1.0/A.getij(i,j));
      }



  // Now implement the algorithm:
  Vector r(N);
  r.zero();
  do
  {
    count++;
    x = Dinv*(b+T*x); // set x = inverse(D)*(b+T*x)
    r=b-A*x; // set r=b-A*r
  }   while ( (r.norm() > tol) && (count < Max_Its));

}


// Use Jacobi's method to solve Ax=b,
// On entry: x is the initial guess
// On exit : x is the estimate for the solution
//  **** Triplet Matrix Version ****
void Jacobi(Triplet &A, Vector &b, Vector &x,
	    unsigned int &count, double tol, unsigned int Max_Its)
{
  unsigned int N= A.size();
  count =0;
  if ( (N != b.size()) || (N != x.size() ) )
    std::cout << "Jacobi: error - A must be the same size as b,x\n";

  // Form the diagonal and off-diagonal matrices
  Triplet Dinv(N, N), T(N, 3*N);
  for (unsigned int k=0; k<A.nnz(); k++)
  {
    unsigned int i=A.getI(k), j=A.getJ(k);
    double x=A.getX(k);
    if (i != j)
      T.setij(i,j, -x);
    else
      Dinv.setij(i,j, 1.0/x);
  }

  //   Now implement the algorithm.
  Vector r(N);
  r.zero();
  do
  {
    count++;
    x = Dinv*(b+T*x); // set x = inverse(D)*(b+T*x)
    r=b-A*x; // set r=b-A*r
  }   while ( (r.norm() > tol) && (count < Max_Its));

}

void Banner(void )
{
  std::cout << "\n\n\n";
  std::cout << " ---------------------------------------------------------\n";
  std::cout << "|      01Triplet_example.cpp for CS319: Week 11            |\n";
  std::cout << "|  Demonstrate the 'Triplet' sparse Matrix storage format. |\n";
  std::cout << " ---------------------------------------------------------\n";
}

