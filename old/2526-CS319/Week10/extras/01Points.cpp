// CS319 Operator Overloading: Extras
// Point: a class representing a point (in two-dimensional space)
// The purpose of this example is to demonstrate operator overloading.

#include <iostream>

class Point
{
private:
  float x,y;
public:
  Point(float i=0, float j=0) { x=i; y=j;};
  void Set(float i, float j) {x=i; y=j;};
  void Get(float &i, float &j) {i=x; j=y;};
  Point operator+(Point b);
  Point operator+(float p);

  Point operator-(Point b);
  Point operator-(void);

  Point operator++(void);
  Point operator++(int Dummy);
};

//////////////////////
// Overloading Plus
Point Point::operator+(Point b)
{
  Point temp;
  temp.x = x + b.x;
  temp.y = y + b.y;
  return temp;
}


Point Point::operator+(float p)
{
  Point temp;
  temp.x = this->x + p;
  temp.y = this->y + p;
  return temp;
}


/* Here is an alternative verion
   Point Point::operator+(float p)
   {
   Point temp(*this);
   temp.x += p;
   temp.y += p;
   return temp;
   }
*/

//////////////////////
// Overloading BINARY minus 
Point Point::operator-(Point b)
{
  Point temp;
  temp.x = x - b.x;
  temp.y = y - b.y;
  return temp;
}

// Overloading UNARY minus 
Point Point::operator-(void)
{
  Point temp;
  temp.x = -x;
  temp.y = -y;
  return(temp);
}

///////////////////////////////////
///// Overloading ++
// prefix version
Point Point::operator++(void)
{
  x++;
  y++;
  return(*this);
}

// postfix version
Point Point::operator++(int Dummy)
{
  Point temp=*this;
  x++;
  y++;
  return(temp);
}

int main(void)
{
  Point a(2,2), b, c;
  float x,y;

  a.Get(x, y);
  std::cout << "a=(" << x << ", " << y << ")" <<  std::endl;

  b.Set(2,3);
  b.Get(x, y);
  std::cout << "b=(" << x << ", " << y << ")" <<  std::endl;

  c=a+b;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;

  std::cout << "\nAdding (scalar) 1 to c..." << std::endl;
  c=c+1.0;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;

  std::cout << "Now we'll test the binary minus operator (c=a-b)" << std::endl;
  c=a-b;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;
  std::cout << "and we'll test the unary minus operator (c=-a)" << std::endl;
  c=-a;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;

  std::cout << "Prefix ++" << std::endl;
  ++c;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;

  std::cout << "Postfix ++" << std::endl;
  c++;
  c.Get(x, y);
  std::cout << "c=(" << x << ", " << y << ")" <<  std::endl;

  return(0);
}
  


  
  
  
