function U = Central_Diff_BVP(epsilon, q, r, f, alpha, beta, x)
%%% Solve_BVP.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% This simple Matlab function that implements a finite difference
%%% method for the problem
%%% -epsilon u''(x) + q(x)u'(x) + r(x) u(x) = f(x) on (0,1)
%%% u(0)=alpha, u(1) = beta.
%%% on a uniform mesh
%%% Using central differences to discretize u'(x)

N = length(x)-1;
h = 1/N;

%%
F = [alpha; f(x(2:N)); beta];

%% Construct the Linear System
Main_Diagonal = [1; 2*epsilon/h^2+r(x(2:N)); 1];
Sup_Diagonal  = -epsilon*ones(N-1,1)/h^2 + q(x(2:N))/(2*h);
Sub_Diagonal  = -epsilon*ones(N-1,1)/h^2 - q(x(2:N))/(2*h);

A = sparse([1:N+1, 2:N,   2:N], ...
           [1:N+1, 3:N+1, 1:N-1], ...
           [Main_Diagonal', Sup_Diagonal', Sub_Diagonal']);



%% Solve the linear system
U = A\F;

