%% FiniteDifference.m
% Date: 16/06/2015
% Author: Niall Madden, School of Maths, NUI Galway
%
% This is a simple *script* file that implements a finite difference
% method for the problem
%      -u''(x) + r(x) u(x) = f(x) on (0,1)
%          u(0)=alpha, u(1) = beta.
% on a uniform mesh

clear;

%% Problem Data
alpha = 0; beta = 0;
r = @(x)(4+x*0);
f = @(x)(1+exp(x));

%%Data for numerical method
N = 10;

%% Set up the mesh
h = 1/N;
x = linspace(0, 1, N+1)';

%% Construct the Linear System
A(1,1) = 1;
b(1) = alpha;
for i=2:N
    A(i,i-1) = -1/h^2;
    A(i,i)   = 2/h^2 + r(x(i));
    A(i,i+1) = -1/h^2;
    
    b(i) = f(x(i));
end
A(N+1,N+1)=1;
b(N+1) = beta;

%% Solve the linear system
u = A\b';

%% Plot the output
plot(x, u, '-o');
