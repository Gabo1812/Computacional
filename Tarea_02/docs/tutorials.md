# Tutorials

A continuación, encontrarás tutoriales sobre cómo implementar la cuadratura gaussiana en diferentes situaciones.

## Tutorial 1: Integración de una función simple

En este tutorial, te mostramos cómo integrar una función simple como \( f(x) = x^2 \) en el intervalo [0, 1] usando la cuadratura gaussiana.

```python
import numpy as np
from gauss_quadrature import gauss_quadrature

# Definir la función a integrar
def func(x):
    return x**2

# Llamar a la función de cuadratura gaussiana
resultado = gauss_quadrature(func, 0, 1, 3)

print("Resultado de la integración:", resultado)

