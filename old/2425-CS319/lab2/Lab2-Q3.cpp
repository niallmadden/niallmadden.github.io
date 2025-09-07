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

float f(float x) {return(exp(-x));} // function to differentiate

int main(void)
{
   std::cout << std::endl <<
     " ---------------------------------\n" << 
     "|  CS319  Lab 2, Q3,  Feb 2025    |\n" <<
     "|  Numerical Differentiation      |\n" <<
     "|  This version by: Niall Madden  |\n" <<
     " ---------------------------------\n";

   double x0 = 1.0; // point to differentiate at
   double Df_true = -exp(-x0), Df_approx;
   std::cout << std::fixed << std::showpoint;
   std::cout << std::setprecision(8);
   std::cout << "\t True:\t " << Df_true << std::endl;
   std::cout << "     h     |   2-point   |   Error "<< std::endl;

   float h=pow(2.0,-2);
   Df_approx = (f(x0+h)-f(x0))/h; // two point
   double error = fabs(Df_true-Df_approx);
   std::cout << h << " | " << std::setw(11) << Df_approx << " | "
	       << error << std::endl;
}
