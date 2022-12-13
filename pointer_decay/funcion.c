#include <stdio.h>

void funcion(int **pElems)
{
    int * elems = *pElems;
    printf("\n");
    printf("pasado a funcion_decay\n");
    printf("sizeof(elems): %d\n",sizeof(elems));
    printf("sizeof(elems[0]): %d\n",sizeof(elems[0]));
    int longitud = sizeof(elems)/sizeof(elems[0]);
    printf("longitud: %d\n", longitud);
}