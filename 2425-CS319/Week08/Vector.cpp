// File:     Vector.cpp (Version W08.1)
// Author:   Niall Madden  <Niall.Madden@UniversityOfGalway.ie>
// Date:     Week 8 of 2425-CS319
// What:     Header file for Vector class
// See also: Vector.h and 04TestVector.cpp 

#include <iostream>
#include <math.h>

#include "Vector.h"

Vector::Vector(unsigned int Size)
{
  N = Size; 
  entries = new double[Size];
}

Vector::~Vector()
{
  delete [] entries;
}

void Vector::seti(unsigned int i, double x)
{
  if (i<N)
    entries[i]=x;
  else
    std::cerr << "Vector::seti(): Index out of bounds."
	      << std::endl;
}

double Vector::geti(unsigned int i)
{
  if (i<N)
    return(entries[i]);
  else {
    std::cerr << "Vector::geti(): Index out of bounds."
	      << std::endl;
    return(0);
  }
}

void Vector::print(void)
{
  for (unsigned int i=0; i<N; i++)
    std::cout << "[" << entries[i] << "]" << std::endl;
}

double Vector::norm(void)
{
  double x=0;
  for (unsigned int i=0; i<N; i++)
    x+=entries[i]*entries[i];
  return (sqrt(x));
}

void Vector::zero(void)
{
  for (unsigned int i=0; i<N; i++)
    entries[i]=0;
}
