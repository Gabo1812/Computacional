#include "tuple.hpp"

int main() {
    // Pruebas de constructores
    Tuple t1;          // Constructor por defecto
    Tuple t2(5);       // Constructor con 5 elementos
    Tuple t3(t2);      // Constructor copia

    // Modificar valores
    t2.setElement(0, 1.0);
    t2.setElement(1, 2.0);
    t2.setElement(2, 3.0);
    t2.setElement(3, 4.0);
    t2.setElement(4, 5.0);

    // Prueba de operador de asignación
    Tuple t4 = t2;

    // Imprimir valores
    std::cout << "Esta es una tupla t2: "; t2.print();
    std::cout << "Esta es la copia de la tupla t2, llamada t4: "; t4.print();

    // Pruebas de sobrecarga de operadores
    try {
        Tuple sum = t2 + t4;
        Tuple diff = t2 - t4;
        Tuple prod = t2 * t4;
        Tuple quot = t2 / t4;

        std::cout << "Suma de tuplas t2 y t4: "; sum.print();
        std::cout << "Resta de tuplas t2 y t4: "; diff.print();
        std::cout << "Multiplicación de tuplas t2 y t4: "; prod.print();
        std::cout << "División de tuplas t2 y t4: "; quot.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

