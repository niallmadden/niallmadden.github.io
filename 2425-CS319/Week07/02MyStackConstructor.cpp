/* 02MyStackConstructor.cpp
   What: Final version of the stack class, which has 
        two constructors, and a destructor.
Author: Niall Madden
  When: Feb 2025
  More: https://www.niallmadden.ie/2425-CS319/#Week07
*/

#include <iostream>

#define MAX_STACK 10

class MyStack {
private:
  char *contents;
  int top, maxsize; 
public:
  MyStack (void);  // default constructor
  MyStack (unsigned int StackSize);
  ~MyStack ();    // destructor
  void push(char c);
  char pop(void );
};

MyStack::MyStack(void)
{
  top=0;
  contents = new char[MAX_STACK];
  maxsize = MAX_STACK;
}

MyStack::MyStack(unsigned int StackSize)
{
  top=0;
  maxsize = StackSize;
  contents = new char[StackSize];
}

MyStack::~MyStack()
{
  delete [] contents;
}


void MyStack::push(char c)
{
  contents[top]=c;
  top++;
}

char MyStack::pop(void)
{
  top--;
  return(contents[top]);
}  


int main(void )
{
  MyStack s1(6);

  std::cout << "Pushing CS319" << std::endl;
  s1.push('C');
  s1.push('S');
  s1.push('3');
  s1.push('1');
  s1.push('9');

  std::cout << "Popping ... " << std::endl;

  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;
   
  return (0);
}

