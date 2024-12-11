%% NOISYFIT.M Compute a linear fit to some noisy data
% For CS319 Lab 3

e = 0.1; % magnitude of the noise
d = 1; % degree of the polynomial fit.
f = @(x) 1+2*x - 3*x.^2;

x = linspace(0,1,100);
y = f(x) + e*randn(size(x));
p = polyfit(x , y , d) ;

plot(x,y, '.', x, polyval(p, x), 'LineWidth',3)