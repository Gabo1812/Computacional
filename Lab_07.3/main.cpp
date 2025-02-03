#include "complex.hpp"
#include <iostream>

int main() {
    // Crear un número complejo
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    // Mostrar el número complejo
    std::cout << "El primer numero complejo es: ";
    c1.print();  // Imprime el número complejo
    std::cout << std::endl;

    std::cout << "El segundo numero complejo es: ";
    c2.print();  // Imprime el número complejo
    std::cout << std::endl;

    // Mostrar la norma de los números complejos
    std::cout << "La norma del primer complejo es: " << c1.norm() << std::endl;
    std::cout << "La norma del segundo complejo es: " << c2.norm() << std::endl;

    // Obtener el conjugado y mostrarlo
    Complex conjugado1 = c1.conjugate(); // Calcula el conjugado
    std::cout << "El conjugado del primer complejo es: ";
    conjugado1.print(); // Imprimir el conjugado
    std::cout << std::endl;

    Complex conjugado2 = c2.conjugate(); // Calcula el conjugado
    std::cout << "El conjugado del segundo complejo es: ";
    conjugado2.print(); // Imprimir el conjugado
    std::cout << std::endl;

    // Sumar los dos números complejos y mostrar el resultado
    Complex suma = c1 + c2;
    std::cout << "La suma de ambos complejos es: ";
    suma.print(); // Imprimir el resultado de la suma
    std::cout << std::endl;

    // Restar los dos números complejos
    Complex resta = c1 - c2;
    std::cout << "La resta es: ";
    resta.print();
    std::cout << std::endl;

    // Multiplicar los dos números complejos
    Complex producto = c1 * c2;
    std::cout << "El producto de ambos complejos es: ";
    producto.print();
    std::cout << std::endl;

    // Dividir los dos números complejos
    try {
        Complex division = c1 / c2;
        std::cout << "La division es: ";
        division.print();
        std::cout << std::endl;
    } 
    catch (const std::invalid_argument& e) {
    std::cout << "Error: " << e.what() << std::endl; // Imprimir el mensaje de error
    }
    return 0;
}

