// File:   02set_and_multiset.cpp for 2425-CS319 Week 11
// Author: Niall Madden
// What:   Compare the use of set and multiset
// For more information see
//    https://www.niallmadden.ie/2425-CS319/#Week11
#include <iostream>
#include <iomanip>
#include <set>       // set and multiset

int main(void )
{
  std::set <int> set_int;
  std::set <int>::iterator set_int_i;
  std::multiset <int> multi_int;
  std::multiset <int>::iterator multi_int_i;

  for (int i=0; i<=20; i+=3) // (0,3,6,9,12,15,18) 
  {
    set_int.insert(i);  
    multi_int.insert(i);
  }
  for (int i=20; i>0; i-=2) // (20,18,16,...,4,2) 
  {
    set_int.insert(i);
    multi_int.insert(i);
  }

  std::cout << "The multiset has " << multi_int.size() <<
    " items." << std::endl;
  std::cout << "\t They are: ";
  for (multi_int_i = multi_int.begin();
       multi_int_i != multi_int.end();
       multi_int_i++)
    std::cout << std::setw(3) << *multi_int_i;
  std::cout << std::endl;
  std::cout << "\t 6 occurs " << multi_int.count(6) <<
    " time(s)." << std::endl;

  std::cout << "The set has " << set_int.size() <<
    " items." << std::endl;
  std::cout << "\t They are: ";
  for (set_int_i = set_int.begin();
       set_int_i != set_int.end();
       set_int_i++)
    std::cout << std::setw(3) << *set_int_i;
  std::cout << std::endl << "\t 6 occurs " << set_int.count(6)
	    << " time(s)." << std::endl;

  return(0);
}
