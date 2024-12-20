
%% FiniteDifference.m
% This is a simple *script* file that implements a finite difference
% method for the problem
%      -u''(x) + b(x) u(x) = f(x) on (0,1)
%          u(0)=alpha, u(1) = beta.
% on a uniform mesh
% 04/12/17 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   GIAN Short Course on Theory and Computation of Singularly
%        Perturbed Differential Equations, 4-8 Dec 2017
% See also MATLAB_primer.pdf
clear;

%% Problem Data
alpha = 0; beta = 0;
b = @(x)(4+x*0);
f = @(x)(1+exp(x));

%% Data for numerical method
N = 10;

%% Set up the mesh
h = 1/N;
x = linspace(0, 1, N+1)';

%% Construct the Linear System
% The code below is written to be easy to understand. But it is
% *not* written to be efficient. For example, A should be preallocated,
% rather than being resize. Also, it should be a sparse matrix.
A(1,1) = 1;
B(1) = alpha;
for i=2:N
    A(i,i-1) = -1/h^2;
    A(i,i)   = 2/h^2 + b(x(i));
    A(i,i+1) = -1/h^2;
    
    B(i) = f(x(i));
end
A(N+1,N+1)=1;
B(N+1) = beta;

%% Solve the linear system
U = A\B';

%% Plot the output
plot(x, U, '-o');
