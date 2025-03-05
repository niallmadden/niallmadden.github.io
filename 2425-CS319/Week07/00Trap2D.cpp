// 00Trap2D.cpp
// Apply the Traezium Rule to a 2D integration problem.
// while also demo'ing 2D dynamic memory allocation.
// Week 07: CS319 - Scientific Computing

#include <iostream>
#include <cmath>  // For exp()
#include <string>

double f(double x1, double x2) {  return(exp(x1+x2)); } 
double ans_true = pow(exp(1.0)-1.0,2); // true value 

double Trap2D(double *x1, double *x2,
	      double **y, unsigned int N);		

int main(void )
{
  unsigned N = pow(2,15);     // Number of points in each direction
  double a1=0.0, b1=1.0, a2=0.0, b2=1.0;       // limits of int
  double h1, h2;             // step-size in x1 and x2
  double *x1, *x2, **y;      // quadrature points and values

  x1 = new double[N+1];
  x2 = new double[N+1];

  h1 = (b1-a1)/double(N);
  h2 = (b2-a2)/double(N);
  for(unsigned i = 0; i < N+1; i++)
  {
    x1[i] = a1+i*h1;
    x2[i] = a2+i*h2;
  }
  
  y = new double * [N+1];
  for(unsigned i = 0; i < N+1; i++)
    y[i] = new double[N+1];

  for (unsigned i=0; i<N+1; i++)
    for (unsigned j=0; j<N+1; j++)
      y[i][j] = f(x1[i], x2[j]);
  
  double est1 = Trap2D(x1, x2, y, N);
  double error1 = fabs(ans_true - est1);

  std::cout << "N=" <<  N << " | est=" << est1
	    << " | error = " << error1 << std::endl;

  // De-allocate memory
  delete [] x1;
  delete [] x2;
  for(unsigned i = 0; i < N+1; i++)
    delete [] y[i];
  delete [] y;

  return(0);
}

double Trap2D(double *x1, double *x2, double **y,
	      unsigned N)
{
  double Q, h1 = (x1[N]-x1[0])/double(N), 
    h2 = (x2[N]-x2[0])/double(N);

  Q = 0.25*(y[0][0] + y[N][0]  // 4 corners
	    + y[0][N] + y[N][N]);
  
  for (unsigned k=1; k<N; k++)  // 4 edges (not including corners)
    Q += 0.5*(y[k][0] + y[k][N]
	      + y[0][k] + y[N][k]);

  for (unsigned i=1; i<N; i++) // All the points in the interior
    for (unsigned j=1; j<N; j++)
      Q += y[i][j];

  Q *= h1*h2;
  return(Q);
}

