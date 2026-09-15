// File:     Lab7-solution.cpp: Partial solution to Lab 7:
//           Jacobi's method for solving linear systems
// Date:     March, 2025
// What:     Solving a linear system of equations with Jacobi's method,
//           but without any classes, objects, or operator overloading.

#include <iostream>
#include <stdlib.h>
#include <cmath>

void print_vec(double *v, unsigned N);
double norm(double *x, unsigned N);
double diff(double *, double *, unsigned);

void Jacobi(double **A, double *b, double *xk, unsigned N,
            unsigned &count, unsigned max_its, double TOL);

int main(void )
{
  unsigned int N=3;

  double **A, // system matrix
    *x,       // true solution
    *b,       // right-hand side
    *xk;      // initial guess

  unsigned max_its = 15, it_count;
  double TOL=1.0e-4;

  // Memory allocation
  x = new double[N];
  xk = new double[N];
  b = new double[N];
  A = new double * [N];
  for(unsigned i=0; i<N; i++)
    A[i] = new double[N];

  // Set up the linear system to solve, which is
  // 9*x_1 + 3*x_2 + 3*x_3 = 15
  // 3*x_1 + 9*x_2 + 3*x_3 = 15
  // 3*x_1 + 3*x_2 + 9*x_3 = 15
  A[0][0]=9;   A[0][1]=3;   A[0][2]=3; 
  A[1][0]=3;   A[1][1]=9;   A[1][2]=3; 
  A[2][0]=3;   A[2][1]=3;   A[2][2]=9;
  b[0]=15;     b[1]=15;     b[2]=15;
  x[0]=1;      x[1]=1;      x[2]=1;
  
  // Initial guess for Jacobi
  xk[0]=0;     xk[1]=0;   xk[2]=0;

  Jacobi(A,b,xk,N, it_count, max_its, TOL);
  
  std::cout << "Jacobi Estimate is : " << std::endl;
  print_vec(xk, N);
  std::cout << std::endl;
  std::cout << "Jacobi took " << it_count << " iterations" << std::endl;
  std::cout << "Error is " << diff(xk,x,N) << std::endl;

  return (0);
}

void Jacobi(double **A, double *b, double *xk, unsigned N,
            unsigned &count, unsigned max_its, double TOL)
{
  double *xk1, *R; 
  xk1 = new double[N];
  R = new double[N];

  count = 0;
  double Rnorm=TOL+1;
  while ( (Rnorm > TOL) && (count<max_its))
  {
    count++;
    for (unsigned i=0; i<N; i++)
    {
      xk1[i] = b[i];
      for (unsigned j=0; j<N; j++)
	if (j != i)
	  xk1[i] -= A[i][j]*xk[j];
      xk1[i] /= A[i][i];
    }
    
    // Compute the residual
    for (unsigned i=0; i<N; i++)
    {
      R[i]= b[i];
      for (unsigned j=0; j<N; j++)
	R[i]-= A[i][j]*xk[j];
      Rnorm = norm(R,N);
    }
    for (unsigned i=0; i<N; i++)
      xk[i]=xk1[i];
  } 
}  

void print_vec(double *x, unsigned N)
{
  std::cout << "[";
  for (unsigned i=0; i<N; i++)
    std::cout << x[i] << ", ";
  std::cout << "]";
}
  
double diff(double *x1, double *x2, unsigned N)
{
  double *y;
  y = new double[N];
  
  for (unsigned i=0; i<N; i++)
    y[i] = x1[i]-x2[i];
  return( norm(y,N) );
}

double norm(double *x, unsigned N)
{
  double n=0;
  for (unsigned i=0; i<N; i++)
    n += x[i]*x[i];
  return( sqrt(n) );
}

