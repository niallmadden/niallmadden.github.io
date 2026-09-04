// 07IsComposite.cpp
// An example of a simple function, to check if an int is composite 
// Author: Niall Madden
// Week 3: 2526-CS319 - Scientific Computing

#include <iostream>

bool IsComposite(int i);

int main(void )
{
  int i;

  std::cout << "Enter a natural number: ";
  std::cin >> i; // Warning: should check this is positive

  std::cout << i << " is a " <<
    (IsComposite(i) ? "composite":"prime") << " number."
	    << std::endl;
  
  return(0);
}

// Check if i as a Composite number (i.e., not prime)
// Return "true" if it is composite.
// Return "false" if it is prime.
bool IsComposite(int i) // should check $i>0$
{
  int k;
  for (k=2; k<i; k++)
    if ( (i%k) == 0)
      return(true);

  // If we get to here, then i has no divisors between 2 and i-1
  return(false);
}



