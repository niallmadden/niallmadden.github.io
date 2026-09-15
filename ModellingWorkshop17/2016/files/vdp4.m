
function [] = vdp4


%Parameters
t0 = 0;

mu = 1;
omega_v = 1:.01:2;

%Initial conditions
y_init = [0,1];


figure(1)

for k = 1:length(omega_v)
%ODE solution

omega = omega_v(k);

%Time

t1 = 100*2*pi/omega;
tspan = [t0,t1];

options = odeset('events',@(t,y)events(t,y,mu,omega));
[t,y,te,ye,ie] = ode45(@(t,y)vdp_oscillator(t,y,mu,omega),tspan,y_init,options);


plot(omega,ye(10:end,1),'r.')
hold on
xlabel('omega'),ylabel('y_1 (y)')

end


end

function dy = vdp_oscillator(t,y,mu,omega)

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