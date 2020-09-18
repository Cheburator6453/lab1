import numpy as np
import matplotlib.pyplot as plt
data1 = np.loadtxt('laba3.txt')
data2 = np.loadtxt('laba4.txt')
plt.subplot(1,2,1)
plt.plot(data1[:,0],data1[:,1])
plt.plot(np.arange(6),[16.1,
14.8,
16.1,
16.2,
18,
17.4
],'ro')
plt.subplot(1,2,2)
plt.plot(data2[:,0],data2[:,1])
plt.plot(np.arange(6),[16.1,
14.8,
16.1,
16.2,
18,
17.4
],'ro')
plt.show()
