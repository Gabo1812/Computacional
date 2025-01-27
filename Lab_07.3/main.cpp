#include <iostream>
#include "complex.hpp"

int main() {
    // Crear un número complejo
    Complex c(3.0, 4.0);

    // Mostrar la norma del número complejo c1
    std::cout << "La norma de c1 es: " << c.norm() << std::endl;

    return 0;
}

