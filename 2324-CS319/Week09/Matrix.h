// File:     Matrix.h (W09.1)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 9 of 2324-CS319
// What:     Implementation of "Matrix": a class of square matrices
// See also: Matrix.cpp and 04TestMatrix.cpp 

class Matrix {
private:
  double *entries;
  unsigned int N;
public:
  Matrix (unsigned int Size=2);
  ~Matrix(void) { delete [] entries; };

  unsigned int size(void) {return (N);};
  double getij (unsigned int i, unsigned int j);
  void setij (unsigned int i, unsigned int j, double x);

  void print(void);
};

