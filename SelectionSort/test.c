#include <stdio.h>
#include <stdlib.h>
//falta atoi
//https://classes.mst.edu/compsci1570/ntca.htm
//https://es.stackoverflow.com/questions/519936/capturar-y-recorrer-un-arreglo-de-cadenas-en-c

void main(int argc, char** argv){

    int k = 1;
    printf("%d\n", k);

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
    printf("longitud %d\n", longitud);

    //longitud con sizeof

    int longNueva = longitud-1;
    //generamos arreglo con arreglo de caracteres a arreglo de enteros
    int arreglo[longNueva];
    printf("longNueva  %d\n", longNueva );
    i = 0;
    while (i<longNueva){
        arreglo[i] = atoi(argv[i+1]);
        printf("elem %d \n", arreglo[i]);
        i = i + 1;
    }
    //debería copiarse el null en la ultima pasada


    int longitud2 = sizeof(arreglo)/sizeof(arreglo[0]);
    printf("longitud2: %d\n", longitud2);
    printf("Elementos del array: \n");
    int elemento;
    int j = 0;

    while (j<longitud2){
        elemento  = arreglo[3];
        printf("%d ", arreglo[j]);

        j = j+1;
    }
    /*
    for (int i = 0; i < longNueva; i++) {     
        printf("%d ", arreglo[i]);     
    }
    */
    printf("\n");
    printf("Segundo elemento del array: \n");  
    printf("%d\n", arreglo[1]);    


}