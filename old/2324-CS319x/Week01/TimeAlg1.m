% Sum the elements of a link in MATLAB/Octave
N = 10^6;   % N=10^n
A = ones(1,N);
start=tic; 
s1 = 0;
for i=1:length(A)
   s1=s1+A(i);
end
t1=toc(start);
fprintf('N=%8.2e, error=%d, time(s)=%8.4f\n',...
	N, s1-N, t1)



