# OS-Project
Dekker's Algorithm

The first correct software solution to the Critical-Section Problem for 2 processes was developed by Dekker. This is why this is also known as the Dekker’s Algorithm for the Critical-Section Problem.
Dekker's algorithm is the first known correct solution to the mutual exclusion problem in concurrent programming. 
It allows two threads to share a single-use resource without conflict, using only shared memory for communication.
If two processes attempt to enter a critical section at the same time, the algorithm will allow only one process in, based on whose turn it is. If one process is already in the critical section, the other process will busy wait for the first process to exit. This is done by the use of two flags, flag [0] and flag [1], which indicate an intention to enter the critical section on the part of processes 0 and 1, respectively, and a variable ‘turn’ that indicates who has priority between the two processes.

Dekker's algorithm guarantees mutual exclusion, freedom from deadlock, and freedom from starvation.

One advantage of this algorithm is that it doesn't require special test-and-set (atomic read/modify/write) instructions and is therefore 
highly portable between languages and machine architectures. One disadvantage is that it is limited to two processes and makes use of 
busy waiting instead of process suspension. (The use of busy waiting suggests that processes should spend a minimum of time inside the 
critical section.)
