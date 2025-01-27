#include <iostream>
#include "complex.hpp"

int main() {
    // Crear un número complejo
    Complex c1(3.0, 4.0);

    // Mostrar la norma del número complejo c1
    std::cout << "La norma de c1 es: " << c1.norm() << std::endl;

    return 0;
}

