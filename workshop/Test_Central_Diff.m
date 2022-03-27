%%% TestRates2.m
%%% Date: 03/04/07
%%% Author: Niall Madden, Dep of Mathematics, NUI Galway
%%%
%%% Test the rate of convergece of our finite difference method
%%% by comparing the solution with a method on a much finer mesh.

clear;

%% Problem Data
alpha = 0; beta = 0;
epsilon = 1;
q = inline('1 + x');
r = inline('sqrt(1 + x + sin(x))');
f = inline('1+x.^x');

%%
N_Best = 2^16;
x_Best = linspace(0, 1, N_Best+1)';
U_Best = Central_Diff_BVP(epsilon, q, r, f, alpha, beta, x_Best);

%%Data for numerical method

fprintf('\n  ----------  TestRates2.m  --------- \n');

fprintf('%5s  | %8s  | %5s    | %5s\n', 'N', 'Error', 'C', 'Rate');

for k = 2:10
	%% Set up the mesh
	N = 2^k;
	h = 1/N;
	x = linspace(0, 1, N+1)';

	%% Call the solver
	U = Central_Diff_BVP(epsilon, q, r, f, alpha, beta, x);

	Error(k) = max(abs(U - interp1(x_Best, U_Best, x)));
	C(k) = Error(k)*N^2;
    if (k>2)
		Rate(k) = log2( Error(k-1)/Error(k));
		fprintf(' %5d | %9.3e | %7.2e | %5.2f \n', ...
			N, Error(k), C(k), Rate(k));
	else
		fprintf(' %5d | %9.3e | %7.2e | \n', N, Error(k), C(k));
	end
	plot(x, U, '-o');
	pause;
end