#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>

int main(int argc, char** argv) {
    
    MPI_Init(&argc, &argv); // Inicializa MPI

    // Inicializa MPI y obtiene el rango y número de procesos
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtiene el número total de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtiene el identificador del proceso
    
    // Verifica si se proporcionó un argumento (tamaño del vector)
    if (argc != 2) {
        if (rank == 0) {
            std::cerr << "Uso: " << argv[0] << " [tamaño del vector]" << std::endl;
        }
        MPI_Finalize(); // Finaliza MPI
        return 1;
    }
    
    int N; // Tamaño de los vectores A y B
    try {
        N = std::stoi(argv[1]); // Convierte el argumento a entero
    } catch (const std::invalid_argument& e) {
        if (rank == 0) {
            std::cerr << "Error: El argumento debe ser un número entero válido." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }
    
    if (N % size != 0) {
        if (rank == 0) {
            std::cerr << "Error: El tamaño del vector debe ser múltiplo del número de procesos." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    // Calcula cuántos elementos tendrá cada proceso
    int nlocal = N / size;
    
    // Vectores locales y globales
    std::vector<int> local_a(nlocal), local_b(nlocal);
    std::vector<int> a, b;

    if (rank == 0) { // El proceso 0 inicializa los vectores globales
        a.resize(N);
        b.resize(N);
        for (int i = 0; i < N; i++) {
            a[i] = i + 1;  // a = [1, 2, 3, ..., N]
            b[i] = i + 1;  // b = [1, 2, 3, ..., N]
        }
    }
    
    // Distribuye los datos de los vectores a todos los procesos
    MPI_Scatter(a.data(), nlocal, MPI_INT, local_a.data(), nlocal, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(b.data(), nlocal, MPI_INT, local_b.data(), nlocal, MPI_INT, 0, MPI_COMM_WORLD);
    
    // Cada proceso calcula su producto punto local
    int productoInternoLocal  = 0;
    for (int i = 0; i < nlocal; i++) {
        productoInternoLocal  += local_a[i] * local_b[i];
    }
    
    // Realiza una reducción para obtener el producto punto total en el proceso 0
    int productoInternoTotal  = 0;
    MPI_Reduce(&productoInternoLocal , &productoInternoTotal , 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (rank == 0) { // Solo el proceso 0 muestra el resultado
        std::cout << "Producto punto total: " << productoInternoTotal  << std::endl;
    }
    
    MPI_Finalize(); // Finaliza MPI
    return 0;
}

