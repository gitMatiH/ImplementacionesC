#include <stdio.h>

void funcion_decay(int *elem);
void funcion(int **pElems);

void main(){
    printf("Tamaños en función main\n");
    int arreglo[] = {2,3,4,5};
    printf("sizeof(arreglo): %d\n",sizeof(arreglo));
    printf("sizeof(arreglo[0]): %d\n",sizeof(arreglo[0]));
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]);
    printf("longitud: %d\n", longitud);

    funcion_decay(arreglo);
    funcion(&arreglo);

}