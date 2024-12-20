function x=Make_Equidistribute_Mesh(N, epsilon, beta)
%% Make a mesh that equidistributes a layer-type function (note: this is
% not an o posteroi adaptive mesh.
% Inputs: 
%    N   (number of mesh intervals)
%    epsilon (perturbation paramter)
%    beta (lower bound for square-root of reaction term )
% Output:  
%    x (column vector containing mesh points)
%
% 07/12/17 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   GIAN Short Course on Theory and Computation of Singularly
%        Perturbed Differential Equations, 4-8 Dec 2017
% https://skumarmath.wordpress.com/gian-17/singular-perturbation-problems/
% and http://www.maths.nuigalway.ie/~niall/TCSPDEs2017/

x = linspace(0, 1, N+1)';

if (2*epsilon/beta*log(N) < 1/4)
   Iteration=0;
   
   L = x + (2/beta) - (2/beta)*exp(-beta*x/(2*epsilon)) ...
     + (2/beta)*exp(-beta*(1-x)/(2*epsilon));
   
   while( max(diff(L)) >= (1 + 1e-3)*L(end)/N)
      Iteration = Iteration + 1;
      Y = linspace(0, L(N+1), N+1)';
      x = interp1(L, x, Y);
      x(1)=0; x(N+1)=1; % avoid issues with round-off
      L = x + (2/beta) - (2/beta)*exp(-beta*x/(2*epsilon)) ...
         + (2/beta)*exp(-beta*(1-x)/(2*epsilon));
      L(1)=0;
%       plot(x, '-o')
%       fprintf('iter=%2d, C = %1.15e \n', Iteration,  max(diff(L))*N/L(end));
%       pause
   end
end
