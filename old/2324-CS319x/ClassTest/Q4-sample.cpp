// Solution to Q4 from 2324-CS319 Sample Class Test
#include <iostream>
#include <cstdlib> 

bool IsLeapYear(int year);

int main(void)  
{
  int years[]={1572, 1900, 2000, 2023, 2024};
  std::cout << "--Testing IsLeapYear()--\n";
  for (int i=0; i<=4; i++)
    if (IsLeapYear(years[i]))
      std::cout << years[i] <<
	" is a leap year\n";
    else
      std::cout << years[i] <<
	" is not a leap year\n";
  return(0);
}

// Note: could use nested is statements to make this
// code clearer.
bool IsLeapYear(int year)
{
  if (year > 1582 &&
      ( (year%400)==0 ||
	((year%4)==0) &&
	((year%100)!=0) ) )
    return(true);
  else
    return(false);
}
	
