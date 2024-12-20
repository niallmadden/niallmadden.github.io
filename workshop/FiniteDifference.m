%%% FiniteDifference.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% This is a simple *script* file that implements a finite difference
%%% method for the problem
%%% -u''(x) + r(x) u(x) = f(x) on (0,1)
%%% u(0)=alpha, u(1) = beta.
%%% on a uniform mesh

clear;


%% Problem Data
alpha = 0; beta = 0;
r = inline('4+x*0');
f = inline('1+exp(x)');
%%

%%Data for numerical method
N = 10;
%%

%% Set up the mesh
h = 1/N;
x = linspace(0, 1, N+1)';
%%

%% Construct the Linear System
A(1,1) = 1;
F(1) = alpha;
for k=2:N
    A(k,k-1) = -1/h^2;
    A(k,k)   = 2/h^2 + r(x(k));
    A(k,k+1) = -1/h^2;
    
    F(k) = f(x(k));
end
A(N+1,N+1)=1;
F(N+1) = beta;

%% Solve the linear system
U = A\F';

%% Plot the output
plot(x, U, '-o');
