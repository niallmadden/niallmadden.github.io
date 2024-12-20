function x = Make_Bakhvalov_Mesh(N, epsilon, beta, sigma, q)
%% Make a Baklhvalov mesh 
% Inputs: 
%    N   (number of mesh intervals)
%    epsilon (perturbation paramter)
%    beta (lower bound for square-root of reaction term )
%    sigma (mesh parameter: set to formal order of scheme)
%    q    (mesh parameter: approx proportion of intervals in layer)
% Output:  
%    x (column vector containing mesh points)
% For more info:
%    See Linss "Layer-Adapted Meshes..." Section 2.1.1.
% 06/12/17 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%
%   GIAN Short Course on Theory and Computation of Singularly
%        Perturbed Differential Equations, 4-8 Dec 2017
% https://skumarmath.wordpress.com/gian-17/singular-perturbation-problems/
% and http://www.maths.nuigalway.ie/~niall/TCSPDEs2017/
%
% See also Test_2DRD Solve_2DRD
  tau= 0.0; tauold= -11.0;
  
  meps= sigma*epsilon/beta;

  while ((tau >= 0.0) && abs(tau-tauold) > 1e-10) 
      tauold= tau;
      chitau= meps*log(q/(q-tau));
      tau= q -meps*(1.0-2.0*tau)/(1.0-2.0*chitau);
  end
  chitau= meps*log(q/(q-tau));

  if (chitau < 0.0) 
     x = linspace(0,1,N+1)';
  else
     x=nan(N+1,1);
     i=1:N/2+1;
     k=find((i-1)/N <= tau);
     x(k) = -meps*log(1 - (i(k)-1)/N/q);
     
     k = setdiff(i,k);
     
     x(k) = chitau+(1.0-2.0*chitau)/(1.0-2.0*tau)*((i(k)-1)/N-tau);
     x(N/2+1)=0.5;
     x(N/2+2:end)= 1-x(N/2:-1:1);
  end
end
    
  
 
