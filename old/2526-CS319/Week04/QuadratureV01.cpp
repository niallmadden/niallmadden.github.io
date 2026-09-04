// QuadratureV01.cpp:
// Trapezium Rule (TR) quadrature for a 1D function
// Author: Niall Madden
// Date: Feb 2026
// Week 04: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()

double f(double); // prototype 
double f(double x) {  return(exp(x)); } // definition

int main(void )
{
  std::cout << "Using the TR to integrate f(x)=exp(x)\n";
  std::cout << "Integrate f(x) between x=0 and x=1.\n";
  double a=0.0, b=1.0;
  double Int_f_true = exp(1)-1;
  std::cout << "Enter value of N for the Trap Rule: ";
  int N;
  std::cin >> N; // Lazy! Should do input checking.

  double h=(b-a)/double(N);
  double Int_f_TR = (h/2.0)*f(a);
  for (int i=1; i<N; i++)
    Int_f_TR += h*f(a+i*h);
  Int_f_TR += (h/2.0)*f(b);

  double error = fabs(Int_f_true - Int_f_TR);
  
  std::cout << "N=" << N << ", Trap Rule=" << Int_f_TR
	    << ", error=" << error << std::endl;
  return(0);
}


