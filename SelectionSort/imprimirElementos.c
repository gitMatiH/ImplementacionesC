#include <stdio.h>

void imprimirElementos(int *elemento)
{
    printf("Se ejecuta imprimirElementos.c\n");
    int * elem = elemento;
    int longitud = sizeof(elem)/sizeof(elem[0]);
    printf("longitud: %d\n",longitud);
    printf("Elementos del array: \n");
    int i;
    for (i = 0; i < longitud; i++) {     
        printf("%d ", elem[i]);     
    } 
    printf("\n");
    printf("Segundo elemento del array: \n");  
    printf("%d\n", elem[1]);    
}