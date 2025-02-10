#ifndef TUPLE_HPP     // Verifica si TUPLE_HPP no ha sido definido aún
#define TUPLE_HPP    // Define TUPLE_HPP para evitar múltiples inclusiones
#include <iostream> // Para usar size_t
//Acá viene la declaracion de la clase Complex
class Tuple{  
  private:
    double* data;   // Puntero a la memoria donde se almacenan los valores
    size_t size;   // Número de elementos en la estructura
  public:
    // Constructores
    Tuple();                              // Constructor por defecto que inicializa un solo valor en la memoria
    Tuple(size_t n);                      // Constructor que asigna memoria para N valores, inicializados en 0.0
    Tuple(const Tuple& other);            //COnstructor copia
    Tuple& operator=(const Tuple& other); // Operador de asignación
    ~Tuple();                             // Destructor

    // Métodos de la clase
    size_t getSize() const;                          // Método para obtener el tamaño de la estructura
    double getElement(size_t index) const;          // Método para acceder a un elemento específico
    void setElement(size_t index, double value);   // Método para modificar un elemento específico
    void print() const;                           // Método para imprimir los valores

    // Sobrecarga de operadores
    Tuple operator+(const Tuple& other) const;  // Sobrecarga del operador +
    Tuple operator-(const Tuple& other) const;  // Sobrecarga del operador -
    Tuple operator*(const Tuple& other) const;  // Sobrecarga del operador *
    Tuple operator/(const Tuple& other) const;  // Sobrecarga del operador /
};
#endif