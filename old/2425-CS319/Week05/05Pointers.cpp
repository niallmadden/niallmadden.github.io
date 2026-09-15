// 05Pointers.cpp
//   What: An example of how pointers work
// Author: Niall Madden
//   Date: Feb 2025

#include <iostream>

int main(void )
{
  int a=-3, b=12;
  int *where;

  std::cout << "The variable 'a' stores " << a << std::endl;
  std::cout << "The variable 'b' stores " << b << std::endl;
  std::cout << "'a' is stored at address " << &a << std::endl;
  std::cout << "'b' is stored at address " << &b << std::endl;

  where = &a;
  std::cout << "The variable 'where' stores "
	    << (void *) where << std::endl;
  std::cout << "... and that in turn stores " <<
    *where << '\n';
 
  return (0);
}

 
