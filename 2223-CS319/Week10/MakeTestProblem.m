function [A,b]=MakeTestProblem(n)
A1 = sparse(1:n, 1:n, 1) ...
   + sparse(2:n, 1:n-1, -0.5, n,n) ...
   + sparse(1:n-1, 2:n, 1/4, n, n);
A = kron(A1,speye(n)) + kron(speye(n),A1) ;
x = ones(length(A),1);
b = A*x;