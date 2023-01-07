The main function in this example creates a new matrix with 3 rows and 3 columns, 
and sets several elements in the matrix using the matrix_set function. It then uses 
the matrix_print function to print the matrix to the console, and finally frees the 
memory used by the matrix using the matrix_free function.

This example shows how you can use the Matrix ADT to create, manipulate, and print 
matrices in a C program. The ADT provides an abstract interface for working with 
matrices, and the implementation details (such as the size and data layout of the 
matrix) are hidden from the client code. This can make it easier to use the ADT 
and can also make it easier to change the implementation if needed.



****

resize


This example shows how you can use the matrix_resize function to change the size of 
the matrix. The matrix_resize function uses the realloc function to change the size 
of the rows of the matrix and the size of the elements in each row. After calling 
matrix_resize, the matrix has 4 rows and 4 columns, and the element at position (3, 3) 
can be set to a new value using the matrix_set function. The matrix is then printed 
to the console to show the changes.

This implementation allows you to change the size of the matrix at runtime, which 
can be useful if you need to dynamically adjust the size of the matrix in your 
program. However, keep in mind that using realloc can be relatively slow and can also 
lead to fragmentation of the memory heap, so you should use it with caution in 
performance-critical applications.