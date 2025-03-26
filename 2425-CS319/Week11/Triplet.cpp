// Triplet.cpp  for 2425-CS319 Week 11
//   What: Methods for the Triplet class
// Author: Niall Madden
#include <iostream>
#include <iomanip>
#include "Vector10.h"
#include "Matrix11.h"
#include "Triplet.h"

// Standard  constructor.
Triplet::Triplet (unsigned int N, unsigned nnz_max) { 
  this->N = N;
  this->NNZ_MAX = nnz_max;
  this->NNZ = 0;

  X = new double [nnz_max];
  I = new unsigned [nnz_max];
  J = new unsigned [nnz_max];
  for (unsigned k=0; k<nnz_max; k++)  {
    I[k]=-1; 
    J[k]=-1; 
    X[k]=(double)NULL;
  }
}

// Triplet copy constructor
Triplet::Triplet (const Triplet &m)
{
  N = m.N;
  NNZ = m.NNZ;
  NNZ_MAX = m.NNZ_MAX;

  X = new double[NNZ_MAX];
  I = new unsigned [NNZ_MAX];
  J = new unsigned [NNZ_MAX];
  for (unsigned k=0; k<NNZ; k++)
    I[k] = m.I[k];
  for (unsigned k=0; k<NNZ; k++)
    J[k] = m.J[k];
  for (unsigned k=0; k<NNZ; k++)
    X[k] = m.X[k];
}

// Triplet destructor
Triplet::~Triplet(void)
{
  delete [] X;
  delete [] I;
  delete [] J;
}

// Triplet::where - locates (i,j) entry 
// returns k if A(i,j) is stored in X[k].
// returns -1 if A(i,j) is not stored.
int Triplet::where(unsigned i, unsigned j)
{
  unsigned int k=0;
  do {
    if ( (I[k]==i) && (J[k]==j) )
      return(k);
    k++;
  } while (k<NNZ);
  return(-1);
}

// Triplet::setij(i,j,x) - sets the (i,j) entry to x
void Triplet::setij (unsigned i, unsigned j, double x)
{
  if (i>N-1)
    std::cerr << "Triplet::setij(): i Index out of bounds." << std::endl;
  else if (j>N-1)
    std::cerr << "Triplet::setij(): j Index out of bounds." << std::endl;
  else if (NNZ > NNZ_MAX-1)
    std::cerr << "Triplet::setij(): Matrix full." << std::endl;
  else
  {
    int k=where(i,j);
    if (k == -1)
    {
      I[NNZ]=i;
      J[NNZ]=j;
      X[NNZ]=x;
      NNZ++;
    }
    else
      X[k]=x;
  }
}

// Triplet::getij(i,j) - returns the (i,j) entry to x
double Triplet::getij (unsigned i, unsigned j)
{
  int k=where(i,j);
  if (k == -1)
  {
    //std::cerr << "Warning Triplet::getij(): no such entry." << std::endl;
    return(0);
  }
  else if ( (i>N) || (j>N) )
  {
    std::cerr << "Triplet::getij(): Index out of bounds." << std::endl;
    return(0);
  }
  else
    return( X[k] );
}

void Triplet::print (void)
{
  for (unsigned k=0; k<NNZ; k++)
  {
    std::cout << "[" << std::setw(2) << I[k] << "]";
    std::cout << "[" << std::setw(2) << J[k] << "]";
    std::cout << "[" << std::setw(5) << X[k] << "]"  << std::endl;
  }
}

// Overload the assignment = operator. 
Triplet &Triplet::operator=(const Triplet &B)
{
  if (this == &B)
    return(*this); // Taking care for self-assignment

  N = B.N;
  NNZ = B.NNZ;
  NNZ_MAX = B.NNZ_MAX;

// Just in case there was any memory already allocated to this
  delete [] X; 
  delete [] I; 
  delete [] J; 

  X = new double[B.NNZ_MAX];
  I = new unsigned [B.NNZ_MAX];
  J = new unsigned [B.NNZ_MAX];

  for (unsigned k=0; k<NNZ; k++)
    I[k] = B.I[k];
  for (unsigned k=0; k<NNZ; k++)
    J[k] = B.J[k];
  for (unsigned k=0; k<NNZ; k++)
    X[k] = B.X[k];

  return(*this);      
}

Triplet full2Triplet(Matrix &F, unsigned NNZ_MAX)
{
  unsigned N = F.size();

  Triplet T(N, NNZ_MAX);

  double x;
  T.NNZ=0;
  for (unsigned i=0; i<N; i++)
    for (unsigned j=0; j<N; j++)
    {
      x = F.getij(i,j);
      if (x != 0)
      {
	if (T.NNZ >=NNZ_MAX)
	  std::cerr << "full2Triplet:: Matrix is full!\n" << std::endl;
	else
	{
	  T.I[T.NNZ] = i;
	  T.J[T.NNZ] = j;
	  T.X[T.NNZ] = x;
	  T.NNZ++;
	}
      }
    }
  return(T);      
}

// Overload the operator* (multiplication)operator for a 
// Triplet-Vector product.
// Triplet is passed implicitly as "this", the Vector
// is  passed explicitly. Will return v=(this)*u
Vector Triplet::operator*(Vector u)
{
  Vector v(N); // v = A*u, where A is the implicitly passed Triplet
  v.zero();
  if (N != u.size())
    std::cerr << "Error: Triplet::operator* - dimension mismatch" 
	      << std::endl;
  else
    for (unsigned k=0; k<NNZ; k++)
      v.seti(I[k], v.geti(I[k]) + X[k]*u.geti(J[k]));
  return(v);
}

 
