#ifndef COLA_ESTATICA_CIRCULAR_H
#define COLA_ESTATICA_CIRCULAR_H
#define CMAX 15



typedef int tDato;


typedef struct Cola
{
    tDato elem[CMAX];
    int inicio;
    int fin;
}tCola;

/*con conocimiento de longitudArr*/
float porcentajeOcupacion(tCola* q, int longitudArr) {

/**
*   Precondicion: longitudArr (sino no se puede). Se saca al crear la estructura
*   Poscondicion: devuelve porcentaje de ocupacion
  */
    float porcentaje;

    if ( (*q).inicio < (*q).fin ) {
        float aux = ((*q).fin - (*q).inicio + 1) * 100;
        porcentaje = aux/longitudArr;
        return porcentaje;
    }

    if ( (*q).inicio > (*q).fin ) {
        float aux = longitudArr - ((*q).inicio + 1) + (*q).fin;
        porcentaje = aux / longitudArr;
        return porcentaje;
    }
    
    if ( (*q).inicio == (*q).fin ) {
        porcentaje = 100;
        return porcentaje;
    }

}

/*sin conocimiento de longitudArr*/

void cCrear(tCola* q)
{

/**
*   Precondicion: que se le pase una cola vacia
*   Poscondicion: devuelve a la cola inicializada
  */

    q->inicio = -1;
    q->fin = -1;
}

int cVacia(tCola* q)
{

/**
*   Precondicion: no tiene
*   Poscondicion: devuelve 1 si esta vacia, 0 si no esta vacia
 */

    return q->inicio == q->fin;
}

int cLlena(tCola* q)

/**
*   Precondicion: no tiene
*   Poscondicion: devuelve 1 si esta llena, 0 si no esta llena
 */

{
    return ( (q->inicio == 0 && q->fin == CMAX-1) ||
           ( (q->fin)+1 == q->inicio) );
}



void cPoner(tCola* q, tDato x)
{

/**
*   Precondicion: no cLlena()
*   Poscondicion: pone el elemento x de tipo'' en el final de la cola
 */

    if (q->fin == CMAX-1)
    {
        q->fin = 0;
    }
    else
    {
        q->fin = (q->fin+1);
    }
    q->elem[q->fin] = x;
}

void cSacar(tCola* q, tDato* x)
{
    if (q->inicio == CMAX-1)
    {
        q->inicio = 0;
    }
    else
    {
        q->inicio = (q->inicio+1);
    }
    *x = q->elem[q->inicio];
}


#endif