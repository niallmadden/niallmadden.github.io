%% Euler.m
% A MATLAB/Octave script file that implements Euler's method to
% numerically solve 
%    y(t0)=y0,  y'(t)=f(t,y)
% on the interval [t0, tN]
% WRITTEN BY: Niall Madden, NUI Galway. Niall.Madden@NUIGalway.ie
% DATE:     24 October 2019
% FOR:      MA385/MA530, Lab 2.
% See also: http://www.maths.nuigalway.ie/MA385/

clear;  % clear any old  variables

f = @(t,y)(y./(1 + t.^2));
y = @(t)(exp(atan(t)));

fprintf('\n--------------------------\n');
fprintf(' ----  Eulers Method  ----\n');
fprintf(' ----  MA385 - Lab 2  ----\n');

t0=0; % initial time
y0=1; % Initial value: y(t0)=y0
T=4;  % final time

n = 2; % <--- This is the number of points used.
h = (T-t0)/n;  % h=t_k-t_{k-1}

t=t0:h:T;    % time steps

Y(1)=y0;

%% The method:
for i=1:n
    Y(i+1) = Y(i) + h*f(t(i), Y(i));
end

%% Compute and display errors
Error = abs(Y(n+1) - y(T));
fprintf('n=%d \n', n); 
fprintf('y(n)=%f\n',  Y(n+1));
fprintf('Error=%e\n', Error);
     
plot(t,y(t), t,Y, '--o');
title(n);
legend('True Solution','Eulers Method');
