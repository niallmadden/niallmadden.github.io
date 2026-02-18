// 00CompareRules.cpp
// Compare the Traezium and Simpson's Rule
// Week 06: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()
#include <iomanip>  

double f(double x) {  return(exp(x)); } // definition
double ans_true = exp(1.0)-1.0; // true value of integral

double Quad1(double *x, double *y, unsigned int N);		
double Quad2(double *x, double *y, unsigned int N);		

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

  double Est1 = Quad1(x,y,N);
  double Est2 = Quad2(x,y,N);
  double error1 = fabs(ans_true - Est1);
  double error2 = fabs(ans_true - Est2);

  std::cout << " N=" << N << std::scientific;
  std::cout <<  std::setprecision(4);
  std::cout << " | Trap Error=" << error1;
  std::cout << " | Simp Error=" << error2;
  std::cout << std::endl;
  delete [] x; delete [] y;
  return(0);
}

double Quad1(double *x, double *y, unsigned int N)
{
  double h = (x[N]-x[0])/double(N);
  double Q = 0.5*(y[0]+y[N]);
  for (unsigned int i=1; i<N; i++)
    Q += y[i];
  Q *= h;
  return(Q);
}

double Quad2(double *x, double *y, unsigned int N)
{
  double h = (x[N]-x[0])/double(N);
  double Q = y[0]+y[N];
  for (unsigned int i=1; i<=N-1; i+=2)
    Q += 4*y[i];
  for (unsigned int i=2; i<=N-2; i+=2)
    Q += 2*y[i];
  Q *= h/3.0;
  return(Q);
}


