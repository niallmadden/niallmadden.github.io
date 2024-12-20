function u = u_true(x, epsilon)
%% The exact solution to -epsilon^2 u'' + u = exp(x) on (0,1), u(0)=u(1)=0.
% INPUTS:
%   x: points at which to evaluate the solution (size/class Nx1 double)
%   epsilon: postive perturbation parameter (size/class 1x1 double)
% OUTPUT:
%   u: vector of values oh the true solution to the ODE at the points in x
%      (size/class: same as x)
% 15/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Solve_1DRD Test_1DRD
if (epsilon == 1)
   u = exp(1)/2*(exp(x)-exp(-x))./(exp(1)-exp(-1)) - x/2.*exp(x);
else
   u = exp(x)./(1-epsilon^2) + ...
      (exp( (x-1)./epsilon).*(exp(1) - exp(-1/epsilon)) + ...
      exp( (-x)./epsilon).*(1 - ...
      exp((epsilon-1)/epsilon)))./(1-epsilon^2)*(exp(-2/epsilon) -1);
end
 