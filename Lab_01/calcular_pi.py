#!/usr/bin/env python
#Vamos a resolver la integral de 1/(1+x**2) de 0 a 1
#Usando el cambio de x = tanp
import numpy as np
#Espacio de Funciones
def Int_Riemann(f,a,b,N):
    h = (b-a)/N
    vect = h*f
    I = 0
    for i in range(N):
        I += vect[i]
    return I
def func_integrar(x):
    f = 4/(1+x**2)
    return f
#Main code
N = 100
x_inf = 0
x_sup = 1
h = (x_sup - x_inf)/N
x = np.linspace(x_inf+h/2,x_sup,N)
f = func_integrar(x)
print(Int_Riemann(f,x_inf,x_sup,N))
print(x)# para controlar



