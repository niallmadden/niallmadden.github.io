clear;
%%%% 03/04/05 Niall Madden
%%% Test Elliptic.m

N=2^5;
epsilon = 1e-1;
B = inline('2 + x + y');
F = inline('x*0+y*0+1'); 

x = linspace(0,1,N+1);
y = linspace(0,1,N+1);

[X,Y] = meshgrid(x, y);

U = Elliptic(epsilon, X, Y, B, F);

u=reshape(U,N+1,N+1);
mesh(x,y,u);
