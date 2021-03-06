function U = Elliptic(epsilon, x, y, B ,F)
%%%% 03/04/05 Niall Madden
% Find a finite difference approximation of two-dimensional
% reaction-diffusion problem.
% -\epsilon (u_xx + u_yy) + b u =f on Omega
% u = 0 on Gamma 
% x and y generated by meshgrid()
% B and F are inline functions
% Return 1-dimensional solution U

  tmp = size(x) - [1,1]; M=tmp(1); N=tmp(2);
  Size = numel(x);
  [M, N]
  %%% For now, we assume M=N
  if (M ~= N)
	  disp('Sorry - must have M = N');
	  return
  end

  % reshape takes elements column-wise, so need to transpose.
  X=reshape(x',[],1); clear x;
  Y=reshape(y',[],1); clear y;
  
  %%boundry_data;
  %% IMPORTANT - Only use homogenous BCs

  Boundary.i = find( (X==0) | (X==1) | (Y==0) | (Y==1));
  Boundary.U = 0; 

  Interior=setdiff( 1:Size, Boundary.i)';

  H1 = X(Interior) - X(Interior-1);      H2 = X(Interior+1)     - X(Interior);
  K1 = Y(Interior) - Y(Interior-(M+1));  K2 = Y(Interior+(M+1)) - Y(Interior);
  
  MainD  = -2./(H1 + H2).*(1./H1 + 1./H2) - 2./(K1 + K2).*(1./K1 + 1./K2);
  SouthD = 2./(K1 + K2).*(1./K1);      NorthD = 2./(K1 + K2).*(1./K2);
  WestD  = 2./(H1 + H2).*(1./H1);      EastD = 2./(H1 + H2).*(1./H2);
  
  I = [Interior;       Interior   ;Interior;   Interior;       Interior;   Boundary.i ];
  J = [Interior;       Interior-1; Interior+1; Interior-(M+1); Interior+(M+1) ;  Boundary.i]; 

  
  S = [-epsilon*MainD+B(X(Interior),Y(Interior)); -epsilon*WestD; ...
	  -epsilon*EastD; -epsilon*SouthD ; -epsilon*NorthD ; ...
	  ones(size(Boundary.i))];
  
  T1 = sparse(I,J,S);
  
  clear I J S MainD EastD WestD NorthD SouthD H1 H2 K1 K2 
   
  
  f=F(X,Y);
  f(Boundary.i)=Boundary.U; %Only hogo
  U = T1 \ f;
  
  
