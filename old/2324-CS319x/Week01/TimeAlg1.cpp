// Sum the elements of a list in C++
#include <iostream>
#include <time.h>
#include <math.h>
int main() {
  int N=pow(10,6); // N=10^n
  double *A = new double [N];
  for (int i=0; i<N; i++)
    A[i]=1.0;
  clock_t start=clock();
  double s1=0;
  for (int i=0; i<N; i++)
    s1+=A[i];
  double num_clocks = (double)(clock()-start);
  double t1 = num_clocks/CLOCKS_PER_SEC;
  std::cout << "N=10^" << log10(N)
	    << ", error=" << s1-N
	    << ", time(s)" << t1 << std::endl;
  return(0);
}
 
