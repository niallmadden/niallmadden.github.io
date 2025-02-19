// Solution to Q2 on sample test
#include <iostream>
#include <cstdlib> //needed for the rand() function

int CountOccurences(int list[], int len, int k);

int main(void)  
{
  // Part (b) START
  int a[10]; 
  for (int i=0; i<10; i++)
  {
    a[i] = rand()%11;
    std::cout << "a["<<i<<"]=" << a[i] << std::endl;
  }

  std::cout << "The following entries are unique:";
  for (int i=0; i<10; i++)
    if (CountOccurences(a, 10, i) == 1)
      std::cout << i << " ";
  std::cout << std::endl;
  return(0);
}

// Function for Part (a)
int CountOccurences(int list[], int n, int k)
{
  int c=0;
  for (int i=0; i<n; i++)
    if (list[i]==k)
      c++;
  return(c);
}
