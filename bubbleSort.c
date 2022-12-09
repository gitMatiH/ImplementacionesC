#include <stdio.h>

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

void swap(int i, int j,int *elem)
{
    int aux;
    aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}

void bubbleSort(int *elem, int longitud)
{
    int i, j;
    i = 0;
    while (i<longitud)
    {
        j = 0;
        while (j<(longitud-1-i))
        {
            if (elem[j]>elem[j+1])
            {
                swap(j, j+1, elem);
            }
            j = j + 1;
        } 
        i = i + 1;
    }
}

int main() {
    int x;
    printf("Ingrese la longitud del array: ");
    scanf("%d", &x);
    int data[x];
    int i = 0;
    int elem;
    while (i<x)
    {
        printf("Ingrese el elemento %d del array: ", i+1);
        scanf("%d", &elem);
        data[i] = elem;
        i = i + 1;
    }
    
    int longitud = sizeof(data)/sizeof(data[0]);
    
    bubbleSort(data, longitud);
    imprimirElementos(data, longitud);

    return 0;

}