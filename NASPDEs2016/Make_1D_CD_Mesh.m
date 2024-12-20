function x = Make_1D_CD_Mesh(N, epsilon, beta, sigma, MeshType) 
%% Construct a fitted mesh on [0,1] for solving a one-dimensional 
% singularly perturbed problem. 
% INPUTS:
%         N: postive interger, muliple of 4    (size/call 1x1 double)
%   epsilon: postive perturbation parameter    (size/class 1x1 double)
%      beta: lower bound for the reaction term (size/class 1x1 double)
%     sigma: formal order or the scheme        (size/class 1x1 double)
%  MeshType: one of 'uniform' or 'shishkin'    (size/class 1xs char)
% OUTPUT:
%         x: column vector of mesh points. Strictly increasing,
%            with x(1)=0, x(N+1)=1.            (size/class (N+1)x1 double)
% Notes: 
%   No bounds checking done. Please use sensibly.
%   MeshType is not case-sensitve.
%   Using "unique" to compare floats, which is not a good idea.
%
%             (size/class 1x(N+1) double).
% 15/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Solve_1DRD Test_1DRD 

if (strcmpi(MeshType, 'Uniform'))
   x = linspace(0,1,N+1)';
elseif (strcmpi(MeshType, 'Shishkin'))
   tau = min(1/2, sigma*epsilon/beta*log(N));
   x = unique([linspace(0, 1-tau, N/2+1), ...
      linspace(1-tau,1, N/2+1)])';
else
   fprintf('WARNING: I do not know what type of mesh %s is!\n', MeshType);
   x=nan(N+1,1);
end