%% File  : Eg05_Newton.m
%  Date  : Jan 2023 (CS319 Week 03)
%  What  : Use a while to implement Newton's method

f = @(x)x.^2-2;
df = @(x)2*x;
fplot(f, [0,3]);

xk = 1;
k = 0;
fprintf("k=%2d, xk=%f, f(xk)=%8.2e\n", ...
   k, xk, f(xk))
while (abs(f(xk)) > 1.0e-6)
   k=k+1;
   xk = xk - f(xk)/df(xk);
   fprintf("k=%2d, xk=%f, f(xk)=%8.2e\n", ...
      k,xk,f(xk))
end
