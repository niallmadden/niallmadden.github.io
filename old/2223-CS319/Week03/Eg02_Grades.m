%% Eg02_Grades.m 
%   Date  : Jan 2023
%   What  : Example of using if-elseif-else
NumberGrade = input("Please enter the grade (percent): ");
if ( NumberGrade >= 70 )
   LetterGrade = 'A';
elseif ( NumberGrade >= 60 )
   LetterGrade = 'B';
elseif ( NumberGrade >= 50 )
   LetterGrade = 'C';
elseif ( NumberGrade >= 40 )
   LetterGrade = 'D';
else
   LetterGrade = 'E';
end
fprintf("%2d%% corresponds to a %c grade\n", ...
   NumberGrade, LetterGrade);

