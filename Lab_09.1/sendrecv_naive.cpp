#include <iostream>
#include <mpi.h>

int main(){

  int size, rank;
  int sendbuff, recvbuff;

  int tag = 0;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  sendbuff = rank;
  MPI_Status stat;

  if(size != 2) MPI_Abort(MPI_COMM_WORLD, 1);

  // Laboratorio
  // Realice la operación Send-Recv utilizando un llamado a la función MPI_Sendrecv
  if(rank == 0){ // El proceso con rank 0 envía datos al proceso 1 y recibe datos de él
   // Su código aquí
   MPI_Sendrecv(&sendbuff, 1, MPI_INT, 1, tag, // Enviar 'sendbuff' a proceso 1
    &recvbuff, 1, MPI_INT, 1, tag,            // Recibir en 'recvbuff' de proceso 1
    MPI_COMM_WORLD, &stat);                  // Usar el comunicador global y almacenar el estado en 'stat'
  }

  if(rank == 1){ // El proceso con rank 1 envía datos al proceso 0 y recibe datos de él
   // Su código aquí
   MPI_Sendrecv(&sendbuff, 1, MPI_INT, 0, tag, // Enviar 'sendbuff' a proceso 0
    &recvbuff, 1, MPI_INT, 0, tag,            // Recibir en 'recvbuff' de proceso 0
    MPI_COMM_WORLD, &stat);                  // Usar el comunicador global y almacenar el estado en 'stat'
  }

  std::cout << "I'm: " << rank << " and my recv is: " << recvbuff << std::endl;

  MPI_Finalize();

  return 0;
}
