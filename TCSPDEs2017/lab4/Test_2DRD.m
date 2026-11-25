%% Test_2DRD.m
% Tests a finite difference solver for a 2D singularly perturbed
%  reaction-diffusion problem:
%        -epsilon^2 (u_xx + u_yy) + u = f(x,y) on (0,1)x(0,1)
%                     and u=0 at boundary
% Discretization: Galerkin FEM with second-order central differences.
% Mesh: Piecewise uniform (Shishkin) mesh with N subinterval in each
%       coordinate direction.
% The user should specify
%  * the range of epsilon. Default is [1, 1e-1, 1e-2, ... 1e-6]
%  * the range of N. Default is [8, 16, ...,  256]
% Errors are calculated using the exact solution.
%
% 06/12/17 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   GIAN Short Course on Theory and Computation of Singularly
%        Perturbed Differential Equations, 4-8 Dec 2017
% https://skumarmath.wordpress.com/gian-17/singular-perturbation-problems/
% and http://www.maths.nuigalway.ie/~niall/TCSPDEs2017/
% See also Solve_2DRD Problem_Data 
fprintf('\n\n-----------------------------------------------------------\n');
fprintf(' Solving a singularly perturbed reaction-diffusion problem   \n');
fprintf('  in 2D  with a finite differene method.             \n');

clear;

ShowFigures=false; % Set to 'true' if you wany to see graph of the 
                   % solution and error.
%% Problem data
Epsilons=10.^(0:-1:-6); % Will try epsilon=1e-0, 1e-2,...,1e-6;
Problem_Data;
g = @(x,y)(x.*y.*0); % zero boundary conditions


%% Discretization data
Ns = 2.^(3:8); % Values of N we will try.
MeshType='Shishkin';  % Choose one of Uniform, Shishkin, (or Bakhvalov?).
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
      y = x;
      U = Solve_2DRD(epsilon, x, y, b, f, g);
      U = reshape(U, N+1, [])';
      
      [X,Y]=meshgrid(x,y);
      Errors(i, n) = max(max(abs(U-u_true(X,Y,epsilon))));
      fprintf('& %10.3e ', Errors(i,n));
      if (ShowFigures);
         figure(1); surf(x,y,U);          title('Computed Solution');
         figure(2); surf(x,y,u_true(X,Y,epsilon)); title('true');
         figure(3); surf(x,y,U-u_true(X,Y,epsilon)); title('Error');
         pause(1e-1)
      end      
    end
    fprintf('\n');
end