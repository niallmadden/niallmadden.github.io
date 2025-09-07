// File:     VectorBasic.h (simple version)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 9 of 2425-CS319
// What:     Header file for vector class
// See also: VectorBasic.cpp and 01TestVector.cpp 
class Vector {
private:
  double *entries;
  unsigned int N;
public:
  Vector(unsigned int Size=2);
  ~Vector(void);

  unsigned int size(void) {return N;};
  double geti(unsigned int i);
  void seti(unsigned int i, double x);

  void print(void);
  double norm(void); // Compute the 2-norm of a vector
  void zero(void); // Set entries of vector to zero.
};
