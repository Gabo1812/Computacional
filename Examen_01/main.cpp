#include "tuple.hpp"

int main() {
    // Pruebas de constructores
    Tuple t1;          // Constructor por defecto
    std::cout << "Esta es una tupla por defecto t1: "; t1.print();
    Tuple t2(5);       // Constructor con 5 elementos
    std::cout << "Esta es una tupla t2 con 5 elementos, inicializada en cero: "; t2.print();
    Tuple t3(t2);      // Constructor copia
    std::cout << "Esta es una tupla t3 copiada usando el constructor copia: "; t3.print();

    // Modificar valores
    t2.setElement(0, 1.0); // Agrega 1.0 en la posición 0
    t2.setElement(1, 2.0); // Agrega 2.0 en la posición 1
    t2.setElement(2, 3.0); // Agrega 3.0 en la posición 2
    t2.setElement(3, 4.0); // Agrega 4.0 en la posición 3
    t2.setElement(4, 5.0); // Agrega 5.0 en la posición 4

    // Prueba de operador de asignación
    Tuple t4 = t2;

    // Imprimir valores
    
    std::cout << "Esta es la tupla t2 despues de setearle valores en cada entrada: "; t2.print();
    std::cout << "Esta es la copia de la tupla t2 usando el operador de asignacion, llamada t4: "; t4.print();
    std::cout << "Esta la cantidad de elementos de la tupla t2: "<< t2.getSize()<< std::endl;
    std::cout << "Este es el elemento en la posición 0 de la tupla t2: " << t2.getElement(0) << std::endl;
    // Pruebas de sobrecarga de operadores
    try {
        Tuple sum = t2 + t4;
        Tuple diff = t2 - t4;
        Tuple prod = t2 * t4;
        Tuple quot = t2 / t4;

        std::cout << "Suma de tuplas t2 y t4: "; sum.print();
        std::cout << "Resta de tuplas t2 y t4: "; diff.print();
        std::cout << "Multiplicacion de tuplas t2 y t4: "; prod.print();
        std::cout << "Division de tuplas t2 y t4: "; quot.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

