%% Test time and memory use of a solver
clear;
k=0;
for n=2.^(6:10)
   k=k+1;
   A = MakeTestProblem(n);
   b = randn(length(A),1);
   DoFs(k)=length(b); 
   tic; x=A\b; SolveTime(k)=toc;
   fprintf("n=%4d, DoFs=%8d, Time(s)=%8.3f\n", ...
      n, DoFs(k), SolveTime(k));
end
loglog(DoFs, SolveTime, ':o', DoFs, 2.0e-8*DoFs.^1.5, '--', ...
   'LineWidth', 2, 'MarkerSize', 10);
legend('Direct Solver Time', 'DoFS^{1/2}', 'Location', 'northwest')