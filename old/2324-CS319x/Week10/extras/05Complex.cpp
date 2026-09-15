// CS319 Operator Overloading: Extras
// A very basic implementation of a Complex number class

#include <iostream>

class Complex 
{
private:
  float real, imag;
public:
  Complex (float r=0.0, float i=0.0) {Set(r,i);};
  float GetReal(void) {return(real);};
  float GetImag(void) {return(imag);};
  void Set(float r, float i=0.0);
};

void Complex::Set(float r, float i)
{
  real=r; imag=i;
}


int main(void)
{
  Complex x(2, 1/2.);
  std::cout << "x=" << x.GetReal() << "+" << x.GetImag() << "i" << std::endl;
  return(0);
}
