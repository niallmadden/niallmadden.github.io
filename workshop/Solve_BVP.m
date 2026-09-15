function U = Solve_BVP(r, f, alpha, beta, x)
%%% Solve_BVP.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% This is a simple Matlab function that implements a finite difference
%%% method for the problem
%%% -u''(x) + r(x) u(x) = f(x) on (0,1)
%%% u(0)=alpha, u(1) = beta.
%%% on a uniform mesh


N = length(x)-1;
h = 1/N;

%%
F = [alpha; f(x(2:N)); beta];

%% Construct the Linear System
Main_Diagonal = [1; 2/h^2+r(x(2:N)); 1];
Sup_Diagonal  = -ones(N-1,1)/h^2;
Sub_Diagonal  = -ones(N-1,1)/h^2;

A = sparse([1:N+1, 2:N,   2:N], ...
           [1:N+1, 3:N+1, 1:N-1], ...
           [Main_Diagonal', Sup_Diagonal', Sub_Diagonal']);



%% Solve the linear system
U = A\F;

%% Plot the output
plot(x, U, '-o');
