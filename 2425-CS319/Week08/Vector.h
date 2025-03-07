// File:     Vector.h (Version W08.1)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 8 of 2425-CS319
// What:     Header file for vector class
// See also: Vector.cpp and 04TestVector.cpp 
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
