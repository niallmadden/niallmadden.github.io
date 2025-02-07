import matplotlib.pyplot as plt
import numpy as np
 
x = np.linspace(-1, 3, 100) # values of x to use
f = lambda x: np.exp(-2*x) - 2*x**2 + 4*x
m = 0.9207; # value of x which gives maximum (to digits)

plt.plot(x, f(x), 'b-', m,f(m),'ro', markersize=10) 
plt.ylim(-1,3)
plt.grid(visible=True)
plt.ylabel('$f(x)=e^{-2x} - 2x^2 + 4x$', fontsize=18)
plt.show()
