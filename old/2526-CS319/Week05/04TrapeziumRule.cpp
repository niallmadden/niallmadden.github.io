// 04TrapeziumRule.cpp
// Compare with QuadratureV04.cpp  from Week 4
// Week 05: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()
#include <iomanip>  

double f(double x) {  return(exp(x)); } // definition
double ans_true = exp(1.0)-1.0; // true value of integral

double Quad1(double *x, double *y, unsigned int N);		

int main(void )
{
  unsigned int N;
  double a=0.0, b=1.0; // limits of integration
  double *x; // quadrature points
  double *y; // quadrature values

  std::cout << "Enter the number of intervals: ";
  std::cin >> N; // not doing input checking 

  x = new double[N+1];
  y = new double[N+1];
  double h = (b-a)/double(N);
  for (unsigned int i=0; i<=N; i++)
  {
    x[i] = a+i*h;
    y[i] = f(x[i]);
  }
  double Est1 = Quad1(x, y, N);
  double error = fabs(ans_true - Est1);
  std::cout << "N=" << N << ", Trap Rule="
	    << std::setprecision(6) << Est1
	    << ", error=" <<  std::scientific 
	    << error << std::endl;

  delete [] x;
  delete [] y;
  return(0);
}

double Quad1(double *x, double *y, unsigned int N)
{
  double h = (x[N]-x[0])/double(N);
  double Q = 0.5*(y[0] + y[N]);
  for (unsigned int i=1; i<N; i++)
    Q += y[i];
  Q *= h;
  return(Q);
}


