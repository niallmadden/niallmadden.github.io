function sorted=is_sorted(x)
n = length(x);
for i=1:n-1
   if (x(i)>x(i+1))
      sorted=false;
      return;
   end
end
sorted=true;