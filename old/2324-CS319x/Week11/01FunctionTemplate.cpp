// File:   01FunctionTemplate.cpp
// Author: Niall Madden 
// Date:   March 2024 (Week 11 of 2324-CS319)
// Using a function template to define a Sort() function that can be 
//   used to sort arrays of, well, anything.
// See also 04Sort.cpp from Week 5
//    https://www.niallmadden.ie/2324-CS319/#Week05

#include <iostream>
#include <stdlib.h> // contains rand() header
#include <iomanip>

template <typename MyType>
void PrintList(MyType *x, unsigned int n);

template <typename MyType>
void Sort(MyType &a, MyType &b);
 
template <typename MyType>
void Sort(MyType *list, unsigned int length);

int main(void ) 
{
  int Numbers[8];
  char Letters[8];
  
  for (int i=0; i<8; i++)      
    Numbers[i]=rand()%40;
  
  for (int i=0; i<8; i++)      
    Letters[i]='A'+rand()%26;
  
  std::cout << "Before sorting:" << std::endl;
  std::cout << "Numbers: ";  PrintList(Numbers, 8);
  std::cout << "Letters: ";  PrintList(Letters, 8);
  
  Sort(Numbers, 8);
  Sort(Letters, 8);
  
  std::cout << "After sorting: " << std::endl;
  std::cout << "Numbers: ";  PrintList(Numbers, 8);
  std::cout << "Letters: ";  PrintList(Letters, 8);

  return(0);
}

// function Sort()  
// Arguments: references to two MyType variables a and b [to be sorted]
// Return value: void
// Does: Sorts a and b so that a<=b.
template <typename MyType>
void Sort(MyType &a, MyType &b) {
  if (a>b)
  {
    MyType tmp=a;
    a=b;
    b=tmp;
  }
}

// Function Sort()
// Arguments: (generic) MyType array x [data to be sorted] 
//             unsigned int n [length of array]
// return value: void
// Does: Sorts the first n elements of x
template <typename MyType>
void Sort(MyType *x, unsigned int n) {
  for (int i=n-1; i>1; i--)
    for (int k=0; k<i; k++)
      Sort(x[k], x[k+1]);
}

// Function PrintList()
// Arguments: (generic) MyType array x [data to displayed] 
//             unsigned int n [length of array]
// return value: void
// Does: Sends first n elements of x to std::cout
template <typename MyType>
void PrintList(MyType *x, unsigned int n)
{
  for (unsigned int i=0; i<n; i++)
    std::cout << std::setw(4) << x[i] << "  ";
  std::cout << std::endl;
}


