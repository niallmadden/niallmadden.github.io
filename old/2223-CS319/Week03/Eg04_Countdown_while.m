%% File  : Eg04_Countdown_while.m
%  Date  : Jan 2023 (CS319 Week 03)
%  What  : Use a while loop to count down from 10
c = 10;
while (c>0)
   fprintf("%i... ", c);
   c=c-1;
end
fprintf("Zero!\n");
