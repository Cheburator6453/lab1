
import numpy as np
# import pylab
import numpy
import matplotlib.pyplot as plt
data = np.loadtxt("data.txt")
plt.plot(data[:, 0], data[:, 1],'bo')
# plt.show()
def makeData():
	x = numpy.arange(-10, 10, 0.5)
	y = numpy.arange(-10, 15, 0.5)
	xgrid, ygrid = numpy.meshgrid(x, y)
	zgrid = (-(-xgrid * xgrid - 13 * xgrid - ygrid * ygrid - 4 * ygrid - 37))
	return xgrid, ygrid, zgrid

x, y, z = makeData()
plt.contour(x, y, z, 25)
# plt.plot(-2.6,1,'ro')
# plt.plot(2.1,4.7,'ro')
# plt.plot(5,7.1,'ro')
# plt.plot(7.5,8.9,'ro')
plt.show()