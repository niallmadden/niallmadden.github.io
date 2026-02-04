/* FILE  : Lab2-Q1.cpp   
   Author: Niall Madden (Email: Niall.Madden@UniversityOfGalway.ie)
   Date  : Feb 2026
   What  : eps mach for floats
*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath> // for pow
#include <limits> // to check the value

int main(void)
{
   std::cout << std::endl <<
     "---------------------------------\n" << 
     "|   CS319  Lab 2, Q1,  Feb 2025   |\n" <<
     "|       Investigate floats  \n" <<
     "---------------------------------\n";

   // Machine epsilon for floats
   float epsilon=1.0;
   float f=1.0,  g = f+epsilon;
   
   int n=0;
   clock_t start=clock();
   while ( g > 1.0  )
   {
     n++;
     epsilon/=2.0;
     g = f+epsilon;
     // std::cout << "eps=" << epsilon << std::endl;
   }
   float diff = (float)(clock()-start);
   float diff_seconds = diff/CLOCKS_PER_SEC;
   std::cout << std::setprecision(16);
   std::cout << "(float) eps_mach:\t " << epsilon*2 << std::endl;
   std::cout << "Value from <limits>:\t "
	     << std::numeric_limits<float>::epsilon() << std::endl;
   std::cout << std::setprecision(4);
   std::cout << "That took " << n << " iterations, so eps_mach is 2^"
	     << (-n) << "=" << pow(2,-n);
   std::cout << " (Computation took " << diff_seconds
        << "s)."  << std::endl;
   return(0);
}
