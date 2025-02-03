#include<iostream>
#include <cmath> //Libreria para incluir sqrt
#include "complex.hpp"
// Aca viene la implementación, donde primero importamos el complex.hpp
// Inicializamos el constructor y se asignan los atributos iniciales en 0.0 + i*0.0
Complex::Complex() : real(0.0), imag(0.0) {}
// Construir el constructor para parametros
Complex::Complex(double r, double i) : real(r), imag(i) {}
// Constructor copia
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}
// Operador de asignación
Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {  // Evitar la autoasignación
        real = other.real;
        imag = other.imag;
    }
    return *this;
}
// Destructor 
Complex::~Complex() {}

// Metodos de mi clase Complex

// Norma de un numero complejo
double Complex::norm() const {
  return std::sqrt(real * real + imag * imag);
  // Método para imprimir el número complejo
}
void Complex::print() const {
    std::cout << real;
    if (imag >= 0) {
        std::cout << " + " << imag << "i";
    } else {
        std::cout << " - " << -imag << "i";
    }
}
// Método para calcular el conjugado de un número complejo
Complex Complex::conjugate() const {
    return Complex(real, -imag);  // Devuelve un nuevo número complejo con la parte imaginaria negativa
}
// Sobrecarga para los operadores

// Sobrecarga del operador +
// Suma de dos números complejos: (a + bi) + (c + di) = (a+c) + (b+d)i
Complex Complex::operator+(const Complex& other) const {
    double newReal = real + other.real;
    double newImag = imag + other.imag;
    return Complex(newReal, newImag);
}

// Sobrecarga del operador -
// Resta de dos números complejos: (a + bi) - (c + di) = (a-c) + (b-d)i
Complex Complex::operator-(const Complex& other) const {
    double newReal = real - other.real;
    double newImag = imag - other.imag;
    return Complex(newReal, newImag);
}

// Sobrecarga del operador *
// (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex& other) const {
    double newReal = (real * other.real) - (imag * other.imag);
    double newImag = (real * other.imag) + (imag * other.real);
    return Complex(newReal, newImag);
}

// Sobrecarga del operador /
// (a + bi) / (c + di) = [(a+bi)(c-di)] / (c² + d²)
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero complex number!"); // Para evitar posible division por cero
    }

    double newReal = (real * other.real + imag * other.imag) / denominator;
    double newImag = (imag * other.real - real * other.imag) / denominator;
    
    return Complex(newReal, newImag);
}


