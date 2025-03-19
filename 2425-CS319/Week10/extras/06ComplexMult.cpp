// CS319 Operator Overloading: Extras
// Complex: a class representing complex numbers
// Shows three ways of overloading the * operator

#include <iostream>
#include <cmath>

class Complex 
{
  friend Complex operator*(float f, Complex z); // float*complex must be friend
  friend std::ostream &operator<<(std::ostream &output, const Complex &b);
private:
  float real, imag;
public:
  Complex (float r=0.0, float i=1.0) {Set(r,i);};
  float GetReal(void) const {return(real);};
  float GetImag(void) const {return(imag);};
  void Set(float r, float i=0.0);
  Complex operator*(Complex b); // complex*complex OK to overload as member!
  Complex operator*(float f); // complex*float OK to overload as member!
};

std::ostream &operator<<(std::ostream &output, const Complex &b)
{
  output << b.real << " + " << b.imag << "i";
  return(output);
}

// Complex*Complex: (a+bi)(c+di)=(ac-bd) + (ad+bc)i
Complex Complex::operator*(Complex y)
{
  Complex tmp;
  tmp.real = real*(y.real) - imag*(y.imag);
  tmp.imag = real*(y.imag) + imag*(y.real);
  return(tmp);
}

// Complex*float: (a+bi)*y= ay + (by)i
Complex Complex::operator*(float y)
{
  Complex tmp;
  tmp.real = real*y;
  tmp.imag = imag*y;
  return(tmp);
}

// float*Complex f*(a+bi)= af + (bf)i
Complex operator*(float f, Complex z)
{
  Complex tmp;
  tmp.Set(f*(z.real), f*(z.imag));
  return(tmp);
}


void Complex::Set(float r, float i)
{
  real=r; imag=i;
}


int main(void)
{
  Complex x(2.0, 3.0), z;
  const Complex I(0,1);
  float f=-2.0;

  std::cout << "I=" << I << std::endl;
  std::cout << "x=" << x << std::endl;

  // Complex*Complex
  z=x*I;
  std::cout << "x*I=" << z << std::endl;

  // Complex*float
  z = x*3.0;
  std::cout << "x*3=" << z << std::endl;

  // float*Complex
  z = f*x;
  std::cout << "3*x=" << z << std::endl;

  return(0);
}
