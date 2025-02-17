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
  // Asegúrese de que entiende lo que hace la siguiente línea
  int peer = (rank == 0) ? 1 : 0; // Establece 'peer' a 1 si el rank es 0, de lo contrario a 0.
  // Implemente el Send-Recv
  // Su código aquí
  MPI_Sendrecv(&sendbuff, 1, MPI_INT, peer, tag,  // Enviar 'sendbuff' al proceso 'peer'
    &recvbuff, 1, MPI_INT, peer, tag,  // Recibir en 'recvbuff' del proceso 'peer'
    MPI_COMM_WORLD, &stat);           // Usar el comunicador global y almacenar el estado en 'stat'
  std::cout << "I'm: " << rank << " and my recv is: " << recvbuff << std::endl;

  MPI_Finalize();

  return 0;
}
