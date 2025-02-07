// Triplet.h:  For 2324-CS319 Week 11
// Author: Niall Madden

#ifndef _TRIPLET_H_INCLUDED
#define _TRIPLET_H_INCLUDED

#include "Vector10.h"
#include "Matrix11.h"

class Triplet {
  friend Triplet full2Triplet(Matrix &F, unsigned NNZ_MAX);
private:
  unsigned *I, *J;
  double *X;
  unsigned N;
  unsigned NNZ;
  unsigned NNZ_MAX;

public:
  Triplet (unsigned N, unsigned nnz_max); // Constructor
  Triplet (const Triplet &t); // Copy constructor
  ~Triplet(void);

  Triplet &operator=(const Triplet &B); // overload assignment 

  unsigned size(void) {return (N);};
  int where(unsigned i, unsigned j); // negative return on error
  unsigned nnz(void) {return (NNZ);};
  unsigned nnz_max(void) {return (NNZ_MAX);};

  double getij (unsigned i, unsigned j);
  void setij (unsigned i, unsigned j, double x);

  unsigned getI (unsigned k) { return I[k];};
  unsigned getJ (unsigned k) { return J[k];};
  double getX (unsigned k) { return X[k];};

  Vector operator*(Vector u);
  void print(void);
};
#endif
