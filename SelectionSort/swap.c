#include <stdio.h>

void swap(int i, int j,int *elem)
{
/*
    printf("sizeof(elem): %d\n",sizeof(elem));
    printf("sizeof(elem[0]): %d\n",sizeof(elem[0]));
    int longitud = sizeof(elem)/sizeof(elem[0]);
    printf("longitud: %d\n", longitud);
*/
    int aux;
    aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}