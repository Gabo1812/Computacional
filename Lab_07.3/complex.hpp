#ifndef COMPLEX_HPP // Verifica si COMPLEX_HPP no ha sido definido aún
#define COMPLEX_HPP // Define COMPLEX_HPP para evitar múltiples inclusiones
//Acá viene la declaracion de la clase Complex
class Complex{
  private:
    double real; //Atributos del objeto Complex 
    double imag;
  public:
    // Constructores
    Complex(); // Constructor por defecto (inicializa a 0 + 0i)
    Complex(double r, double i);    //Constructor con parametros
    Complex(const Complex& other);  // Constructor de copia para crear una copia de otro objeto
    Complex& operator=(const Complex& other);  // Operador de asignación para copiar un objeto a otro
     ~Complex();  // Destructor

    // Métodos de la clase
    double norm() const;  // Método para calcular la norma
    void print() const;  // Método para imprimir el número complejo
    Complex conjugate() const;  // Método para calcular el conjugado

    // Sobrecarga de operadores
    Complex operator+(const Complex& other) const;  // Sobrecarga del operador +
    Complex operator-(const Complex& other) const;  // Sobrecarga del operador -
    Complex operator*(const Complex& other) const;  // Sobrecarga del operador *
    Complex operator/(const Complex& other) const;  // Sobrecarga del operador /
    // Getters por si en algún momento necesito acceder a la parte real o imaginaria desde fuera de la clase
    double getReal() const { return real; }
    double getImag() const { return imag; }
};
#endif
