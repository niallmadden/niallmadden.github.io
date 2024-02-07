// CS319 - Week 5. Jan 2024
// 04Sort.cpp: Our second example of function overloading
// See your notes from class for a detailed discussion

#include <iostream>
#include <stdlib.h> // contains rand() header

const int N=8;

void Sort(int &a, int &b);
void Sort(int list[], int length);
void PrintList(int x[], int n);

int main(void )
{
    int i, x[N];

    for (i=0; i<N; i++)
      x[i]=rand()%40;
    
    std::cout << "The list is:\t\t";
    PrintList(x, N);
    std::cout << "Sorting..." << std::endl;

    Sort(x,N);

    std::cout << "The sorted list is:\t";
    PrintList(x, N);
    return(0);
}
  
// Arguments: two integers 
// return value: void
// Does: Sorts a and b so that a<=b.
void Sort(int &a, int &b)
{
  if (a>b)
  {
    int tmp;
    tmp=a;     a=b;    b=tmp;
  }
}

// Arguments: an integer array and its length
// return value: void
// Does: Sorts the 1st n elements of x
void Sort(int x[], int n)
{
  int i, k;
  for (i=n-1; i>1; i--)
    for (k=0; k<i; k++)
      Sort(x[k], x[k+1]);

}

void PrintList(int x[], int n)
{
  for (int i=0; i<n; i++)
    std::cout << x[i] << "  ";
  std::cout << std::endl;
}
