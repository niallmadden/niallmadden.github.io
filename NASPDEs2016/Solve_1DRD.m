function U = Solve_1DRD(epsilon, x, b, f)
%% SOLVE_1DRD: a simple finite difference solver for a linear ODE.
% Use a second-order central finite difference scheme, on an arbitrary mesh, 
% to solve a singularly perturbed reaction-diffusion problem:
%            -epsilon^2 u'' + b(x)u = f(x) on (0,1)
%                     and u=0 at boundary
% INPUTS:
%   epsilon: postive perturbation parameter    (size/class 1x1 double)
%         x: column vector of mesh points. Assumed strictly increasing,
%            with x(1)=0, x(N+1)=1.            (size/class (N+1)x1 double)
%         N: postive interger, muliple of 4    (size/call 1x1 double)
%         b: reaction coefficient              (function handle)
%         f: source term                       (function handle)
% OUTPUT:
%         U: column vector with the finite difference solution.
%                                              (size/class (N+1)x1 double)
% 15/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Test_1DRD u_true

N = length(x)-1;
if (size(x,1) == 1)
   x=x'; % x should be a column
end

h = diff(x);
Hbar=(x(3:N+1) - x(1:N-1))/2;

delta2 = sparse(...
   [2:N-1,         1:N-1,                         1:N-2], ...
   [1:N-2,         1:N-1,                         2:N-1], ...
   [1./h(2:N-1); -(1./h(1:N-1) + 1./h(2:N)); 1./h(2:N-1)]');

A = -epsilon^2*delta2 + ...
   sparse(1:N-1, 1:N-1, Hbar.*b(x(2:N)));
B = Hbar.*f(x(2:N));
U = [0;A\B;0];
