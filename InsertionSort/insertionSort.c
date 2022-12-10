#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertionSort.h"

void imprimirElementos(int *elem, int longitud)
{
    printf("Elementos del array: \n");    
    for (int i = 0; i < longitud; i++) {     
        printf("%d ", elem[i]);     
    } 
    printf("\n");
    printf("Segundo elemento del array: \n");  
    printf("%d\n", elem[1]);    
}

/*
void insertionSort(int *arreglo, int longitud)
{
	return 0;
}
*/


int main() {

	int *pArreglo;
	int arr[20];
	memset ( arr, 0, 20*sizeof(int) ) ;
	pArreglo = lectura(arr);

	int longitud = sizeof(arr)/sizeof(arr[0]);

	//insertionSort(datos, longitud);
	imprimirElementos(pArreglo, longitud);

	return 0;
}