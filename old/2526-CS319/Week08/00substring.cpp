/* CS319 : strings as objects */
#include <iostream>
#include <string>

int main(void)
{
  std::string
    sentence="Ada Lovelace was the first programmer",
    first_word;
  int space_loc = sentence.find(" ");    // Find first space
  first_word = sentence.substr(0,space_loc); // extract substring
  
  std::cout << "sentence is: " << sentence << std::endl;
  std::cout << "first word is: '" << first_word << "'\n";
  return(0);
}
