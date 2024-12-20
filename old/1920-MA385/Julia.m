% Julia.m for MA385/MA530, Niall Madden.

% Make a Julia set.
% Use Newton's method to solve z^n-1=0 for a set of points in the
% complex plane. There are n possible solutions. two points belong
% to the same subset it they converge to the same point.

clear; % Clear any old vaiables and 
%close all  % close any open figure windows.

n = 4;  % nth roots of unity

k=0:n-1  % the vector (0, 1, ..., n-1)
I = sqrt(-1);
Roots = cos(k*2*pi/n) + I*sin(k*2*pi/n)

N=400; %% Compute for N^2 complex numbers
% Increase this number to get better resolution;
% Decrease it to speed up computations.

Max_Iterations = 1000; %% Conduct at most Max_Iterations 

A=-1.25; B=1.25; h=(B-A)/N;
x = A:h:B; y =A:h:B; %x is real part, y is imaginary

Z = meshgrid(x)  + I*meshgrid(y)'; % Starting points

for k=1:Max_Iterations
    
  Z = Z - (Z.^n -1)./(n*Z.^(n-1));
  T=zeros(N+1,N+1);
  for j=1:n
    T = T+ j*(abs(Z -Roots(j)) <= 1e-3);
  end
end

FigTitle = sprintf('f(z) = z^{%d}-1', n);
figure(1); contourf(x,y,T,n+1); title(FigTitle); axis square
hold on;
plot(real(Roots),imag(Roots),'o','MarkerSize', 14, 'MarkerEdgeColor', 'k', ...
    'MarkerFaceColor', 'g', 'LineWidth',4)
hold off;
