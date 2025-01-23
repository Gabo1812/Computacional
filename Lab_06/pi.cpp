#include <iostream>
// Definimos la función a integrar
double func_integrar(double x) {
    return 4 / (1 + x * x);
}

// Función para la integración numérica utilizando la regla del trapecio
double Int_Riemann(double(*func)(double), double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps;
    double I = 0;
    for (int i = 0; i < steps; ++i) {
        I += func(lim_inf + (i + 0.5) * h) * h;
    }
    return I;
}

int main() {
    int N = 100;  // Número de subintervalos
    double x_inf = 0;
    double x_sup = 1;

    // Imprimimos el resultado
    std::cout << Int_Riemann(func_integrar, x_inf, x_sup, N) << std::endl;
    return 0;
}

