// CS319 -- Scientific Computing
// A very basic implementation of a bisection algorithm.
// This is loosely based on Shapira "Solving PDEs in C++", Section 1.20
// Author: Niall Madden
// Date: March 2021
// For more, see:  See http://www.maths.nuigalway.ie/~niall/CS319/lab2/

#include <iostream>
#include <iomanip>
#include <math.h>

double Bisection(double left, double right);
double f(double);

int main()
{
  double a=-1.0, b=3.0, c;
  
  c = Bisection(a,b);
  
  std::cout << "The maximum of the function between "
	    << a << " and " << b << " is at "
	    << std::setprecision(10) << c << std::endl;
  
  return(0);
}


// The objective function
double f(double x)
{
  return( exp(-2*x) - 2*x*x + 4*x );
}

// FUNCTION: Bisection
// ARGUMENTS: (double) a and (double) b
// RETURNS: (double) c, the point where the function f,
//    defined above, achieves its max.
double Bisection(double a, double b)
{
  double c = (a+b)/2.0;
  while ( (b-a) > 1e-6)
  {
    c = (a+b)/2.0;
    double l = (a+c)/2.0, r=(c+b)/2.0;
	
    if ( (f(c) > f(l)) && (f(c) > f(r)) )
    {
      a=l;
      b=r;
    }
    else if ( f(l) > f(r) )
      b=c;
    else
      a=c;
  }
  return(c);
}
