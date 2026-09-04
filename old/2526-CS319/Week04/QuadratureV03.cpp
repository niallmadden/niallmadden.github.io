// QuadratureV03.cpp: Trapezium Rule as a function
// that takes a function as argument
// Week 04: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()
#include <iomanip>  

double f(double x) {  return(exp(x)); } // definition
double g(double x) {  return(6*x*x); } // definition

double TrapRule(double Fn(double), double a, double b,
		int N);
		
int main(void )
{
  std::cout << "Using the TR to integrate in 1D\n";
  std::cout << "Integrate between x=0 and x=1.\n";
  double a=0.0, b=1.0;

  std::cout << "Which shall we integrate: \n"
	    << "\t 1. f(x)=exp(x) \n\t 2. g(x)=6*x^2?\n";
  int choice;
  std::cin >> choice;
  while (!(choice == 1 || choice  == 2) )
  {
    std::cout << "You entered " << choice
	      <<". Please enter 1 or 2: ";
    std::cin >> choice;
  }
  double Int_TR=-1; // good place-holder
  if (choice == 1)
    Int_TR = TrapRule(f,a,b,10);
  else
    Int_TR = TrapRule(g,a,b,10);
  
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


