#include <stdio.h>
#include <stdlib.h>
#include "selectionSort.h"
#define selectionSort main

/**
 * precondición: los argumentos debe(n) ser: (enteros separados por blankspace)
 * podemos calcular la longitud del arreglo en la función
 */

void selectionSort(int argc, char **argv)
{
	//quedó medio feo porque no es un selection sort, es selsort mas otras cosas

    //longitud con while
    int longitud;
    //porque es un string, tenemos char*
    char *elem = argv[1];
    int i = 1;

    while (elem != NULL){
        elem = argv[i];
	printf("elem %s \n", elem);
        i = i + 1;
    }
    longitud = i;
    //rango de numeros entrada 1 -- i, el ultimo caracter es null
    printf("longitud de strings de entrada %d\n", longitud);

    int longitudCaracteres = longitud-1;
    //generamos arreglo con arreglo de caracteres a arreglo de enteros

    int longitudEnteros = longitudCaracteres -1;
    printf("longitudEnteros %d\n", longitudEnteros);
    i = 0;
    int arreglo[longitudEnteros]; 
    while (i<longitudEnteros){
        arreglo[i] = atoi(argv[i+1]);
        printf("elem %d \n", arreglo[i]);
        i = i + 1;
    }

    //imprimirElementos(arreglo);

    printf("ordenamiento\n");
    //ordenamiento sobre el mismo arreglo
    int j;
    for (j = 0; j<longitudEnteros; j = j+1){
        i = j;
        int pos_menor = i;
        int menor = arreglo[i];
        //busca menor del subarreglo
        while (i < longitudEnteros){
            if (arreglo[i] < menor){
              pos_menor = i;
              menor = arreglo[i];
            }
            i = i + 1;
        }
        swap(pos_menor, j, arreglo);
    }

    //imprimirElementos(arreglo);


    longitud = sizeof(arreglo)/sizeof(arreglo[0]);
    printf("longitud: %d\n",longitud);
    printf("Elementos del array: \n");    
    for (int i = 0; i < longitud; i++) {     
        printf("%d ", arreglo[i]);     
    } 


}