// 01Manipulators.cpp
// Using manipulators from iomanip

#include <iostream>
#include <string>
#include <iomanip>
int main()
{
  int i, fib[16];
  fib[0]=1; fib[1]=1;

  std::cout << "Without setw  manipulator" << std::endl;
  for (i=0; i<=12; i++)
  {
    if( i >= 2)
      fib[i] = fib[i-1] + fib[i-2];
    std::cout << "The " << i << "th " << 
      "Fibonacci Number is " <<  fib[i] << std::endl;
  }

  std::cout << "With the setw  manipulator" << std::endl;
  for (i=0; i<=12; i++)
  {
    if( i >= 2)
      fib[i] = fib[i-1] + fib[i-2];
    std::cout
      << "The " << std::setw(2) << i << "th " 
      << "Fibonacci Number is "
      << std::setw(3) <<  fib[i] << std::endl;
  }

  return(0);
}

