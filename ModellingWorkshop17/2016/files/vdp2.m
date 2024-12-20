
function [] = vdp2


%Parameters
t0 = 0;
t1 = 1000;
mu = 2;
omega = 2;

%Initial conditions
y_init = [0,1];

%Time
tspan = [t0,t1];

%ODE solution
[t,y] = ode45(@(t,y) vdp_oscillator(t,y,mu,omega),tspan,y_init);


%Plotting
figure(1)
plot(t,y(:,1),'k', t,y(:,2),'r')
xlabel('t'),ylabel('y_1, y_2')

figure(2)
plot(y(:,1),y(:,2),'r')
xlabel('y_1 (y)'),ylabel('y_2 (dy/dt)')

figure(3)
plot3(y(:,1),mod(t,2*pi/omega),y(:,2),'r.')
xlabel('y_1 (y)'),ylabel('t'),zlabel('y_2 (dy/dt)')

end

function [dy] = vdp_oscillator(t,y,mu,omega)

y1 = y(1);
y2 = y(2);
dy = [y2;mu*(1-y1^2)*y2-y1+sin(omega*t)];
end
