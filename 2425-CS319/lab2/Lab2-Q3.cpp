/* FILE  : Lab2-Q3.cpp   
   Author: Niall Madden (Email: Niall.Madden@UniversityOfGalway.ie)
   Date  : Feb 2025 
   What  : Numerical differentiation
*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath> // for pow
#include <limits> // to check the value

float f(float x) {return(exp(-x));}

int main(void)
{
   std::cout << std::endl <<
     "---------------------------------\n" << 
     "|   CS319  Lab 2, Q3,  Feb 2025   |\n" <<
     "|   Numerical Differentiation     |\n" <<
     "---------------------------------\n";

   float df0_true = -1.0, df0_approx2, df0_approx3;
   float x0=0.0, h=1.0e-1;
   df0_approx2 = (f(x0+h)-f(x0))/h; // two point
   df0_approx3 = (f(x0+h)-f(x0-h))/(2*h); // three point

   std::cout << std::setprecision(6);
   std::cout << "Derivative (true):\t " << df0_true << std::endl;
   std::cout << "Derivative (2-point):\t " << df0_approx2;
   std::cout << "\tError:\t " << fabs(df0_true-df0_approx2) << std::endl;
   std::cout << "Derivative (3-point):\t " <<  df0_approx3;
   std::cout << "\tError:\t " << fabs(df0_true-df0_approx3) << std::endl;

   return(0);
}
