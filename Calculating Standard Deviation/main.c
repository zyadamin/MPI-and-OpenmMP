#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc , char * argv[])
{
  int my_rank;		/* rank of process	*/
  int p;			/* number of process	*/
  int Integer;
  int globalSum = 0;
  int localSum = 0;
  int localSumOfd = 0;
  int gloabalSumOfd = 0;
  int globalmean = 0;
  int ST=0;

	MPI_Status status;	/* return status for 	*/
				/* recieve		*/

	/* Start up MPI */
	MPI_Init( &argc , &argv );

	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	/* Find out number of process */
	MPI_Comm_size(MPI_COMM_WORLD, &p);


	if( my_rank == 0)
	{

     printf("Enter an integer: ");
     scanf("%d", &Integer);

    }

     MPI_Bcast(&Integer , 1 , MPI_INT, 0,MPI_COMM_WORLD);

    if( my_rank != 0)
    {
        int i;
	    for(i = 0; i<Integer; i++){
            srand(time(0));
	       int number = (rand() % (1000 - 1 + 1)) + 1;
            printf("%d ",number);
            localSum+=number;
	    }

	      printf("SUM at rank %d are %d\n",my_rank,localSum );
    }


   MPI_Allreduce(&localSum,&globalSum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);

  if (my_rank!=0){

     globalmean=(globalSum/(Integer*(p-1)));
    localSumOfd = localSum*((Integer-globalmean)*(Integer-globalmean));
  }

  MPI_Reduce(&localSumOfd,&gloabalSumOfd,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

  if (my_rank == 0 ){
   ST=sqrt(gloabalSumOfd/(Integer-1));
      printf("Standard Deviation %d\n",ST);

  }

	/* shutdown MPI */
	MPI_Finalize();
    return 0;
}
