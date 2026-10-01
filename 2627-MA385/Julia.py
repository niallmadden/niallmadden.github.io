# Julia.py: making Julia sets with Newton's Method

## The idea
# The complex $n^\mathrm{th}$ roots of unity is the set of
# numbers z_0, z_1,... , z_{n-1} such that (z_k)^n=1.
# For example, the 4th roots of unity are 1, -1, i=\sqrt{-1} and -i. 
#  
# Suppose we wanted to estimate these numbers using Newton's method.
# We could try to solve f(z)=0 with f(z)=z^n-1. Then the iteration is:
# $$
#  z_{k+1}= z_k - \frac{(z_k)^n -1}{n (z_k)^{n-1}}.
# $$

# However, there are $n$ possible solutions to  z^n-1=0.
# Given a particular starting point, which root with the method
# converge to? If we take a number of points in a region of space,
# iterate on each of them, and then colour the points to indicate
# the ones that converge to the same root, we get the  famous Julia Set.

import numpy as np
import matplotlib.pyplot as plt


# ## Define parameters
# * `n` is the number of roots
# * `N` defines the resolution. Larger values give nicer pictures,
# but are slower to run

n = 4    # nth roots of unity
N = 800  # resolution (N^2 points)
Max_Iterations = 1000
x0, x1 = -1.1, 1.1 # corners for domain
y0, y1 = -1.1, 1.1 # corners for domain


## Computations
k = np.arange(n) 
Roots = np.cos(k*2*np.pi/n) + 1j*np.sin(k*2*np.pi/n)

x = np.linspace(x0,x1,N)
y = np.linspace(y0,y1,N)
X, Y = np.meshgrid(x, y) # Grid of complex numbers
Z = X+1j*Y

# Newton iteration
for _ in range(Max_Iterations):
    Z = Z - (Z**n-1)/(n*Z**(n-1))

# Classification of convergence
T = np.zeros(Z.shape, dtype=int)
for j in range(n):
    T[np.abs(Z-Roots[j]) <= 1e-3] = j+1


# Plot
fig, ax = plt.subplots(figsize=(6,6))
c = ax.contourf(x, y, T, levels=n+1, cmap="jet")
ax.set_title(f"$f(z) = z^{n} - 1$")
ax.set_aspect("equal")

ax.plot(Roots.real, Roots.imag, '*', markersize=10,linewidth=4)
plt.savefig("Julia.png", dpi=300, bbox_inches="tight")
plt.show()

