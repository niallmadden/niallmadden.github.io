// Use prefix and postfix ++
#include <iostream>
int main(void)
{
   int a, b;

   a=10; b=20;
// The following would be illegal
//   (a++)=b;
   (++a)=b; // <-  But this is OK!
   std::cout << "a=" << a << ", b=" << b << std::endl;
   return(0);
}
