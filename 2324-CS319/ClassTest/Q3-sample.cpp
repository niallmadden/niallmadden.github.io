// Solution to Q3 from 2324-CS319 Sample Class Test
#include <iostream>

int main(void)  
{
  double C, F;

  for (C=-40; C<=40; C+=8.0)
  {
    F = (9.0/5.0)*C + 32.0;
    std::cout << "C = " << C <<
      " corresponds to F=" <<
      F << std::endl;
  }  
  return(0);
}
