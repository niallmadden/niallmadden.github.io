// CS319:  how **not** to write a swap function
// Author: Niall Madden
// Date: Feb 2024
#include <iostream>
void Swap(int a, int b);

int main(void )
{
  int a, b;

  std::cout << "Enter two integers: ";
  std::cin >> a >> b; 

  std::cout << "Before Swap: a=" << a << ", b=" << b
	    << std::endl;
  Swap(a,b);
  std::cout << "After Swap: a=" << a << ", b=" << b
	    << std::endl;

  return(0);
}

// Function: SWAP
// Arguments: two integers, a and b 
// return value: void
// Does: tries to swap that values stored in a and b.
void Swap(int a, int b)
{
  int tmp;

  tmp=a;
  a=b;
  b=tmp;
}

