# MPI-and-OpenmMP-with-c

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



