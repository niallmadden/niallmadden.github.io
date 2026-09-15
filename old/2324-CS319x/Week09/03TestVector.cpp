// File:     01TestVector.cpp
// Author:   Niall Madden (NUI Galway) Niall.Madden@NUIGalway.ie
// Date:     Week 7 of 2021-CS319
// What:     First example of computing with vectors.
// See also: http://www.maths.nuigalway.ie/~niall/CS319/Week07

#include <iostream>
#include <stdlib.h>
#include "Vector.h"

//  c=alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (Vector &c, Vector &a, Vector &b, 
	     double alpha=1.0, double beta=1.0);

int main(void )
{
  unsigned int N=3;
   
  Vector u(N), v(N), w(N);
  
  for (unsigned int i=0; i<N; i++)
  {
    u.seti(i, (double)i);
    v.seti(i, (double)(rand()%10));
  }

  std::cout << "u=" << std::endl;
  u.print();
  std::cout << "||u||=" << u.norm() << std::endl;

  std::cout << std::endl << "v=" << std::endl;
  v.print();
  std::cout << "||v||=" << v.norm() << std::endl;

  VecAdd(w, u,v,1,-1);
  std::cout << std::endl << "w=" << std::endl;
  w.print();
  std::cout << "||w||=" << w.norm() << std::endl;

  return (0);
}

//  alpha*a + beta*b where a,b are vectors; alpha, beta are scalars
void VecAdd (Vector &c, Vector &a, Vector &b, double alpha, double beta)
{
  unsigned int N;
  N = a.size();

  if ( (N != b.size()) )
    std::cerr << "dimension mismatch in VecAdd " << std::endl;
  else
  {
    for (unsigned int i=0; i<N; i++)
      c.seti(i, alpha*a.geti(i)+beta*b.geti(i) );
  }
}
