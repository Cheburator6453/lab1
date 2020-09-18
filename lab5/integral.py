import math as m
def funct(x):
    return (m.exp(-1/m.pow(x,2))) / m.pow(x, 2)
eps = 0.0001
b = 1.5
a = 8 - m.log(m.exp(8)-eps);
c = 1000000.0
h = (b - a) / c
p = 0
p_temp=1
n=0
while (m.fabs(p - p_temp) > eps):
    p_temp = p
    c = c+1000000
    h = (b - a) / c
    p = 0
    i = a
    n=n+1
    while(i<b):
        i =i+h
        p =p+h*(funct(i)+funct(i+h))/2
       
    
print("Ответ:" )
print(p)

print("Кол-во итераций: " )
print(n)

