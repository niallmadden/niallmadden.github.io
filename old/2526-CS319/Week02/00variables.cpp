// CS319 - Scientific Computing
// 00variables.cpp
// Check the size of some standard variables.

#include <iostream>
#include <math.h> // need this for pow

using namespace std;
int main()
{
   cout << "sizeof(char) = " << sizeof(char) << endl;
   cout << "sizeof(int) = " << sizeof(int) << endl;
   cout << "sizeof(long int) = " << sizeof(long int) << endl;
   cout << "sizeof(short int) = " << sizeof(short int) << endl;
   cout << "sizeof(float) = " << sizeof(float) << endl;
   cout << "sizeof(double) = " << sizeof(double) << endl;
   cout << "sizeof(bool) = " << sizeof(bool) << endl;

   cout << endl;

   int i;
   int a;
   for (i=0; i<32; i++)
   {
     a = pow(2,i);
     cout << "a = 2^" << i << " = " << a << endl;
   }
   return(0);
}
 
