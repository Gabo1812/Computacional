#include<iostream>
#include<cmath>
#include "complex.hpp"
//Aca viene la implementación, donde primero importamos el complx.hpp
//Inicializamos en 0.0 + i*0.0
Complex::Complex(){
  real = 0.0;
  imag = 0.0;
}
//Construir el constructor para parametros
Complex::Complex(double r, double i){
  real = r;
  imag = i;
}
//Probamos con una función 
double Complex::norm() const {
  return real*real + imag*imag;
}
