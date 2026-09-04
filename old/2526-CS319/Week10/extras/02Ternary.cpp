// CS319 Operator Overloading: Extras
// An example of how to use C++'s only ternary operator
#include <iostream>
#include <string>

int main(void)
{
  int Score;
  std::string Grade, Outcome;

  std::cout << "Enter your score: ";
  std::cin >> Score;

  (Score >= 40) ? Grade="Pass" : Grade="Fail";
  std::cout << "You have " << Grade << "ed." << std::endl;

  // Alternative 
  std::cout << "Enter another score: ";
  std::cin >> Score;
  Outcome = (Score >= 40) ? "will not" : "will";
  std::cout << "You " << Outcome << " have to come back in Augest!"
	    << std::endl;

  return(0);
}
