import numpy as np

def Cuadratura_Gaussiana(N, lim_inf, lim_sup, f):
    """
    Calcula la integral de una función usando cuadratura de Gauss-Legendre.

    Parámetros:
    N        : int    -> Número de puntos de muestreo.
    lim_inf  : float  -> Límite inferior de integración.
    lim_sup  : float  -> Límite superior de integración.
    f        : función -> Función a integrar.

    Retorna:
    float -> Aproximación de la integral de f en [lim_inf, lim_sup].
    """
    if not isinstance(N, int) or N <= 0:
        raise ValueError("El número de puntos debe ser un entero positivo.")
    if lim_inf >= lim_sup:
        raise ValueError("El límite inferior debe ser menor que el superior.")

    #Aproximación inicial
    # Cálculo de puntos y pesos para la cuadratura de Gauss-Legendre
    a = np.linspace(3, 4 * (N - 1), N) / ((4 * N) + 2)
    x = np.cos(np.pi * a + 1 / (8 * N * N * np.tan(a)))

    # Método iterativo de Newton para calcular las raíces de los polinomios de Legendre
    epsilon = 1e-15
    delta = 1.0
    while delta > epsilon:
        p0 = np.ones(N, dtype=float)
        p1 = np.copy(x) # Deep copy
        for k in range(1, N):
            p0, p1 = p1, ((2 * k + 1) * x * p1 - k * p0) / (k + 1)
        dp = (N + 1) * (p0 - x * p1) / (1 - x ** 2)
        dx = p1 / dp
        x -= dx
        delta = np.max(np.abs(dx))

    # Cálculo de los pesos
    w = 2 * (N + 1) ** 2 / (N ** 2 * (1 - x ** 2) * dp ** 2)

    # Reescalado de puntos y pesos al intervalo [lim_inf, lim_sup]
    pto_esc = 0.5 * (lim_sup - lim_inf) * x + 0.5 * (lim_sup + lim_inf)
    peso_esc = 0.5 * (lim_sup - lim_inf) * w

    # Evaluación de la integral
    return np.dot(f(pto_esc), peso_esc)

# Función a integrar
def func_integrar(x):
    return x**6 - np.sin(2*x) * x**2

# Código principal
lim_inf = 1
lim_sup = 3

# Evaluación para distintos valores de N
for N in [2, 3, 4, 5, 6, 7]:
    print(f"Para N={N}:")
    
    # Calcula la integral utilizando la cuadratura de Gauss-Legendre
    integral = Cuadratura_Gaussiana(N, lim_inf, lim_sup, func_integrar)
    print(f"Valor de la integral para N={N}: {integral}\n")


