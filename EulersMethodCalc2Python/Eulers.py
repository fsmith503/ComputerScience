import numpy as np
from matplotlib import pyplot as plt
#python Eulers.py

x0 = 0
y0 = 1
xf = 10
n = 101
deltax = (xf-x0)/(n-1)

x = np.linspace(x0,xf,n)

y = np.zeros([n]);
y[0] = y0;
for i in range(1,n):
	y[i] = (-y[i-1] + np.sin(x[i])) + y[i-1]
	

for i in range(n):
	print(x[i],y[i])

plt.plot(x,y, 'o')
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("Approximate Solution with Euler's Method")
plt.show()
