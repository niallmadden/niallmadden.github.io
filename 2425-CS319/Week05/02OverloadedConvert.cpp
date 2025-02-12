// 03OverloadConvert.cpp
// CS319:  An example of how **not** to overload
//   Note: this code will not, and should not, compile.
// Author: Niall Madden
// Date: Feb 2025

#include <iostream>

typedef float EUR;
typedef float GBP;

const float EUR_to_GBP=0.75008; // Correct as of 21/01/14

// The following won't work because date types EUR  and GBP
// are really the same.
EUR Convert(GBP x) { return(x/EUR_to_GBP); }
GBP Convert(EUR x) { return(x*EUR_to_GBP); }

int main(void )
{
  EUR k;

  std::cout << "Enter a Euro amount: ";
  std::cin >> k;

  std::cout << "€" << k << " = £" << k*EUR_to_GBP << std::endl;

  return(0);
    
}
 
