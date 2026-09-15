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
% 04/12/17 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   GIAN Short Course on Theory and Computation of Singularly
%        Perturbed Differential Equations, 4-8 Dec 2017
% https://skumarmath.wordpress.com/gian-17/singular-perturbation-problems/
% and http://www.maths.nuigalway.ie/~niall/TCSPDEs2017/
% See also Test_1DRD u_true

N = length(x)-1;
if (size(x,1) == 1)
   x=x'; % x should be a column
end

h = diff(x);
hbar=(x(3:N+1) - x(1:N-1))/2;

delta2 = sparse(...
    [2:N,           2:N,                           2:N], ...
    [1:N-1,         2:N,                           3:N+1], ...
    [1./h(1:N-1); -(1./h(1:N-1) + 1./h(2:N)); 1./h(2:N)]', ...
    N+1, N+1);

A = -epsilon^2*delta2 + ...
   sparse(2:N, 2:N, hbar.*b(x(2:N)),N+1,N+1);
A(1,1)=1; % For the left boundary condition
A(N+1,N+1)=1; % For the right boundary condition
B = [0;hbar.*f(x(2:N));0];
U = A\B;


