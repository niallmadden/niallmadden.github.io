// Triplet.h:  For 2425-CS319 Week 11
// Author: Niall Madden

#ifndef _TRIPLET_H_INCLUDED
#define _TRIPLET_H_INCLUDED

#include "Vector10.h"
#include "Matrix11.h"

class Triplet {
  friend Triplet full2Triplet(Matrix &F, unsigned int NNZ_MAX);
private:
  unsigned int *I, *J;
  double *X;
  unsigned int N;
  unsigned int NNZ;
  unsigned int NNZ_MAX;

public:
  Triplet (unsigned int N, unsigned int nnz_max); // Constructor
  Triplet (const Triplet &t); // Copy constructor
  ~Triplet(void);

  Triplet &operator=(const Triplet &B); // overload assignment 

  unsigned int size(void) {return (N);};
  int where(unsigned int i, unsigned int j); // negative return on error
  unsigned int nnz(void) {return (NNZ);};
  unsigned int nnz_max(void) {return (NNZ_MAX);};

  double getij (unsigned int i, unsigned int j);
  void setij (unsigned int i, unsigned int j, double x);

  unsigned int getI (unsigned int k) { return I[k];};
  unsigned int getJ (unsigned int k) { return J[k];};
  double getX (unsigned int k) { return X[k];};

  Vector operator*(Vector u);
  void print(void);
};
#endif
