%% Problem_Data.m
% Data for a singularly perturbed reaction-diffusion equation with
%  known solution.
%  Defines
%  u_true (function handle) 
%  b (function handle)
%  f (function handle)
% 22/07/16 - Niall Madden (Niall.Madden@NUIGalway.ie) for the 
%   AARMS-CRM Workshop on Numerical Analysis of Singularly
%        Perturbed Differential Equations, July 25-29.
%     http://www.math.mun.ca/~smaclachlan/anasc_spde/
% See also Test_2DRD Solve_2DRD

b = @(x,y)(1 + x*0 + y*0);
beta = 0.99; % A lower bound for bble at (1,0)

u_true = @(x,y,epsilon)( ... 
    (cos(pi*x/2) - (exp(-x/epsilon)-exp(-1/epsilon))/(1-exp(-1/epsilon))).*(...
    1-y-(exp(-y/epsilon) - exp(-1/epsilon))/(1-exp(-1/epsilon))));

Ux = @(x,y,epsilon)( ... 
    (-pi/2*sin(pi*x/2) + exp(-x/epsilon)/(epsilon*(1-exp(-1/epsilon)))).*(...
    1-y-(exp(-y/epsilon) - exp(-1/epsilon))/(1-exp(-1/epsilon))));

Uxy = @(x,y,epsilon)( ... 
    (-pi/2*sin(pi*x/2) + exp(-x/epsilon)/(epsilon*(1-exp(-1/epsilon)))).*(...
    -1+exp(-y/epsilon)/(epsilon*(1-exp(-1/epsilon)))));

eps2Uxx = @(x,y,epsilon)( ... 
    (-epsilon^2*(pi/2)^2*cos(pi*x/2) - exp(-x/epsilon)/(1-exp(-1/epsilon))).*(...
    1-y-(exp(-y/epsilon) - exp(-1/epsilon))/(1-exp(-1/epsilon))));


Uy = @(x,y,epsilon)( ... 
    (cos(pi*x/2) - (exp(-x/epsilon)-exp(-1/epsilon))/(1-exp(-1/epsilon))).*(...
    -1+exp(-y/epsilon)/(epsilon*(1-exp(-1/epsilon)))));
eps2Uyy = @(x,y,epsilon)( ... 
    (-cos(pi*x/2) + (exp(-x/epsilon)-exp(-1/epsilon))/(1 ...
    -exp(-1/epsilon))).*exp(-y/epsilon)/(1-exp(-1/epsilon)));

 
%% This version for arbitrary B -- DONT USE (except with extreme care)
% B = @(x,y)(1 + x*0 + y*0); %% DONT USE
% f = @(x,y,epsilon)(-eps2Uxx(x,y,epsilon) - eps2Uyy(x,y,epsilon) ...
%         + B(x,y).*U(x, y,epsilon));  
%% This version for B=1
f = @(x,y,epsilon)(-eps2Uxx(x,y,epsilon) - eps2Uyy(x,y,epsilon) ...
        + u_true(x, y,epsilon));  

