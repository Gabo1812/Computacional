# Explanation
La cuadratura gaussiana es un método de integración numérica que utiliza puntos de evaluación y pesos seleccionados de manera óptima. A diferencia de los métodos como el de los trapecios o Simpson, que usan puntos equidistantes, la cuadratura gaussiana selecciona los puntos de manera no uniforme, lo que la hace más precisa para ciertos tipos de funciones.

## Fundamentos Matemáticos

Dada una integral de la forma:

$$
I = \int_a^b f(x) \, dx
$$

La cuadratura gaussiana aproxima esta integral utilizando una suma ponderada de los valores de la función en puntos específicos, que son las raíces de los polinomios de Legendre. La fórmula general para la cuadratura gaussiana es:

$$
I \approx \sum_{i=1}^{n} w_i f(x_i)
$$

donde \( x_i \) son los puntos de evaluación y \( w_i \) son los pesos asociados.

## Ventajas

- Alta precisión con un número reducido de puntos.
- Útil para funciones con alta variabilidad en ciertos intervalos.


