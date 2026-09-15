function U=Solve_2DRD(epsilon, x, y, b ,f, g)
%% SOLVE_2DRD: a simple finite difference solver for a linear PDE.
% Use a second-order central finite difference scheme, on an arbitrary mesh, 
% to solve a singularly perturbed reaction-diffusion problem:
%       -epsilon^2 (u_xx + u_yy) + b(x,y)u = f(x,y) on (0,1)^2
%                     and u=g at boundary
% INPUTS:
%   epsilon: postive perturbation parameter    (size/class 1x1 double)
%         x: column vector of mesh points. Assumed strictly increasing,
%            with x(1)=0, x(N+1)=1.            (size/class (N+1)x1 double)
%         y: column vector of mesh points. Assumed strictly increasing,
%            with y(1)=0, y(N+1)=1.            (size/class (N+1)x1 double)
%         N: postive interger, muliple of 4    (size/call 1x1 double)
%         b: reaction coefficient              (function handle)
%         f: source term                       (function handle)
%         g: boundary condition                (function handle)
% OUTPUT:
%         U: column vector with the finite difference solution.
%                                             (size/class (N+1)^2x1 double)
% 22/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Test_2DRD

N = length(x)-1; % assuming length(x)=length(y)
[X,Y]=meshgrid(x,y);
Size = numel(X);

% reshape takes elements column-wise, so need to transpose.
X=reshape(X',[],1); clear x;
Y=reshape(Y',[],1); clear y;
  
%% boundry_data (warning: checking for equality between floats!)
Boundary = find( (X==0) | (X==1) | (Y==0) | (Y==1));

% Make the system matrix
Interior=setdiff( 1:Size, Boundary)';

H1 = X(Interior) - X(Interior-1);      H2 = X(Interior+1)   - X(Interior);
Hbar = (H1+H2)/2;
K1 = Y(Interior) - Y(Interior-(N+1));  K2 = Y(Interior+(N+1)) - Y(Interior);
Kbar = (K1+K2)/2;
Scale = Hbar.*Kbar;

% The diagonals, 
NorthD =            Hbar./K2;
WestD  = Kbar./H1;      
EastD  =                          Kbar./H2;
SouthD =            Hbar./K1;
MainD  =    -Kbar.*(1./H1 + 1./H2) - Hbar.*(1./K1 + 1./K2);


I = [Interior;       Interior   ;Interior;   Interior;       Interior;   Boundary ];
J = [Interior;       Interior-1; Interior+1; Interior-(N+1); Interior+(N+1) ;  Boundary];
S = [-epsilon^2*MainD+Scale.*b(X(Interior),Y(Interior)); -epsilon^2*WestD; ...
    -epsilon^2*EastD; -epsilon^2*SouthD ; -epsilon^2*NorthD ; ...
    ones(size(Boundary))];
A = sparse(I,J,S);

%% Reduce the system to eleiminate boundary values
f = Scale.*f(X(Interior), Y(Interior),epsilon) ...
    - A(Interior, Boundary)*g(X(Boundary), Y(Boundary));
A = A(Interior, Interior);

clear I J S MainD EastD WestD NorthD SouthD H1 H2 K1 K2 Scale
   
U=zeros(size(X));
U(Interior) = A\f;  % Warning: this indexing can be slow.
U(Boundary) = g(X(Boundary), Y(Boundary));

  
