what is the difference between an array adt and a vector adt?
An array ADT (abstract data type) is a data structure that provides an abstract
 representation of an array. It typically provides operations for manipulating 
arrays, such as inserting and deleting elements, and may also provide additional 
functionality such as resizing the array when it becomes full.

A vector ADT is similar to an array ADT, but it is implemented as a dynamic array, 
which means that it can grow or shrink as needed to accommodate the elements that 
are being stored in it. Vector ADTs typically provide the same types of operations 
as array ADTs, but may also provide additional functionality such as automatic 
resizing and the ability to insert or delete elements at specific positions in the 
vector.

In general, the main difference between an array ADT and a vector ADT is the way 
that they are implemented and the additional functionality that they provide. 
Array ADTs are typically implemented as static arrays, which have a fixed size 
that cannot be changed once they are created, while vector ADTs are implemented 
as dynamic arrays, which can grow or shrink as needed to accommodate the elements 
that are being stored in them. Vector ADTs may also provide additional functionality 
such as automatic resizing and the ability to insert or delete elements at specific
 positions in the vector.


***

now implement the data type to be a bank account, that has things like name,
 phone number, amount of money. Put different elements in the vector
Sure! Here is an implementation of a vector ADT in C that stores elements of a 
BankAccount data type, which has a name, phone number, and amount of money:

In this example, the BankAccount struct represents a bank account with a name, 
phone number, and balance. The Vector struct stores a pointer to an array of 
BankAccount pointers, the number of elements used, and the size of the array. 
The insertVector function increases the size of the array by 50% if the number 
of used elements is equal to the size of the array. The main function demonstrates
 how to create and insert elements of the BankAccount data type into the vector.

I hope this helps! Let me know



modify the vector ADT so that it won't accept something that is greater than
available memory, and so that it can be of any data type. That is, that can accept a 
potentially different data type in each array position

Sure! Here is an implementation of a vector ADT in C that can store elements of 
any data type and won't accept elements if there is not enough memory available 
to store them:

In this implementation, the Vector struct stores a void pointer to the array, 
the number of elements used, the size of the array, and the size of each element 
in the array. The insertVector function attempts to increase the size of the array
 by 1 if the number of used elements is equal to the size of the array. If there is
 not enough memory available to store the new element, the function returns 0. 
The main function demonstrates how to use the vector ADT to store elements of
 different types, and how to check the return value of the insertVector function 
to determine if an element was successfully inserted into the vector.

I hope this helps! Let me know if you have any questions.
