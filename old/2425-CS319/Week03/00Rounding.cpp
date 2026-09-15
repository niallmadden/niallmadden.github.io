// 00Rounding.cpp
// Check for rounding error for numbers with
//  exact and inexact binary representations.

#include <iostream>
int main()
{
   int i, n;
   float x=0.0, increment;

   std::cout << "Enter a (natural) number, n: ";
   std::cin >> n;
   increment = 1/( (float) n);

   for (i=0; i<n; i++)
      x+=increment;

   std::cout << "Difference between x and 1: " << x-1
	     << std::endl;

   return(0);
}
 
