// CS319 -- Scientific Computing
// FILE: CS319-lab3-solution.cpp'
// AUTHOR: Niall Madden, School of Maths, University of Galway
// WHAT: An implementation of the bisection algorithm described in Lab 3.

#include <iostream>
#include <iomanip>
#include <math.h>

// Bisection : find where the maximum value of a function,
//  Objective(),  occurs in the interval [left,right], using an interval
//  bisection algorithm.
// INPUTS: 
// double ObjFn(double):        function to be maximised
// double left, double right:   end-points for search interval
// unsigned int &iterations:    iteration count  [Note: passed by reference
//          on exit it is the number of iterations taken]
// unsigned int MaxIterations:  another variable that does something
// OUTPUT:
//   double:     estimate of where the maximum of Objective occurs
double Bisection(double Objective(double), double left, double right, 
		 unsigned int &iterations, unsigned int MaxIterations);

// Part (d) Examples of two functions we could optimise.
double f1(double x){ return( exp(-2*x) - 2*x*x + 4*x ); }

double f2(double x){ return( sqrt(2+x) + sin(2*x) ); }

// Global variable for tolerance. For Part (a)
double TOL;

int main(void)
{
   std::cout << std::endl;
   std::cout << "-----------------------------------------" << std::endl;
   std::cout << "|        Solution for CS319 Lab 3       |" << std::endl;
   std::cout << "|         Niall Madden, Feb 2026        |" << std::endl;
   std::cout << "-----------------------------------------" << std::endl  << std::endl;

   // For Part (a)
   std::cout << "Enter the desired termination tolerance: ";
   std::cin >> TOL;

   // Example 1: find  max of f1=exp(-2*x) - 2*x*x + 4*x in [-1,3]
   std::cout << std::endl
	     << "---------------------------------------"
	     << std::endl;
   double a1=-1.0, b1=3.0, max1;
   unsigned int iteration_count1=0, MaxIterations=100; // For Parts (b)+(c)
   max1 = Bisection(f1, a1, b1, iteration_count1, MaxIterations);

   std::cout << "Example 1: f=exp(-2*x) - 2*x*x + 4*x." << std::endl;
   std::cout << "The maximum of f in [" << a1 << "," << b1 << "] is "
	     << f1(max1) << std::endl
	     << " and occurs when x=" << max1 << std::endl;
   std::cout << "Bisection() took " <<  iteration_count1
	     << " iterations." << std::endl;
   if (iteration_count1 >= MaxIterations)
   {
      std::cout << " Warning: bisection to not converge." << std::endl;
      std::cout << " Max number of iterations, "<< MaxIterations 
	   << " reached." << std::endl;
   }

   // Example 2: find  max of f2=sqrt(2+x) + sin(2*x)  in [-1,3]
   std::cout << std::endl
	     << "---------------------------------------"
	     << std::endl;
   double a2=-1.0, b2=3.0, max2;
   unsigned int iteration_count2=0; 
   max2 = Bisection(f2, a2, b2, iteration_count2, MaxIterations);

   std::cout << "Example 2: f=sqrt(2+x) + sin(2*x)." << std::endl;
   std::cout << "The maximum of f in [" << a2 << "," << b2 << "] is "
	     << f2(max2) << std::endl
	     << " and occurs when x=" << max2 << std::endl;
   std::cout << "Bisection() took " <<  iteration_count2
	     << " iterations." << std::endl;
   if (iteration_count2 >= MaxIterations)
   {
      std::cout << " Warning: bisection to not converge." << std::endl;
      std::cout << " Max number of iterations, "<< MaxIterations 
	   << " reached." << std::endl;
   }
   return(0);
}


// Bisection : find where the maximum value of a function,
//  Objective(),  occurs in the interval [left,right], using an interval
//  bisection algorithm.
// INPUTS: 
// double ObjFn(double):        function to be maximised
// double left, double right:   end-points for search interval
// unsigned int &iterations:    iteration count  [Note: passed by reference
//          on exit it is the number of iterations taken]
// unsigned int MaxIterations:  another variable that does something
// OUTPUT:
//   double:     estimate of where the maximum of Objective occurs
double Bisection(double ObjFn(double), // (d) Pass function to be optmized
		 double left, double right, 
		 unsigned int &iterations,  // (b): passed by reference
		 unsigned int MaxIterations)
{
  double a=left, b=right;
  double c = (a+b)/2.0;
  iterations=0; // For Aprt (b)
  while ( ((b-a) > TOL) &&  (iterations <= MaxIterations) )
  {
    iterations++;
    c = (a+b)/2.0;
    double l = (a+c)/2.0, r=(c+b)/2.0;
    
    if ( (ObjFn(c) > ObjFn(l)) && (ObjFn(c) > ObjFn(r)) )
    {
      a=l;
      b=r;
    }
    else if ( ObjFn(l) > ObjFn(r) )
      b=c;
    else
      a=c;
  }
  return(c);
}

