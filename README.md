# MPI-and-OpenmMP

## Counting Primes

parallel c program for “Counting Primes” using the

following two methods: MPI_Send and MPI_Receive ONLY

Master Process:
1. Calculate the sub range size r=(y-x)/p.
2. Note that p is the number of processes.
3. Broadcast x and r to each slave process using MPI_Send.
4. Receive sub count from each slave process using MPI_Receive.
5. Print total count of primes between x and y.

Slave Process:
1. Receive x and r through the MPI_Receive.
2. Calculate the lower bound a and upper bound b according to its rank.
3. Count primes in its sub range (between a and b).
4. Print the partial count
5. Send this partial count to the master process using the MPI_Send.

## Calculating Standard Deviation

to calculate standard deviation using MPI_Bcast, MPI_Reduce
& MPI_Allreduce ONLY.

Master Process:
1. Read n from the user.
2. Broadcast n to each slave process using MPI_Bcast.
3. Calculate the square root of the mean of squared differences.

Slave Process:
1. Get n through the MPI_Bcast call.
2. Generate n random elements. So each process will generate n numbers.
3. Calculate local sum of the generated n elements.
4. Share this local sum with the rest of the processes using MPI_Allreduce.
5. Calculate the global mean. (Total sum of elements / n * numOfProcesses).
6. Calculate local sum of squared differences from the mean. Sum (n - mean)2
7. Share this local sum of squared differences with the master process using
MPI_Reduce call.

## Matrix puzzle

Write a parallel C program using OpenMP such tha:

1. Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded
by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at
locations just left and just right of it.
O’s at the edges will not be replaced
