#include "tuple.hpp"
// Aca viene la implementación, donde primero importamos el tuple.hpp

// Constructor por defecto: asigna memoria para un solo valor e inicializa en 0.0
Tuple::Tuple() : size(1) {
    data = new double[size];  // Asigna memoria para un solo elemento
    data[0] = 0.0;            // Inicializa el valor en 0.0
}

// Constructor personalizado: asigna memoria para N valores e inicializa en 0.0
Tuple::Tuple(size_t n) : size(n) {
    if (n == 0) {
        throw std::invalid_argument("El tamaño no puede ser 0.");
    }
    data = new double[size];  // Asigna memoria para N elementos
    for (size_t i = 0; i < size; i++) {
        data[i] = 0.0;        // Inicializa todos los elementos en 0.0
    }
}
// Constructor copia
Tuple::Tuple(const Tuple& other) : size(other.size) {
    data = new double[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}
// Operador de asignación
Tuple& Tuple::operator=(const Tuple& other) {
    if (this == &other) {
        return *this; // Evitar autoasignación
    }

    delete[] data; // Liberar memoria previa

    size = other.size;
    data = new double[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}
// Destructor: libera la memoria asignada
Tuple::~Tuple() {
    delete[] data;  // Evita fugas de memoria
}

// Devuelve el número de elementos en la estructura
size_t Tuple::getSize() const {
    return size;
}

// Obtiene un elemento del contenedor con verificación de índice
double Tuple::getElement(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return data[index];
}

// Modifica un elemento del contenedor con verificación de índice
void Tuple::setElement(size_t index, double value) {
    if (index >= size) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    data[index] = value;
}

// Imprime todos los valores almacenados en el contenedor
void Tuple::print() const {
    std::cout << "[ ";
    for (size_t i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Sobrecarga para los operadores

/// Operador +
Tuple Tuple::operator+(const Tuple& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Los objetos deben tener el mismo tamaño.");
    }

    Tuple result(size);
    for (std::size_t i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// Operador -
Tuple Tuple::operator-(const Tuple& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Los objetos deben tener el mismo tamaño.");
    }

    Tuple result(size);
    for (std::size_t i = 0; i < size; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// Operador *
Tuple Tuple::operator*(const Tuple& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Los objetos deben tener el mismo tamaño.");
    }

    Tuple result(size);
    for (std::size_t i = 0; i < size; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

// Operador /
Tuple Tuple::operator/(const Tuple& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Los objetos deben tener el mismo tamaño.");
    }

    Tuple result(size);
    for (std::size_t i = 0; i < size; i++) {
        if (other.data[i] == 0) {
            throw std::runtime_error("División por cero.");
        }
        result.data[i] = data[i] / other.data[i];
    }
    return result;
}
