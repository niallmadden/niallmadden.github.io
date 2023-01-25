%% Eg01_EvenOdd.m 
%   Author: Niall Madden
%   Date  : Jan 2023
%   For   : CS319, Week 3 
%   What  : A simple example of using if-else

Number = input("Please enter an integrer: ");
if ( mod(Number,2) == 0)
   fprintf("%d is an even number.\n",  Number);
else
   fprintf("%d is an odd number.\n",  Number);
end
