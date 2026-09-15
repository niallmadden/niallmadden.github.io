%%  Using the Bisection method to find a zero of f(x)
% Who: Niall Madden (Niall.Madden@NUIGalway.ie)
% Why: Lab1 of MA385
% When: 26 Sep 2019

clear;

fprintf('\n\n---------\n Using Bisection\n');
% The function is
f = @(x)(exp(x) - (2-x).^3);
fprintf('Solving f=0 with the function\n');
disp(f);

%% The true solution is
tau = 0.72614446580549503614;
fprintf('The true solution is %12.8f\n\n', tau);

fprintf(' k |      x(k)      | |tau-x(k)|\n');
fprintf('---------------------------------\n');
%% Our initial guesses are x_1=0 and x_2 =2;
x(1)=0;
fprintf('%2d | %14.8e | %9.3e \n', 1, x(1), abs(tau - x(1)));
x(2)=5;
fprintf('%2d | %14.8e | %9.3e \n', 2, x(2), abs(tau - x(2)));

for k=2:8
   x(k+1) = (x(k-1)+x(k))/2;
   if ( f(x(k+1))*f(x(k-1)) < 0)
      x(k)=x(k-1);
   end
   fprintf('%2d | %14.8e | %9.3e\n', k+1, x(k+1), abs(tau - x(k+1)));
end

    
