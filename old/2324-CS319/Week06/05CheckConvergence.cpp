// 05CheckConvergence.cpp
// Check the convergence of the Traezium Rule,
// while also demo'ing memory allocation and de-allocation
// Week 06: CS319 - Scientific Computing
#include <iostream>
#include <cmath>  // For exp()
#include <iomanip>  
#include <string>

double f(double x) {  return(exp(x)); } // definition
double ans_true = exp(1.0)-1.0; // true value of integral

double Quad1(double *x, double *y, unsigned int N);		

void print_nparray(unsigned *x, int n, std::string str);
void print_nparray(double *x, int n, std::string str);

int main(void )
{
  unsigned K = 8;  // number of cases to check
  unsigned Ns[K];   // Number of intervals
  double Errors[K];
  double a=0.0, b=1.0; // limits of integration
  double *x, *y; // quadrature points and values.

  for (unsigned k=0; k<K; k++)
  {
    unsigned N = pow(2,k+2);
    Ns[k] = N;
    x = new double[N+1];
    y = new double[N+1];
    double h = (b-a)/double(N);
    for (unsigned int i=0; i<=N; i++)
    {
      x[i] = a+i*h;
      y[i] = f(x[i]);
    }
    double Est1 = Quad1(x,y,N);
    Errors[k] = fabs(ans_true - Est1);
    delete [] x; delete [] y;
  }

  print_nparray(Ns, K, "N");
  print_nparray(Errors, K, "T");
  return(0);
}

double Quad1(double *x, double *y, unsigned N)
{
  double h = (x[N]-x[0])/double(N);
  double Q = 0.5*(y[0]+y[N]);
  for (unsigned int i=1; i<N; i++)
    Q += y[i];
  Q *= h;
  return(Q);
}

void print_nparray(unsigned *x, int n, std::string str)
{
  std::cout << str << "=np.array([";
  std::cout << x[0];
  for (int i=1; i<n; i++)
    std::cout << ", " << x[i];
  std::cout << "])" << std::endl;
}

void print_nparray(double *x, int n, std::string str)
{
  std::cout << str << "=np.array([";
  std::cout << std::scientific << std::setprecision(6);
  std::cout << x[0];
  for (int i=1; i<n; i++)
    std::cout << ", " << x[i];
  std::cout << "])" << std::endl;
}
