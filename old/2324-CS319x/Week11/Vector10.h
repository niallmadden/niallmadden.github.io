// File:     Vector10.h (Version W10.1)
// Author:   Niall Madden 
// Date:     Week 10 of 2324-CS319
// What:     Header file for Vector class
// See also: Vector10.cpp

#include <iostream>   // New for Week 9 for overloading <<

// In case this header files included multiple times.
#ifndef _VECTOR_H_INCLUDED
#define _VECTOR_H_INCLUDED

class Vector {
  friend std::ostream &operator<<(std::ostream &, Vector &v);
private:
  double *entries;
  unsigned int N;
public:
  Vector (unsigned int Size=2);
  Vector (const Vector &v); // Arg must be passed by value. Why?
  ~Vector(void);

  Vector &operator=(const Vector &b); // overload assignment operator
  
  unsigned int size(void) {return N;};
  double geti (unsigned int i);
  void seti (unsigned int i, double x);
  
  Vector operator+(Vector b);
  Vector operator-(Vector b); // binary
  Vector operator-(void); // unary
   
  void print(void);
  double norm(void); // Compute the 2-norm of a Vector
  void zero(void); // Set entries of Vector to zero.
};

#endif
