function v = tocolumn(x)
if ( min(size(x)) ~= 1 || size(x,1)==2)
    v=x;
else
   v=x';
end