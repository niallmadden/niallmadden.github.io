/* File  : 05CountDown.cpp 
   Author: Niall Madden
   Date  : 24/01/2024
   For   : CS319, Week 3
   What  : A very basic example of using a for-loop */

#include <iostream>

int main(void)
{
  int i;

  for (i=10; i>=1; i--)
    std::cout << i << "... ";

  std::cout << "Zero!\n";

  return(0);
}
