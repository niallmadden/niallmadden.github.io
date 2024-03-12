// File:     01TestVectorOperators.cpp
// Author:   Niall Madden 
// Date:     Week 10 of 2324-CS319
// What:     Test some of the operators we overload for Vector
// See also: http://www.maths.nuigalway.ie/~niall/CS319/Week07

#include <iostream>
#include <stdlib.h>
#include "Vector10.h"

int main(void )
{
  unsigned int N=3;
   
  Vector u(N), v(N), w(N);
  
  for (unsigned int i=0; i<N; i++)
  {
    u.seti(i, (double)i);
    v.seti(i, (double)(rand()%10));
  }

  std::cout << "u=" << u << std::endl;
  std::cout << "||u||=" << u.norm() << std::endl;

  std::cout << std::endl << "v=" << v << std::endl;
  std::cout << "||v||=" << v.norm() << std::endl;

  w = u-v;
  std::cout << std::endl << "u-v=" << w << std::endl;
  std::cout << "||w||=" << w.norm() << std::endl;

  return (0);
}

