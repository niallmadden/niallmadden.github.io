// 00Array.cpp
//   What: An example of how an array works
// Author: Niall Madden
//   Date: Feb 2026

#include <iostream>

int main(void )
{
  float vals[]={1.1, 2.2, 3.3};

  for (int i=0; i<3; i++)
    std::cout << "  vals[" << i << "]=" << vals[i];
  std:: cout << std::endl;
  std::cout << "vals=" << vals << '\n';
  return (0);
}

 
