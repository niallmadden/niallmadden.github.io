%% Test_1DRD.m
%     Tests a simple finite difference solver for a 1D
%     singularly perturbed reaction-diffusion problem
%            -epsilon^2 u'' + b(x)u = f(x) on (0,1)
%                     and u=0 at boundary
% The scheme is a standard, second-order central finite difference scheme,
% on a piecewise uniform mesh with N subinterval.
% The user should specify
%  * the functions b and f. Defaults are b(x)=1 and f(x)=exp(x)
%  * the range of epsilon. Default is [1, 1e-1, 1e-2, ... 1e-8]
%  * the range of N. Default is [32, 64, ..., 1024]
% Errors are calculated using the exact solution.
% 15/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Solve_1DRD u_true
fprintf('\n\n--------------------------------------\n');
fprintf('   Solving a singularly perturbed     \n');
fprintf('     reaction-diffusion problem       \n');
fprintf('              in 1D                 \n');

clear;

ShowFigures=true; % Set to 'true' if you wany to see graph of the 
                   % solution and error.
%% Problem data
Epsilons=10.^(-6); % Will try epsilon=1e-0, 1e-2,...,1e-6;
b = @(x)(1 + x*0);
beta = 0.99; % A lower bound for b
f = @(x)(exp(x));
u = @u_true; % The true solution. Used the estimate the error.

%% Discretization data
Ns = 2.^(5:10); % Values of N we will try.
MeshType='Shishkin';  % Choose one of Uniform or Shishkin.
sigma = 2; % Formal order of the scheme. Used to make the mesh. 

Errors = nan( length(Epsilons), length(Ns) );

fprintf('%6s   ', 'N');
for n=Ns
    fprintf( '&  %6d    ', n);
end
fprintf('\n');
for i=1:length(Epsilons)
   epsilon= Epsilons(i);
   fprintf('%8.2e ', epsilon^2);
   for n=1:length(Ns)
      N=Ns(n); % 
      x = Make_1D_Fitted_Mesh(N, epsilon, beta, sigma, MeshType); % 
         
      U = Solve_1DRD(epsilon, x, b, f);
      Errors(i, n) = norm( U - u(x,epsilon), inf);
      fprintf('& %10.3e ', Errors(i,n));
      if (ShowFigures);
         figure(1); plot(x,U, '-o'); title('Comped Solution');
         figure(2); plot(x,u(x,epsilon)-U, '-x'); title('Error');
         pause(1e-1)
      end      
    end
    fprintf('\n');
end