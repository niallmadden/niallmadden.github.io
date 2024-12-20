// 05Input.cpp
// Demonstrating use of "cin" for input.
// Week 2: CS319 - Scientific Computing

#include <iostream>
#include <iomanip> // needed for setprecision
int main()
{
  const double StirlingToEuro=1.16541; // Correct 17/01/2024
  double Stirling;
  std::cout << "Input amount in Stirling: ";
  std::cin >> Stirling;
  std::cout << "That is worth "
	    << Stirling*StirlingToEuro << " Euros\n";
  std::cout << "That is worth " << std::fixed
	    << std::setprecision(2) << "\u20AC"
	    << Stirling*StirlingToEuro << std::endl;
  return(0);
}
 
