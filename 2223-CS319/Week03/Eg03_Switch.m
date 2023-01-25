%% Eg03_Switch.m
%   Author: Niall Madden
%   Date  : Jan 2023
%   What  : Example of using switch/case. Taken from MATLAB help
x = [12, 5, 59, 24];
plottype = 'bar'; % One of 'bar', 'pie', 'pie3'
switch plottype
   case 'bar'
      bar(x)
      title('Bar Graph')
   case {'pie','pie3'}
      pie3(x)
      title('Pie Chart')
   otherwise
      warning('Unexpected plot type. No plot created.')
end