#ifndef COMPLEX_HPP
#define COMPLEX_HPP
//Acá viene la declaracion de complex
class Complex
{
  public:
    double real; //Atributos del objeto Complex 
    double imag;
    double norm() const;
    double conjugate();
    Complex();
    Complex(double r, double i);
};
#endif
