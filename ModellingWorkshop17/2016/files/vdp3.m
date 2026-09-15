
function [] = vdp3


%Parameters
t0 = 0;
t1 = 1000;
mu = 1;
omega = 1.3;

%Initial conditions
y_init = [0,1];

%Time
tspan = [t0,t1];

%ODE solution
options = odeset('events',@(t,y)events(t,y,mu,omega),'reltol',1e-3,'abstol',1e-3);
[t,y,te,ye,ie] = ode45(@(t,y) vdp_oscillator(t,y,mu,omega),tspan,y_init,options);

%Plotting
figure(1)
plot(t,y(:,1),'k', t,y(:,2),'r')
xlabel('t'),ylabel('y_1, y_2')

figure(2)
plot(y(:,1),y(:,2),'r')
xlabel('y_1 (y)'),ylabel('y_2 (dy/dt)')
hold on
plot(ye(:,1),ye(:,2),'b.')
hold off

figure(3)
plot3(y(:,1),mod(t,2*pi/omega),y(:,2),'r.')
xlabel('y_1 (y)'),ylabel('t'),zlabel('y_2 (dy/dt)')

figure(4)
%plot(te,ye(:,1),'r.')
plot(te(10:end),ye(10:end,1),'r.')
xlabel('t(n)'),ylabel('y_1(n) (y)')

figure(5)
%plot(ye(1:end-1,1),ye(2:end,1),'r.')
plot(ye(10:end-1,1),ye(11:end,1),'r.')
xlabel('y_1(n) (y)'),ylabel('y_1(n+1) (y)')

end

function [dy] = vdp_oscillator(t,y,mu,omega)

y1 = y(1);
y2 = y(2);
dy = [y2;mu*(1-y1^2)*y2-y1+sin(omega*t)];
end

function [value,isterminal,direction] = events(t,y,mu,omega)

y2 = y(2);

value = y2;
isterminal = 0;
direction = 1;
end