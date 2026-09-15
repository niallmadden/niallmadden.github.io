%% MA385/MA530. Oct/Nov 2019
% Heat.m - explicit and implicit solver for the heat equation
%       u_t = u_xx  for 0<x<L, t>0 
% using both explicit and implicit methods
% Niall Madden
clear


fprintf('\n\n--------------------------------------------------\n');
fprintf('  Finite difference solver for the Heat Equation\n');
fprintf('    For more information, see MA385/MA530 notes\n');
T=3; % Final time 
L=pi; % Domain is (0, pi)
M=20; % Number of intervals in x-direction
H = L/M; % space step
x = 0:H:L; % x-mesh


N=20; % Number of intervals in t-direction
h = T/N; % time step
t = 0:h:T; %t-mesh

%% Plot the true solution
figure(1);
[X,Y]=meshgrid(x,t); % full grid 
u = exp(-Y).*sin(X); % solution
surf(X,Y,u); axis([0 L 0 T 0 1])
title('True solution');
fprintf('Figure 1 shows the true solution. ');
fprintf('(Paused - hit any ket to continue)\n');
pause;

%% Compute the numerical solution
U =zeros(N+1,M+1)+NaN; % 
U(1,:) = sin(x);   % initial value 
U(:, 1) = 0;        % boundary values 
U(:, M+1) = 0;
% Explicit solver 
for j=2:N % for each time step
  for i=2:M % for space step in the interior
      delta2u = (U(j-1,i-1) -2*U(j-1,i) + U(j-1,i+1))/(H^2);
      U(j,i) = U(j-1,i) + h*delta2u;
  end
  figure(2);
  surf(X,Y,U); axis([0 L 0 T min(min(U)) max(max(U))]);
   title('Explicit method');
  pause(.3);
end
fprintf('Figure 2 shows the numerical solution obtained using the explicit method\n');

figure(2);
surf(X,Y,U); axis([0 L 0 T min(min(U)) max(max(U))]); title('Explicit method');

pause
%% Implicit solver
V =zeros(N+1,M+1)+NaN;
V(1,:) = sin(x);
V(:,1) = 0;
V(:,M+1) = 0;

% Build the matrix
% This is a very slow way of doing it, but OK for demonstration
A = sparse(M+1, M+1);
A(1,1)=1; A(M+1, M+1)=1;

for i=2:M
    A(i,i-1) = -h/H^2; 
    A(i,i) = 2*h/H^2 + 1; 
    A(i,i+1) = -h/H^2; 
end
% The following construct is the same as the one above, but faster and more
%  obscure
% A = sparse(2:M, 1:M-1, -h/H^2, M+1, M+1) + ...
%     sparse(2:M, 2:M,  2*h/H^2+1, M+1, M+1) + ...
%     sparse(2:M, 3:M+1, -h/H^2, M+1, M+1);
% A(1,1)=1; A(M+1, M+1)=1;
for j=2:N
    V(j,:) = A\V(j-1,:)'; % Solve the linear system
    figure(3);
    surf(X,Y,V); axis([0 L 0 T min(min(V)) max(max(V))])
    pause(.2)
end
fprintf('Figure 3 shows the numerical solution obtained using the implicit method\n');

  
