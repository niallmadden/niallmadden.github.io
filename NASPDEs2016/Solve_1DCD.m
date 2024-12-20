function U = Solve_1DCD(epsilon, x, a, b, f)
%% SOLVE_1DCD: a simple finite difference solver for a linear ODE.
% Use a second-order central finite difference scheme, on an arbitrary mesh, 
% to solve a singularly perturbed reaction-diffusion problem:
%            -epsilon^2 u'' + au' + b(x)u = f(x) on (0,1)
%                     and u=0 at boundary
% INPUTS:
%   epsilon: postive perturbation parameter    (size/class 1x1 double)
%         x: column vector of mesh points. Assumed strictly increasing,
%            with x(1)=0, x(N+1)=1.            (size/class (N+1)x1 double)
%         a: convection coefficient              (function handle)
%         b: reaction coefficient              (function handle)
%         N: postive interger, muliple of 4    (size/call 1x1 double)
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
hbar=(x(3:N+1) - x(1:N-1))/2;


delta2 = sparse(...
    [2:N,           2:N,                           2:N], ...
    [1:N-1,         2:N,                           3:N+1], ...
    [1./h(1:N-1); -(1./h(1:N-1) + 1./h(2:N)); 1./h(2:N)]', ...
    N+1, N+1);

 D0 = sparse(...
    [2:N,           2:N], ...
    [1:N-1,         3:N+1], ...
    [-1./(2*hbar);  1./(2*hbar)]', ...
    N+1, N+1);

% Dm = sparse(...
%     [2:N,           2:N], ...
%     [1:N-1,         2:N], ...
%     [-1./h(1:N-1);  1./h(1:N-1)]', ...
%     N+1, N+1);
 
A = -epsilon*delta2 ...
     + spdiags(a(x).*[0;hbar;0],0,N+1,N+1)*D0 ;...
   + sparse(2:N, 2:N, b(x(2:N)).*hbar, N+1, N+1);
A(1,1)=1; % For the left boundary condition
A(N+1,N+1)=1; % For the right boundary condition
B = [0;hbar.*f(x(2:N));0];
U = A\B;


