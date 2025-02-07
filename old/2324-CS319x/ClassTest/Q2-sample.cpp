// Solution to Q2 from 2324-Cs319 Sample Class Test
#include <iostream>
#include <cstdlib> 

bool IsSorted(int x[], int n);

int main(void)  
{
  int a[5];
  for (int i=0; i<5; i++)
  {
    a[i] = rand()%(i*100+1);
    std::cout << "a["<< i << "]="
	      << a[i] << std::endl;
  }
  
  std::cout << "List a is sorted? " <<
    std::boolalpha << IsSorted(a, 5) <<
    std::endl;
  return(0);
}

bool IsSorted(int x[], int n)
{
  for (int i=0; i<n-1;i++)
    if (x[i+1]<x[i])
      return(false);
  return(true); 
}
