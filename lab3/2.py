import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
data = np.loadtxt("points.txt")
data1 = np.loadtxt("data.txt")

ax = fig.add_subplot()
ax.plot(data1[:,0], data1[:, 1])
ax.plot(data[:,0], data[:,1], "ro" )
plt.show()
