%%% First Script file for Matlab Workshop
%%% 03/04/2007

clear %% Get rid of all declared variables.

N = 4
x = linspace(0,1,N+1)';
f = x + sqrt(x) -1;

plot(x, f, '-o');