// Solution to Q3 on sample test
#include <iostream>

int MyNchooseK(int n, int k);

int main(void)  
{
  int n, k, c;

  std::cout << "Enter n and k" <<std::endl;
  std::cin >> n >> k;

  c = MyNchooseK(n,k);
  
  std::cout << n << " choose " << k << " = "
	    << c << std::endl;
  return(0);
}


int MyNchooseK(int n, int k)
{
  if ( (n < k) || (n<0) || (k<0) )
    return(0);
  else if ( (k==0) || (k==n))
    return(1);
  else
    return( MyNchooseK(n-1,k-1) +
	    MyNchooseK(n-1,k));
}

