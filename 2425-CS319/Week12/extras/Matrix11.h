// File: Matrix11.h (version: Week 11.1)
//   What: Header file for matrix class, including overloading = and *
// Author: Niall Madden
//   Date: Week 11, 2425-CS319
// Note: Implementation for a square matrix

#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include "Vector10.h"

class Matrix {
private:
  double *entries;
  unsigned int N;
public:
  Matrix (unsigned int Size=2);
  Matrix (const Matrix &m); // Copy constructor
  ~Matrix(void);
  
  Matrix &operator=(const Matrix &B); // assignment operator
  
  unsigned int size(void) {return (N);};
  double getij (unsigned int i, unsigned int j);
  void setij (unsigned int i, unsigned int j, double x);
  
  Vector operator*(Vector u); // Define later!
  void print(void);
  void zero(void); // New for Week 11
};

#endif
