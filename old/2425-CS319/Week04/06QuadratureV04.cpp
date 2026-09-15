// 06QuadrateureV04.cpp: Trapezium Rule as a function
// Show how to set default values
// Week 04: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()
#include <iomanip>  

double f(double x) {  return(exp(x)); } // definition

double TrapRule(double Fn(double), double a,
		double b, int N=10); // default N=10
		
int main(void )
{
  std::cout << "Using the TR to integrate in 1D\n";
  std::cout << "Integrate between x=0 and x=1.\n";
  double a=0.0, b=1.0;

  std::cout << "We shall integrate: f(x)=exp(x)\n";
  double Int_TR = TrapRule(f,a,b); // Notice - N not specified
  std::cout << "N=10" << ", Trap Rule="
	    << std::setprecision(6) << Int_TR  << std::endl;
  return(0);
}

double TrapRule(double Fn(double), double a,
		double b, int N)
{
  double h=(b-a)/double(N);
  double QFn = (h/2.0)*Fn(a);
  for (int i=1; i<N; i++)
    QFn += h*Fn(a+i*h);
  QFn += (h/2.0)*Fn(b);

  return(QFn);
}


