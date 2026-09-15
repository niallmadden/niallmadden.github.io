// 01TimeCode.cpp
// An example of timing code
// Compare declaring an array with, and without,
// initialisation

#include <iostream>
#include <ctime>
int main()
{
  // Timing without initialising the array
  int Runs=10000, // number of runs to time
    ArraySize=1000000;
  clock_t start = clock();    // start stop-watch 
  for (int i=0; i<Runs; i++)
    double arr[ArraySize+i];    // declare the array (no init)
  double seconds = double(clock() - start)/CLOCKS_PER_SEC;
  std::cout << "Ave Time (no init): " << seconds/Runs << "s\n";

  // Timing with initialising the array
  start = clock();    // restart stop-watch 
  for (int i=0; i<Runs; i++)
    double arr[ArraySize+i]={};    // declare the array (with init)
  seconds = double(clock() - start)/CLOCKS_PER_SEC;
  std::cout << "Ave Time ( init ): " << seconds/Runs << "s\n";

  return 0;
}
