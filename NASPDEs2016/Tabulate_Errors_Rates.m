%% Display some tables: errors and rates

fprintf('%6s   ', 'N');
for n=Ns
    fprintf( '&  %12d    ', n);
end
fprintf('\n%s\n', ...
   repmat('-', 1,128));
for i=1:length(Epsilons)
   epsilon= Epsilons(i);
   fprintf('%8.2e ', epsilon^2);
   for n=1:length(Ns)
      if (n<length(Ns))
         Rate=log2(Errors(i,n)/Errors(i,n+1));
      else
         Rate = nan;
      end
      fprintf('& %10.3e (%4.2f) ', ...
         Errors(i,n), Rate);
   end
   fprintf('\n');
end