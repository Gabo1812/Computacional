#include <iostream>
#include <omp.h>
#include <sys/time.h>

double seconds()
{ 
 struct timeval tmp;
 double sec;
 gettimeofday( &tmp, (struct timezone *)0 );
 sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

 return sec;
}


// Definimos la función a integrar
double func_integrar(double x) {
    return 4.0 / (1.0 + x * x);
}
int num_procs;
// Función para la integración numérica utilizando suma de Riemann con punto medio.
double Int_Riemann(double(*func)(double), double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps; //Ancho de cada rectangulo
    double I = 0;
    #pragma omp parallel
    {
    num_procs = omp_get_num_threads();
    #pragma omp for reduction(+: I)
    for (int i = 0; i < steps; ++i) {
        I += func(lim_inf + (i + 0.5) * h);
    }
    }
    return I*h;//devuelve el resultado de la integral
}

int main() {
    int N = 100000;  // Número de subintervalos
    double x_inf = 0; //Limite inferior de la integral
    double x_sup = 1; //Limite superior de la integral
    // Imprimimos el resultado
    std::cout.precision(12); // Definir decimales de precision
    double time_1 = seconds();
    std::cout << Int_Riemann(func_integrar, x_inf, x_sup, N) << std::endl;
    double time_2 = seconds();
    std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl;
    std::cout << "Number of Threads: " << num_procs << std::endl;
    return 0;
}

