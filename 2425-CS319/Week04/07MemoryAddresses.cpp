// Compare memory addresses

#include <iostream>

void Address(int i);

int main(void)
{
  int i=12;
  std::cout << "main: Value stored in i: " << i << '\n';
  std::cout << "main: address of i: " << &i << '\n';
  Address(i);
  std::cout << "main: Value stored in i: " << i << '\n';
  std::cout << "main: address of i: " << &i << '\n';
  return(0);
}

void Address(int i)
{
  std::cout << "Address: Value stored in i: " << i << '\n';
  std::cout << "Address: address of i: " << &i << '\n';
  i+=10; // Change value of i
  std::cout << "Address: New val stored in i: " << i << '\n';
  std::cout << "Address: address of i: " << &i << '\n';
}  
  
