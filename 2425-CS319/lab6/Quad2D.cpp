// Quad2D.cpp (similar to 00Trap2D.cpp from Week 7)
// Implements the 2D trapezium rule using quadrature weights.
// This is (much) easier to generalise.
// For CS319 Lab 6.

#include <iostream>
#include <cmath>  // For exp()
#include <string>

double f(double x1, double x2) {  return(exp(x1+x2)); } 
double a=0.0, b=1.0;  // limits of int in both x1 and x2
double ans_true = pow(exp(1.0)-1.0,2); // true value 

double Quad2D(double **y, double *w, unsigned int N);		

int main(void )
{
  unsigned N = 16; // Number of points in each direction
  double h = (b-a)/double(N); // step-size in both x1 and x2
  double *x1, *x2, *w, **y; // quadrature points, weights and values.

  x1 = new double[N+1];
  x2 = new double[N+1];

  for(unsigned i = 0; i < N+1; i++)
  {
    x1[i] = a+i*h;
    x2[i] = a+i*h;
  }
  
  y = new double * [N+1];
  for(unsigned i = 0; i < N+1; i++)
    y[i] = new double[N+1];

  for (unsigned i=0; i<N+1; i++)
    for (unsigned j=0; j<N+1; j++)
      y[i][j] = f(x1[i], x2[j]);

  // Define the weights for 1D Trapezium Rule
  // These are [1,2,2,2, ..., 2,1]/2
  w = new double[N+1];
  w[0]=h/2.0;
  for (unsigned i=1; i<N; i++)
    w[i]=h;
  w[N]=h/2.0;
  
  double est1 = Quad2D(y, w, N);
  double error1 = fabs(ans_true - est1);

  std::cout << "N=" <<  N << " | est=" << est1
	    << " | error = " << error1 << std::endl;

  // De-allocate memory (this was omitted from an earlier version)
  delete [] x1;
  delete [] x2;
  for(unsigned i = 0; i < N+1; i++)
    delete [] y[i];
  delete [] y;

  return(0);
}

double Quad2D(double **y, double *w,  unsigned N)
{
  double Q;

  Q=0;
  for (unsigned i=0; i<=N; i++)
    for (unsigned j=0; j<=N; j++)
      Q += w[i]*w[j]*y[i][j];

  return(Q);
}

