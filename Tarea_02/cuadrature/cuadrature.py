#Espacios para librerias
import numpy as np
#Espacio para funciones 
#Funcion que calcula los puntos de colocación x_k y los pesos w_k para cuadratura de Gauss
def gaussxw(N):
    # Aproximación inicial
    a = np.linspace(3, 4 * (N - 1), N) / ((4 * N) + 2)
    x = np.cos(np.pi * a + 1 / (8 * N * N * np.tan(a)))

    # Ahora calculamos las raíces de los polinomios utilizando el método de Newton
    # Esto devuelve los puntos de muestreo obtenidos con los polinomios de Legendre
    epsilon = 1e-15
    delta = 1.0
    while delta > epsilon:
        p0 = np.ones(N, dtype = float)
        # Deep copy
        p1 = np.copy(x)
        for k in range(1, N):
            p0, p1 = p1, ((2 * k + 1) * x * p1 - k * p0) / (k + 1)
        dp = (N + 1) * (p0 - x * p1) / (1 - x * x)
        dx = p1 / dp
        x -= dx
        delta = np.max(np.abs(dx))

    # Ahora calculamos los pesos
    w = 2 * (N + 1) * (N + 1)/(N * N * (1 - x * x) * dp * dp)

    # Note que la función devuelve un tuple
    return x,w

# Función que reescala los puntos y pesos en un intervalo [a, b]
def gaussxwab(a, b, x, w):
    # Obtenido de pag 168 Newman)
    return 0.5 * (b - a) * x + 0.5 * (b + a), 0.5 * (b - a) * w

#Función a integrar
def func_integrar(x):
    return x**6 -np.sin(2*x)*x**2

#Main Code
lim_inf = 1
lim_sup = 3

# Evaluación para distintos valores de N
for N in [2, 3, 4, 5, 6, 7]:
    p_muest, peso = gaussxw(N)
    print(f"Para N={N}:")
    print("Puntos de muestreo:", p_muest)
    print("Pesos:", peso, "\n")

    # Escalamos al intervalo [1,3]
    pto_esc, peso_esc = gaussxwab(lim_inf, lim_sup, p_muest, peso)
    print(f"Para N={N}, escalado:")
    print("Puntos escalados:", pto_esc)
    print("Pesos escalados:", peso_esc, "\n")

    # Evaluamos la integral
    integral = np.sum(func_integrar(pto_esc) * peso_esc)
    print(f"Valor de la integral para N={N}: {round(integral,3)}\n")