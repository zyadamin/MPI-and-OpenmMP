#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
/*
init
fill
send protion
 calc subsum
 send subsum
 rcv subsum
 calc global sum
 print
*/
int main(int argc , char * argv[])
{
   int my_rank;		/* rank of process	*/
	int p;			/* number of process	*/

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
        int x,y,r;
        x=1;
        y=1000000;
        r=(y-x)/(p-1);
        int globalCount = 0;
        int i = 0;

        for (i = 1 ; i < p ; i++){

          MPI_Send (&x , 1 ,MPI_INT, i , 0 , MPI_COMM_WORLD );
          MPI_Send (&r , 1,MPI_INT, i , 0 , MPI_COMM_WORLD );
        }
        for (i = 1 ; i < p ; i++){
          int subCount;
          MPI_Recv(&subCount , 1 ,MPI_INT,i,0,MPI_COMM_WORLD, &status);
          globalCount += subCount;
        }
        printf("Total number of prime numbers is : %d\n",globalCount );
	}else
	{
    int x,r;
    MPI_Recv(&x , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD, &status);
    MPI_Recv(&r , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD , &status);

    int localCount = 0;

   int c;

   int low, high, i, flag;


   low=x+((my_rank-1)*r);

   high=r*my_rank;

   while (low < high) {
      flag = 0;
      if (low <= 1) {
         ++low;
         continue;
      }

      for (i = 2; i <= low / 2; ++i) {

         if (low % i == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0)
         localCount++;

      ++low;
   }



    MPI_Send (&localCount , 1 , MPI_INT , 0 , 0 , MPI_COMM_WORLD);

    printf("Total number of prime numbers in : %d",my_rank);
    printf(" is : %d\n", localCount);


	}

	/* shutdown MPI */
	MPI_Finalize();
    return 0;
}
