%% MANDEL Mandelbrot set.
% Taken from Listing 1.4 of The MATLAB Guide, 3rd Ed
% https://epubs-siam-org.nuigalway.idm.oclc.org/doi/pdf/10.1137/1.9781611974669.ch1
h = waitbar(0,'Computing...');
x = linspace(-2.1,0.6,2001);
y = linspace(-1.1,1.1,2001);
[X,Y] = meshgrid(x,y);
C = complex(X,Y);
Z_max = 1e6; it_max = 50;
Z = C;
for k = 1:it_max
   Z = Z.^2 + C;
   waitbar(k/it_max)
end
close(h)
contourf(x,y,double(abs(Z)<Z_max))
colormap([1 1 1; 1/2 1/2 1/2]) % Gray inside, white outside.
title('Mandelbrot Set','FontSize',16,'FontWeight','normal')