#include <stdio>
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
    char * elem = argv[1];
    int i = 1;

    while (elem != NULL){
        elem = argv[i];
        i = i + 1;
    }
    longitud = i;
    //rango de numeros entrada 1 -- i, el ultimo caracter es null

    //longitud con sizeof

    int long = longitud;
    //generamos arreglo con arreglo de caracteres a arreglo de enteros
    int arreglo[longitud-1];
    i = 0;
    while (i<long){
        arreglo[i] = argv[i+1];
        i = i + 1;
    }
    //debería copiarse el null en la ultima pasada

    //ordenamiento sobre el mismo arreglo
    int j;
    for (j = 0, j<long , j = j+1){
        i = j;
        int pos_menor = i;
        int menor = arreglo[i];
        //busca menor del subarreglo
        while (i < long){
            if arreglo[i] < menor{
              pos_menor = arreglo[i];
              menor = arreglo[i];
            }
            i = i + 1;
        }
        swap(pos_menor, j, arreglo)
    }

    //imprimimos el arreglo ordenado
    printarr(arreglo);

}