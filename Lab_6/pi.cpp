#include <iostream>
// Definimos la función a integrar
double func_integrar(double x){
  return 4/(1+x*x);  
}
// Función para la integración numérica utilizando la regla del trapecio
double Int_Riemann(double(*func_integrar(double x)) double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps;
    double I = 0;
    for (int i = 0; i < steps; ++i) {
        I += func_integrar[i];
    }
    return I * h;
}

int main() {
    int N = 100;  // Número de subintervalos
    double x_inf = 0;
    double x_sup = 1;
    double h = (x_sup - x_inf) / N;

    // Creación del vector de puntos


    // Creación del vector con los valores de la función evaluada en x

    // Realizamos la integración numérica
    double result = Int_Riemann(f, x_inf, x_sup, N);

    // Imprimimos el resultado
    cout << "El valor de la integral es: " << result << endl;

    return 0;
}
