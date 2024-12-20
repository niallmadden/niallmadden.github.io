// 01Pointers.cpp
//   What: An example of how pointers work
// Author: Niall Madden
//   Date: Feb 2024

#include <iostream>

int main(void )
{
  int a=-3, b=12;
  int *where;

  std::cout << "The variable 'a' stores " << a <<
    '\n' << "The variable 'b' stores " << b << '\n';
  std::cout << "'a' is stored at address " << &a <<
    '\n' "'b' is stored at address " << &b << '\n';

  where = &a;
  std::cout << "The variable 'where' stores "
	    << (void *) where << std::endl;
  std::cout << "... and that in turn stores " <<
    *where << '\n';
 
  return (0);
}

 
