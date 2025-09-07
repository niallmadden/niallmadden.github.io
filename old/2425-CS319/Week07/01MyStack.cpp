// 01MyStack.cpp
// What:  Our first class: an implementation of MyStack (Version 1.0).
// Who:   Niall Madden
// When:  Week 7 (CS319 - Scientific Computing)
// More:  See https://www.niallmadden.ie/2425-CS319

#include <iostream>

#define MAX_STACK 10

// Class definition of MyStack 
class MyStack {
private:
  char contents[MAX_STACK]; 
  int top;
public:
  void init(void );
  void push(char c);
  char pop(void );
};

void MyStack::init(void) {
  top=0;
}

void MyStack::push(char c) {
  contents[top]=c;
  top++;
}

char MyStack::pop(void) {
  top--;
  return(contents[top]);
}  

int main(void ) {
  MyStack s;
  
  s.init();   
   
  s.push('C');
  s.push('S');
  s.push('3');
  s.push('1');
  s.push('9');

  std::cout << "Popping ... " << std::endl;

  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
   
  return (0);
}

