%%% TestRates1.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% Test the rate of convergece of our finite difference method

clear;

%% Problem Data
alpha = 0; beta = 0;
r = inline('1+x*0');
f = inline('1+x');
u = inline('1 + x - (exp(-x)*exp(1)*(exp(1)-2) + exp(x)*(2*exp(1)-1))/(exp(2)-1)');

%%

%%Data for numerical method

fprintf('%5s  |  %8s  | %5s \n', 'N', 'Error', 'C');

for N = 2.^(2:10)
	%% Set up the mesh
	h = 1/N;
	x = linspace(0, 1, N+1)';

	%% Call the solver
	U = Solve_BVP(r, f, alpha, beta, x);

	Error = max(abs(U - u(x)));
	C = Error*N^2;
   %% Plot the output and error
   subplot(1,2,1); plot(x, U, '-o');
   subplot(1,2,2); plot(x, abs(U-u(x)), '-o');
   
   fprintf(' %5d | %10.3e | %7.2e \n', N, Error, C);
   pause
end