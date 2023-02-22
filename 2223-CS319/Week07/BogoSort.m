function y = BogoSort(x)
while (~is_sorted(x))
   p = randperm(length(x));
   x=x(p);
end
y=x;