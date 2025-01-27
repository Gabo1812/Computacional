#include <iostream>
// Definimos la función a integrar
double func_integrar(double x) {
    return 4.0 / (1.0 + x * x);
}

// Función para la integración numérica utilizando suma de Riemann con punto medio.
double Int_Riemann(double(*func)(double), double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps; //Ancho de cada rectangulo
    double I = 0;
    for (int i = 0; i < steps; ++i) {
        I += func(lim_inf + (i + 0.5) * h);
    }
    return I*h;//devuelve el resultado de la integral 
}

int main() {
    int N = 100000;  // Número de subintervalos
    double x_inf = 0; //Limite inferior de la integral
    double x_sup = 1; //Limite superior de la integral

    // Imprimimos el resultado
    std::cout.precision(12); // Definir decimales de precision
    std::cout << Int_Riemann(func_integrar, x_inf, x_sup, N) << std::endl;
    return 0;
}

