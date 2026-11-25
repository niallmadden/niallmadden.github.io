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

fprintf('\n  ----------  TestRates.m  --------- \n');

fprintf('%5s  | %8s  | %5s    | %5s\n', 'N', 'Error', 'C', 'Rate');

for k = 2:10
	%% Set up the mesh
	N = 2^k;
	h = 1/N;
	x = linspace(0, 1, N+1)';

	%% Call the solver
	U = Solve_BVP(r, f, alpha, beta, x);

	Error(k) = max(abs(U - u(x)));
	C(k) = Error(k)*N^2;
    if (k>2)
		Rate(k) = log2( Error(k-1)/Error(k));
		fprintf(' %5d | %9.3e | %7.2e | %5.2f \n', ...
			N, Error(k), C(k), Rate(k));
	else
		fprintf(' %5d | %9.3e | %7.2e | \n', N, Error(k), C(k));
	end
end