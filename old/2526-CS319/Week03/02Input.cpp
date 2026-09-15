// 02Input.cpp
// Demonstrating use of "cin" for input.

#include <iostream>
#include <iomanip> // needed for setprecision
int main()
{
  const double StirlingToEuro=1.19099; // Correct 28/01/2026
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
 
