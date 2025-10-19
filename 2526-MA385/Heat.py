## Heat.py
# --------------------------------------------------
# Explicit and Implicit
# Finite Difference solver for the Heat Equation
#     u_t = u_xx,  for 0 < x < L, t > 0
# --------------------------------------------------

# Niall Madden, for MA385. Sectionn 2-6:

import numpy as np
import matplotlib.pyplot as plt
from scipy.sparse import diags, eye, lil_matrix
from scipy.sparse.linalg import spsolve
from time import sleep

# Parameters
T = 3.0          # Final time
L = np.pi        # Domain (0, pi)
Nx = 32           # Number of spatial intervals
Nt = 32           # Number of time intervals

hx,ht = L/Nx, T/Nt  # step sizes
x = np.linspace(0, L, Nx+1)
t = np.linspace(0, T, Nt+1)
X, Y = np.meshgrid(x, t)

# True solution
u_true = np.exp(-Y) * np.sin(X)
fig1 = plt.figure(1)
ax1 = fig1.add_subplot(111, projection='3d')
ax1.plot_surface(X, Y, u_true, cmap='viridis')
ax1.set_xlabel('x'), ax1.set_ylabel('t')
ax1.set_zlabel('u')
ax1.set_title('True solution')
plt.show(block=False)
print("Figure 1 shows the true solution.")
input("Press Enter to continue...")

## Explicit solver
U = np.full((Nt+1, Nx+1), np.nan)
U[0, :] = np.sin(x)   # Initial condition
U[:, 0] = 0           # Boundary condition
U[:, -1] = 0


fig = plt.figure(2)
ax = fig.add_subplot(111, projection="3d")
for j in range(1, Nt+1):
    for i in range(1, Nx):
        delta2 = (U[j-1,i-1] - 2*U[j-1, i] + U[j-1, i+1])/(hx**2)
        U[j, i] = U[j-1,i] + ht*delta2


    ax.plot_surface(X, Y, U, cmap="plasma")
    ax.set_title(f"Explicit method, step {j}")
    ax.set_xlabel("x"), ax.set_ylabel("t")

    plt.pause(0.5)

print("Figure 2 shows the numerical solution obtained using the explicit method.")
plt.show(block=False)
input("Press Enter to continue...")

## Implicit solver
V = np.full((Nt+1, Nx+1), np.nan)
V[0, :] = np.sin(x)   # Initial condition
V[:, 0] = 0           # Boundary condition
V[:, -1] = 0

# Build the tridiagonal matrix A
# There are better ways to do this: this is for clarity.
A = lil_matrix((Nx+1,Nx+1))
A[0,0]=1
A[Nx,Nx]=1
for i in range(1,Nx):
    A[i,i-1]=-ht/hx**2
    A[i,i]  =2*ht/hx**2+1
    A[i,i+1]=-ht/hx**2

plt.figure(3)
ax = plt.axes(projection="3d")
for j in range(1, Nt+1):
    V[j, :] = spsolve(A, V[j-1,:])

    ax.plot_surface(X, Y, V, cmap="inferno")
    ax.set_title(f"Implicit method, step {j}")
    ax.set_xlabel("x"), ax.set_ylabel("t")
    plt.pause(0.3)


plt.show()
