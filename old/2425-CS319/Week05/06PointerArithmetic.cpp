// 06PointerArrithmetic.cpp

#include <iostream>

int main(void )
{
  int vals[3];
  vals[0]=10;  vals[1]=8;  vals[2]=-4;

  int *p;
  p = vals;
  
  for (int i=0; i<3; i++)
  {
    std::cout << "p=" << p << ", *p=" << *p << "\n";
    p++;
  }
  return (0);
}

