// File:     Jacobi-Lab7.cpp: Jacobi's method for solving linear systems
// Date:     March, 2025.
// What:     Solving a linear system of equations with Jacobi's method,
//            but without any classes, objects, or operator overloading.

#include <iostream>
#include <stdlib.h>
#include <cmath>

void print_vec(double *v, unsigned int N);

int main(void )
{
  unsigned int N=3;

  double **A, // system matrix
    *x,       // true solution
    *b,       // right-hand side
    *xk,      // initial guess
    *xk1;      // improved estimate

  // Memory allocation
  x = new double[N];
  xk = new double[N];
  xk1 = new double[N];
  b = new double[N];
  A = new double * [N];
  for(unsigned int i=0; i<N; i++)
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
  xk[0]=0;  xk[1]=0;  xk[2]=0;
  
  // 5 iterations of Jacobi
  for (unsigned int k=0; k<15; k++)
  {
    for (unsigned int i=0; i<N; i++)
    {
      xk1[i] = b[i];
      for (unsigned int j=0; j<N; j++)
	if (j != i)
	  xk1[i] -= A[i][j]*xk[j];
      x[i] /= A[i][i];
    }
    
    for (unsigned int i=0; i<N; i++)
      xk[i]=xk1[i];
  }
  
  std::cout << "Estimate is : " << std::endl;
  print_vec(xk1, N);
  return (0);
}

void print_vec(double *x, unsigned int N)
{
  std::cout << "[";
  for (unsigned int i=0; i<N; i++)
    std::cout << x[i] << ", ";
  std::cout << "]";
}
  
