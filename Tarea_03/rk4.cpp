#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

double func(double x_val, double y_val) {
    // Retorna el criterio de la función 
    return sin(x_val + y_val) - cos(x_val - y_val);
}

double rk4(double (*func)(double, double), double x_val, double y_val, double h) {
    // Calcula un paso del método de Runge-Kutta de cuarto orden
    double k1 = h * func(x_val, y_val);
    double k2 = h * func(x_val + 0.5 * h, y_val + 0.5 * k1);
    double k3 = h * func(x_val + 0.5 * h, y_val + 0.5 * k2);
    double k4 = h * func(x_val + h, y_val + k3);
    
    return y_val + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
}

int main() {
    // Definición de parámetros
    double h = 0.025;
    // Donde va de x=0 a x=25
    int total_iteraciones = int((25 - 0) / h);
    
    // Vectores para almacenar los valores calculados
    std::vector<double> x_vals(total_iteraciones);
    std::vector<double> y_vals(total_iteraciones);

    // Condiciones iniciales
    x_vals[0] = 0;
    y_vals[0] = 0;

    // Cálculo iterativo con el método de Runge-Kutta
    for (int i = 0; i < total_iteraciones - 1; i++) {
        x_vals[i+1] = x_vals[i] + h;
        y_vals[i+1] = rk4(func, x_vals[i], y_vals[i], h);
    }
    /*
    // Descomentar de ser necesario 
    // Guardar resultados en un archivo
    std::ofstream archivo("resultados.dat");
    if (archivo.is_open()) {
        for (int i = 0; i < total_iteraciones; i++) {
            archivo << x_vals[i] << " " << y_vals[i] << "\n";
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
    */
    return 0;
}
