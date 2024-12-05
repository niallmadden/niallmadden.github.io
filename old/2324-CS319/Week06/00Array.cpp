// 00Array.cpp
//   What: An example of how an array works
// Author: Niall Madden
//   Date: Feb 2024

#include <iostream>

int main(void )
{
  float vals[3];
  vals[0]=1.1;  vals[1]=2.2;  vals[2]=3.3;
  for (int i=0; i<3; i++)
    std::cout << "  vals["<<i<<"]=" << vals[i];
  std:: cout << std::endl;
  std::cout << "vals=" << vals << '\n';
  return (0);
}

 
