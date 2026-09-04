/* Stub for "IsSorted.cpp": you must write the code for the
function 
   bool IsSorted(int x[], int n)
that checks if the array stored in x is sorted or now.

In addition, you need to use a for-loop to initialise 
and output the entires in the array a[]

Part of a class test for CS319.
*/

#include <iostream>
#include <cstdlib> //needed for the rand() function

bool IsSorted(int x[], int n);

int main(void)  
{
  int a[5];

  a[0] = rand()%1;
  a[1] = rand()%101;
  a[2] = rand()%201;
  a[3] = rand()%301;
  a[4] = rand()%401;
  
  std::cout << "a[0]=" << a[0] << std::endl;
  std::cout << "a[1]=" << a[1] << std::endl;
  std::cout << "a[2]=" << a[2] << std::endl;
  std::cout << "a[3]=" << a[3] << std::endl;
  std::cout << "a[4]=" << a[4] << std::endl;
  std::cout << "List a is sorted? " <<
    std::boolalpha << IsSorted(a, 5) << std::endl;
  
  return(0);
  
}


bool IsSorted(int x[], int n)
{
  // YOU MUST WRITE THE CODE THAT DOES HERE
  return(true); // JUST A PLACE-HOLDER!
}
