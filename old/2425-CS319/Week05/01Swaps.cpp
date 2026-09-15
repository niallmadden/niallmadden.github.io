// 01Swaps.cpp: Our first example of function overloading,
//  and pass-by-reference
// CS319 (Week 5)
// Author: Niall Madden
// Date: Feb 2025

#include <iostream>

// We have two function prototypes with same name!
void Swap(int &a, int &b);  // note use of references
void Swap(float &a, float &b);

int main(void){
    int a, b;
    float c, d;

    std::cout << "Enter two integers: ";
    std::cin >> a >> b; 
    std::cout << "Enter two floats: ";
    std::cin >> c >> d; 
    
    std::cout << "a=" << a << ", b=" << b << 
      ", c=" << c << ", d=" << d << std::endl;
    std::cout << "Swapping ...." << std::endl;

    Swap(a,b);
    Swap(c,d);

    std::cout << "a=" << a << ", b=" << b << 
      ", c=" << c << ", d=" << d << std::endl;
    return(0);
}
  
// Swap(): swap two ints
void Swap(int &a, int &b)
{
  int tmp;

  tmp=a;
  a=b;
  b=tmp;

}

// Swap(): swap two floats
void Swap(float &a, float &b)
{
  float tmp;

  tmp=a;
  a=b;
  b=tmp;
}

