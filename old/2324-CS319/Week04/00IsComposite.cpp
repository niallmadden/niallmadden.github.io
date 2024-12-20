// 00IsComposite.cpp
// An example of a simple function.
// Author: Niall Madden
// Date: 31 Jan 2024
// Week 4: CS319 - Scientific Computing

#include <iostream>

bool IsComposite(int i);

int main(void )
{
  int i;

  std::cout << "Enter a natural number: ";
  std::cin >> i;

  std::cout << i << " is a " <<
    (IsComposite(i) ? "composite":"prime") << " number."
	    << std::endl;
  
  return(0);
}

// Check if i as a Composite number (i.e., not prime)
// Return "true" if it is composite.
// Return "prime" if it is prime.
bool IsComposite(int i)
{
  int k;
  for (k=2; k<i; k++)
    if ( (i%k) == 0)
      return(true);

  return(false); // If we get to  here, i has no divisors between 2 and i-1
}



