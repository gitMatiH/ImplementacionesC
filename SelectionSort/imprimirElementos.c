#include <stdio.h>

void imprimirElementos(int * elem, int longitudEnteros)
{
    printf("Se ejecuta imprimirElementos.c\n");
    //int * elem = elemento;
    //printf("sizeof(elem): %d\n",sizeof(elem));
    //printf("sizeof(elem[0]): %d\n",sizeof(elem[0]));
    //int longitud = sizeof(elem)/sizeof(elem[0]);
    
    
    printf("longitud: %d\n",longitudEnteros);
    printf("Elementos del array: \n");
    int i;
    for (i = 0; i < longitudEnteros; i++) {     
        printf("%d ", elem[i]);     
    } 
    printf("\n");
    printf("Cuarto elemento del array: \n");  
    printf("%d\n", elem[3]);    
}