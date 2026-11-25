%%% Nonlinear.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% This script uses a finite difference to solve the problem
%%% -u''(x) + f(u) = f(x) on (0,1)
%%% u(0)=0,  u(1) = 0.
%%% on a uniform mesh

clear;

fprintf('\n  ----------  Nonlinear.m  --------- \n');

%% Problem Data
alpha = 0; beta = 0;
f = inline('1+exp(u) + u.^4');
df = inline('exp(u) + 4*u.^3');
%%

%%Data for numerical method
N = 2^5;
%%

%% Set up the mesh
h = 1/N;
x = linspace(0, 1, N+1)';
%%

%%
F = [alpha; f(x(2:N)); beta];

%% Construct the Linear System
Main_Diagonal = [1; -2*ones(N-1,1)/h^2; 1];
Sup_Diagonal  = ones(N-1,1)/h^2;
Sub_Diagonal  = ones(N-1,1)/h^2;

Delta = sparse([1:N+1, 2:N,   2:N], ...
           [1:N+1, 3:N+1, 1:N-1], ...
           [Main_Diagonal', Sup_Diagonal', Sub_Diagonal']);

%%
U = x*0;
R = Delta*U + [0; f(U(2:N)); 0];
TOL = 1e-9;
Iteration = 0;

fprintf('   N  | Iteration | Residual\n');

while( norm(R) > TOL)
	Iteration = Iteration+1;
	J = spdiags([0; df(U(2:N)); 0], 0, N+1, N+1);
	W = (Delta + J)\R;
	U = U - W;
	R = Delta*U + [0; f(U(2:N)); 0];
	
	%
	fprintf(' %4d |  %4d     | %1.2e \n', ...
		N, Iteration, norm(R));
	
	%% Plot the output
	subplot(2,1,1); plot(x, U, '-o');
	subplot(2,1,2); plot(x, R, '-o');
	pause
end
