// File:   03STL_vector.cpp  for 2324-CS319 Week 11
// Author: Niall Madden.
// What:   An example of using the STL vector
// For more information see
//     https://www.niallmadden.ie/2324-CS319/#Week11

#include <iostream>
#include <iomanip>

#include <vector>       // vector
#include <algorithm>    // sort
void print_int (int i) { std::cout << std::setw(3) << i; }
int main(void )
{
  std::vector <int> vec_int;
  std::vector <int>::iterator vec_int_i;
  std::cout << "Vector has " << vec_int.size() << 
    " elements." << std::endl ;

  for (int i=3; i>=0; i--) 
    vec_int.push_back(i*3); // (9,6,3,0) 

  std::cout << "Vector has " << vec_int.size() << " elements: ";
  for (unsigned int i=0; i<vec_int.size(); i++)
    std::cout << std::setw(3) << vec_int[i];
   
  vec_int_i = find (vec_int.begin(),vec_int.end(),3);
  vec_int.insert(vec_int_i,10);

  std::cout << std::endl;
  std::cout << "Vector has " << vec_int.size() << " elements: ";
  for_each (vec_int.begin(), vec_int.end(), print_int);

  std::cout << std::endl; 
  std::cout << "Sorting the vector..." << std::endl;
  sort(vec_int.begin(), vec_int.end());
  std::cout << "Now vector is: ";
  for_each (vec_int.begin(), vec_int.end(), print_int);

// We can also do this with a range-based for loop.
// Need to enable c++11 option
//   std::cout << std::endl << "Again, the vector is: ";
//   for (int i : vec_int)
//      print_int(i);

  std::cout << std::endl;
  return(0);
}
