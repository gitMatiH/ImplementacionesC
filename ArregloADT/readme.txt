implement a sensible strategy for growth of the array based on the current usage 
in the main function
Here is an implementation of a dynamic array in C with a sensible strategy for
 growth of the array based on the current usage:

/*
strategic_array.c
*/

In this implementation, the insertArray function increases the size of the array 
by 50% if the number of used elements is equal to the size of the array. This is 
a sensible strategy because it allows the array to grow at a rate that is 
proportional to its current size, which should help to minimize the number of 
times that the array needs to be resized.

I hope this helps! Let me know if you have any questions.