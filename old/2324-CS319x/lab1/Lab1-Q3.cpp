/* FILE  : Lab1-Q3.cpp   
   Author: Niall Madden
   Date  : Week 3, Semester 2, 2023/2024
   For   : CS319, Lab 1
   What  :  Find the largest integer correctly representable, 
            and time how long it takes.
   Warning: Don't use optimization, or long ints */

#include <iostream>
#include <time.h>

int main(void)
{
   std::cout << std::endl <<
     "---------------------------------\n" << 
     "| CS319  Lab 1, Q3(a),  Jan 2024 |\n" <<
     "---------------------------------\n";
   clock_t start;
   float diff, diff_seconds;
   start=clock();
   
   int i=1;
   int j=i+1; 
   while ( i<j )
   {
      i++;
      j=i+1;
   }
   diff = (float)(clock()-start);
   diff_seconds = diff/CLOCKS_PER_SEC;
   std::cout << "Overflow at i="<< i << std::endl;
   std::cout << "Computation took " << diff_seconds
        << " seconds."  << std::endl;
   return(0);
}
