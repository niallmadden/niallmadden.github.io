%% CS319: Lab 1, Q2 (see Eg01_MyIntMax.m from Week 2)
% Who: Niall Madden
% What: Checks the largest integer of type int18
% When: Jan 2023
clear; % clear any previously defined variables
fprintf('\n---------------------------\n');
fprintf('CS319, Lab 1, Q3 \n');

tic; % Start the clock
a=int8(0); % Set a to zero in int8 
b=a+1;
while( b>a )
   a=a+1;
   b=a+1;
end
fprintf('Largest int8=%d\n', a);
TimeTaken = toc; % Seconds since "tic"
fprintf('Computional took %f seconds.\n', TimeTaken);
