// File:     Vector10.cpp (Version W10.1)
// Author:   Niall Madden
// Date:     Week 10 of 2324-CS319
// What:     Header file for Vector class
// See also: Vector10.h

#include <iostream>
#include <iomanip>    // New for Week 9
#include <math.h>
#include "Vector10.h"

// default constructor
// Note: the version from Week09, which did not use the "this" pointer
Vector::Vector (unsigned int N)
{
  this->N = N; 
  entries = new double[N]; 
}

// copy constructor 
Vector::Vector (const Vector &old_Vector)
{
  N = old_Vector.N;
  entries = new double[N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = old_Vector.entries[i]; 
}

Vector::~Vector () {
  delete [] entries;
}

void Vector::seti (unsigned int i, double x)
{
  if (i<N)
    entries[i]=x;
  else
    std::cerr << "Vector::seti(): Index out of bounds."
	      << std::endl;
}

double Vector::geti (unsigned int i)
{
  if (i<N)
    return(entries[i]);
  else {
    std::cerr << "Vector::geti(): Index out of bounds."
	      << std::endl;
    return(0);
  }
}

void Vector::print (void)
{
  for (unsigned int i=0; i<N; i++)
    std::cout << "[" << entries[i] << "]" << std::endl;
}

double Vector::norm (void)
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

////////////////////////////////////////////////////////
// Everything above this is, except the copy constructor, 
//     is from Week 9.
// Everything below this is from Week 10 
////////////////////////////////////////////////////////

// Overload the = operator. 
Vector &Vector::operator=(const Vector &b)
{
  if (this == &b)
    return(*this); // Taking care for self-assignment
  
  delete [] entries; // In case memory was already allocated

  N = b.N;
  entries = new double[b.N];
  for (unsigned int i=0; i<N; i++)
    entries[i] = b.entries[i];
      
  return(*this);      
}

// Overload the + operator. 
Vector Vector::operator+(Vector b)
{
  Vector c(N); // Make c the size of a
  if (N != b.N)
    std::cerr << "vector::+ : cant add two vectors of different size!"
	      << std::endl;
  else
    for (unsigned int i=0; i<N; i++)
      c.entries[i] = entries[i] + b.entries[i];
  return(c);      
}

// Overload the unary minus (-) operator. As in b=-a;
Vector Vector::operator-(void)
{
  Vector b(N); // Make b the size of a
  for (unsigned int i=0; i<N; i++)
    b.entries[i] = -entries[i];
  return(b);      
}

// Overload the binary minus (-) operator. As in c=a-b
// This implementation reuses the unary minus (-) operator
Vector Vector::operator-(Vector b)
{
  Vector c(N); // Make b the size of a
  if (N != b.N)
    std::cerr << "Vector:: operator- : dimension mismatch!"
	      << std::endl;
  else
    c = *this + (-b);
  return(c);      
}

std::ostream &operator<<(std::ostream &output, Vector &v)
{
  output << "[";
  std::cout.precision(5);
  for (unsigned int i=0; i<v.size()-1; i++)
    output << std::setw(10) << v.entries[i] << ",";
  output << std::setw(10) <<
    v.entries[v.size()-1] << "]";

  return(output);
}

