#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[]) {
    // Inicializamos MPI
    MPI_Init(&argc, &argv);

    // Obtenemos el rango (ID) del proceso y el tamaño total de procesos
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Cada proceso tiene un buffer con su propio rango
    int buffer = rank;

    // Realizamos N iteraciones (donde N es el número de procesos)
    for (int iteration = 0; iteration < size; ++iteration) {
        // Enviar el valor de buffer a proceso siguiente
        int send_rank = buffer;

        if (rank == size - 1) { // El último proceso envía al primer proceso
            MPI_Send(&send_rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        } else {
            // Enviar al siguiente proceso y recibir del anterior
            MPI_Send(&send_rank, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            MPI_Recv(&buffer, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // En la iteración, el proceso 0 escribe en terminal el contenido de su buffer
        if (rank == 0) {
            std::cout << "Iteración " << iteration << ": Buffer en el proceso 0 = " << buffer << std::endl;
        }
    }

    // Después de N iteraciones, el proceso 0 recibe nuevamente el valor 0
    if (rank == 0) {
        std::cout << "Iteración final: El valor recibido por el proceso 0 es " << buffer << std::endl;
    }

    // Finalizamos MPI
    MPI_Finalize();
    return 0;
}

