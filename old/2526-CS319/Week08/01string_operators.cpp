/* CS319 : strings operators */
#include <iostream>
#include <string>

int main(void)
{
  std::string name[3], // array of names
    long_name="";
  name[0]="Augusta";
  name[1]="Ada";
  name[2]="King";

  long_name = name[0] + " " + name[1] + " " + name[2];
  
  std::cout << "long_name: " << long_name << std::endl;
  return(0);
}
