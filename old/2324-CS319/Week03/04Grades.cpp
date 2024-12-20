/* File  : 04Grades.cpp 
   Author: Niall Madden (Niall.Madden@UniversityOfGalway.ie)
   Date  : 24/01/2024
   For   : CS319, Week 03
   What  : A slightly more advanced use of if-else
   Notes : This could also  be written using switch/case */

#include <iostream>

int main(void)
{
   int NumberGrade;
   char LetterGrade;
   
   std::cout << "Please enter the grade (percentage): ";
   std::cin >> NumberGrade;
   if ( NumberGrade >= 70 )
      LetterGrade = 'A';
   else if ( NumberGrade >= 60 )
      LetterGrade = 'B';
   else if ( NumberGrade >= 50 )
      LetterGrade = 'C';
   else if ( NumberGrade >= 40 )
      LetterGrade = 'D';
   else 
      LetterGrade = 'E';

   std::cout << "A score of " << NumberGrade
	     << "% cooresponds to a "
	     << LetterGrade << "." << std::endl;
  return(0);
}
