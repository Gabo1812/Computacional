#!/usr/bin/env python3
#Gabriel Alvarez Castrillo C00368
#Lab_01 Fisica Computacional
#Vamos a resolver la integral de 4/(1+x**2) de 0 a 1 para encontrar pi
#Espacio de Funciones
#Recordando que la integral es el aŕea bajo la curva, con este metodo
#Lo que haremos es dividir el área en rectangulos e irlos sumando.
def Int_Riemann(func,x_inf,x_sup,steps):
    h = (x_sup-x_inf)/steps #Distancia entre pasos/largo del rectangulo
    I = 0 # Inicializamos la variable
    for i in range(steps):
        I += func(x_inf+(i+0.5)*h)*h #Sumamos el área de cada rectangulo
    return I
#Función a Integrar
def func_integrar(x):
    return 4/(1+x**2)#Se cambia por la función que se quiera integrar

#Main code
step = 1000#Numero de pasos o divisiones que haremos
x_inf = 0#limite inferior de la integral
x_sup = 1#limite superior de la integral
print(Int_Riemann(func_integrar,x_inf,x_sup,step))#Mostramos el resultado en pantalla




