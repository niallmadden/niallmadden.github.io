// 03Rounding.cpp
// Check for rounding error for numbers with
//  exact and inexact binary representations.
// Week 2: CS319 - Scientific Computing

#include <iostream>
int main()
{
   int i, max;
   float x, increment;

   std::cout << "Enter a (natural) number, n: ";
   std::cin >> max;
   x=0.0;
   increment = 1/( (float) max);

   for (i=0; i<max; i++)
      x+=increment;

   std::cout << "Difference between x and 1 is " << x-1
	     << std::endl;

   return(0);
}
 
