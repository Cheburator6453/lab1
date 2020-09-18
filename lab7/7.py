import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
data1=np.loadtxt("Shema.txt")
data2=np.loadtxt("ToResh.txt")
x=np.linspace(0,2,200)

y_vector = [1,0]

def func(y, x):
    f=np.array([y[1],1/4*(x*np.exp(-x)-5*y[1]-2*y[0])])
    return f

Ode = odeint(func, y_vector, x)

plt.figure(figsize=(16, 9))
plt.title("Решение", fontsize=14)
plt.plot(data1[:,0],data1[:,1],label = 'Неявный метод для y')
plt.plot(data2[:,0],data2[:,1],label='Точное решение для y')
plt.plot(x, Ode[:,0], label = 'Встроенная функция')

plt.legend()
plt.ylabel('y')
plt.xlabel('x')
plt.minorticks_on()
plt.grid(which="both")
plt.show()

plt.figure(figsize=(16, 9))
plt.title("Производная", fontsize=14)
plt.plot(data1[:,0],data1[:,2],label = "Неявный метод для y' ")
plt.plot(x, Ode[:,1], label = 'Встроенная функция')


plt.legend()
plt.ylabel('dy/dx')
plt.xlabel('x')
plt.minorticks_on()
plt.grid(which="both")


plt.figure(figsize=(16, 9))
plt.title("Фазовый портрет", fontsize=14)
plt.plot(data1[:,1], data1[:,2])
plt.xlabel("$y(x)$", fontsize=14)
plt.ylabel("$y'(x)$", fontsize=14)
plt.minorticks_on()
plt.grid(which="both")

plt.figure(figsize=(16, 9))
plt.title("Разностные графики", fontsize=14)
plt.plot(data1[:,0],data1[:,1],label='Неявный метод для y')
plt.plot(data2[:,0],data2[:,1],'--',label='Точное решение для y')
plt.plot(data1[:,0],data1[:,2],label="Неявный метод для y' ")
plt.plot(x, Ode[:,0],'--', label = 'Встроенная функция y')
plt.plot(x, Ode[:,1],'--', label = "Встроенная функция y'")
plt.legend()
plt.grid(which="both")
plt.show()


