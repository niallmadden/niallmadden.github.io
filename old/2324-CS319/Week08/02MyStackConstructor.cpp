/* 02MyStackConstructor.cpp
  What: Improvement upon the initial version of the stack class. 
        This one uses constructors (but not a destructor).
Author: Niall Madden
  When: Feb 2024
  More: https://www.niallmadden.ie/2324-CS319/#Week08
*/

#include <iostream>

#define MAX_STACK 10

class MyStack {
private:
  char *contents;
  int top, maxsize; 
public:
  MyStack (void);
  MyStack (unsigned int StackSize);
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

