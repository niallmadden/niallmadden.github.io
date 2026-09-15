%%% Nonlinear.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% This script uses a finite difference to solve the
%%% parabolic boundary value problem
%%% u_t(x,t) -u_xx(x,t) + r(x) u(x,t) = f(x,t) 
%%%  on (0,1)x(0,T]
%%% subject to the initial condition u(x,0)=0;
%%% and boundary conditions u(0,t)=u(1,t) = 0; 
%%% on a uniform mesh

clear;

fprintf('\n  ----------  Parabolic.m  --------- \n');

%% Problem Data
f = inline('1+x+tau.^2');
r = inline('sqrt(1+x)');
%%

%%Data for numerical method
N = 2^4;  % Number of points in space
M = 2^5;  % Number of points in time
T  = 1;
%%

%% Set up the mesh
h = 1/N;
x = linspace(0, 1, N+1)';
tau = T/M;
[X,Y] = meshgrid(x, linspace(0,1,M+1));
%%

U = zeros(M+1, N+1);
U(1,:)=0;

%% Construct the Linear System
Main_Diagonal = [-1; -2*ones(N-1,1)/h^2; -1];
Sup_Diagonal  = ones(N-1,1)/h^2;
Sub_Diagonal  = ones(N-1,1)/h^2;

Delta = sparse([1:N+1, 2:N,   2:N], ...
           [1:N+1, 3:N+1, 1:N-1], ...
           [Main_Diagonal', Sup_Diagonal', Sub_Diagonal']);

A = -tau*Delta + spdiags([0; tau+r(x(2:N)); 0], 0, N+1, N+1);


for j=2:M
	F = [0; tau*f(x(2:N),tau) + U(j-1,2:N)'; 0];
	U(j,:) = A\F;
	
	mesh(X,Y,U);
	pause(1e-1)
end
