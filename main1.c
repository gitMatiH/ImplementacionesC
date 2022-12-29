//procedimiento ingreso de pila por usuario y vista de cola (devolucion/testeo)

//directivas de preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definicion de pila de entrada
#include "Implementaciones/pilaEstatica.h"
//definicion de cola de salida
#include "Implementaciones/colaDinamica.h"
//la cola no hace falta definirla porque no se invoca a este nivel (se usa recien en moveAndOrder)

//inclusion del procedimiento moveAndOrder
#include "Implementaciones/moveAndOrder.h"

int main(void)
{
    bool ERROR;
    char opcion;
    int dato;

    tPila p;
    pCrear(&p);

    tCola c;
    cCrear(&c);

    ERROR = false;
    /*
    printf("\nSe ingresara una pila de enteros para obtener una cola de enteros\nque contenga los elementos de la pila pero ordenados ascendentemente\ny sin repetidos.\n");
    printf("\nProceda a ingresar los elementos de la pila (puede estar vacia).\nSolamente funciona con enteros.\n\n's' para cuando queden datos para ingresar\n'n' para cuando no queden datos por ingresar\n\n");

    printf("Hay datos? s/n: ");
    do
    {
        scanf(" %c",&opcion);
        if (opcion!='s' && opcion!='n')
        {
            printf("caracter invalido, vuelva a ingresar: ");
        }
    } while (opcion!='s' && opcion!='n');

    while (opcion == 's' && ERROR!=true)
    {
        printf("ingrese un entero: ");      //se puede validar con un string de digitos limitando los caracteres a la tabla ASCII y que el rango de codificacion corresponda a digitos solamente
        scanf("%d", &dato);
        if (!pLlena(&p))   //precondicion por contrato
        {
            pPoner(&p, dato);//ingresa el entero en el tope de la pila
        }
        else
        {
            ERROR = true;
        }

        printf("Hay datos? s/n: ");
        do
        {
            scanf(" %c",&opcion);
            if (opcion!='s' && opcion!='n')
            {
                printf("caracter invalido, vuelva a ingresar: ");
            }
        } while (opcion!='s' && opcion!='n');
    }
    */
    int arr[10] = {4, 5, 22, 2, 5, 5, 7, 7, 19, 34};
    int i = 0;
    while(i<10 && !pLlena(&p)){
        pPoner(&p, arr[i]);
        i++;
    }
    if(i<10){
        printf("Error de memoria /n");
    }
    else
    {
        moveAndOrder(&p, &c, &ERROR);

        /* para probar esto, devuelve la cola de salida en la sig. parte del codigo*/
        printf("elementos de la cola\n");
        if (cVacia(&c))
        {
            printf("cola vacia");
        }
        else
        {
            while (!cVacia(&c))
            {
                cSacar(&c, &dato);
                printf("%d\n", dato);
            }
        }
        if (ERROR == true)  //se fija si hubo error
        {
            return 1;       //1 si fallo la accion
        }
        else
        {
            return 0;       //0 si la accion fue exitosa
        }
    }
}
