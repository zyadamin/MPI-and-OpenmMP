#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    int y;
    int i,j;
    int count;



    printf("Enter Rows: ");
    scanf("%d",&x);

    printf("Enter cols: ");
    scanf("%d",&y);

   // char arr[x][y];


   char ** arr = (char**)malloc (x * sizeof(char*));
    for(i=0;i<x;i++){
    arr[i]=(char*)malloc (y * sizeof(char));

    }

do{
        count=0;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){

          scanf(" %c",&arr[i][j]);

        }
    }


        for(i=0;i<x;i++){
        for(j=0;j<y;j++){

          if(arr[i][j]=='X'||arr[i][j]=='O'){
            count++;
          }

        }
    }

    if(count!=x*y){
         printf ("please enter valid input\n");
    }

}while(count!=x*y);


     #pragma omp parallel shared(arr) private(i,j)
    {
       #pragma omp for schedule(static)

        for(i=0;i<x;i++){
            for(j=0;j<y-2;j++){
            if(arr[i][j]=='X'&&arr[i][j+2]=='X'){
                arr[i][j+1]='X';
        }
         printf ("IN thread %d y[%d][%d]\n" , omp_get_thread_num() , i,j);
          }
            }

    }


    printf("\n");
    printf("\n");

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
       printf("%c ",arr[i][j]);
         }
       printf("\n");
      }



    return 0;
}
/*
X O X X X
X O X O X
O X O O X
X X X X X
X O O X X
O X O X O

X O X X O X
X O X O X O
O X O O O X
X X X X O X
X O O X O X
O X O X O X

*/

