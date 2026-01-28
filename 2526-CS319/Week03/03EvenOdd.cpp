/* FILE  : 03EvenOdd.cpp 
   Author: Niall Madden
   Date  : Jan 2026
   For   : CS319, Week 3
   What  : A simple example of using if-else  
   Notes : also, show off a C-style comment  
*/

#include <iostream>

int main(void)
{
  int Number;

  std::cout << "Please enter an integrer: ";
  std::cin >> Number;
  
  if ( (Number%2) == 0)
    std::cout <<  "That is an even number." << std::endl;
  else
    std::cout <<  "That number is odd." << std::endl;
  return(0);
}
