#include <iostream>
#include <omp.h>
#include <sys/time.h>
#include <vector>
#include <cstdio> 
#include <cstdlib>

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

// Función para la integración numérica utilizando suma de Riemann con punto medio.
double Int_Riemann(double(*func)(double), double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps; //Ancho de cada rectangulo
    double I = 0;
    #pragma omp parallel
    {
    #pragma omp for reduction(+: I)
    for (int i = 0; i < steps; ++i) {
        I += func(lim_inf + (i + 0.5) * h);
    }
    }
    return I*h;//devuelve el resultado de la integral
}

// Función para hacer la gráfica con gnuplot
void plot_grafica(const std::vector<int>& threads, const std::vector<double>& times) {
    FILE* gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Escalabilidad con OpenMP'\n");
        fprintf(gnuplot, "set xlabel 'Número de hilos'\n");
        fprintf(gnuplot, "set ylabel 'Escalabilidad '\n");
        fprintf(gnuplot, "plot '-' with linespoints title ' Escalabilidad vs Hilos'\n");

        // Enviar los datos a gnuplot
        for (size_t i = 0; i < threads.size(); ++i) {
            fprintf(gnuplot, "%d %f\n", threads[i], times[i]);
        }

        fprintf(gnuplot, "e\n"); // Finaliza la entrada de datos
        fclose(gnuplot);
    } else {
        std::cerr << "Error al abrir gnuplot." << std::endl;
    }
}

int main() {
    int N = 10000000;   // Número de subintervalos
    double x_inf = 0; //Limite inferior de la integral
    double x_sup = 1; //Limite superior de la integral
    std::vector<int> threads_list = {1, 2, 3, 4, 5, 6}; // Número de hilos a probar
    std::vector<double> times;  // Almacenar los tiempos de ejecución

    // Imprimimos el valor de pi
    std::cout.precision(12); // Definir decimales de precision
    std::cout << "El valor de pi es: "<<Int_Riemann(func_integrar, x_inf, x_sup, N) << std::endl;
 
    // Probar diferentes números de hilos
    for (int num_threads : threads_list) {
        omp_set_num_threads(num_threads); // Configura el número de hilos
        double time_1 = seconds();
        Int_Riemann(func_integrar, x_inf, x_sup, N);
        double time_2 = seconds();
        double total_time = time_2 - time_1;
        times.push_back(total_time);
        
        std::cout << "Threads: " << num_threads << " Time: " << total_time << " seconds" << std::endl;
    }
    // Normalizamos el tiempo haciendo tiempo serial entre tiempo paralelo

    std::vector<double> normalized_times = times;
    double serial_time = times[0];
    for (size_t i = 0; i < times.size(); ++i) {
    normalized_times[i] = serial_time / times[i];
    }

    // Grafica de escalabilidad con tiempo normalizado
    plot_grafica(threads_list,normalized_times);


    return 0;
}

