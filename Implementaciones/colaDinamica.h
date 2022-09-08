//acá le habiamos puesto *c a todo y no iba en todo

typedef int tDato;

typedef struct nodo
{
    tDato info;
    struct nodo* sig;
}Nodo;

typedef Nodo* tCola;

void cCrear (tCola* c)  //no necesita return? Nop
{
    c = NULL;       //no iba un asterisco, ya lo pasamos por referencia
                    //ya es un puntero, sino sería puntero a puntero
}

int cVacia (tCola* c)
{
    return c == NULL;
}

int cLlena(tCola* c)
{
    Nodo* nodo; //nodo es el nombre de un puntero de tipo Nodo,
                //todavia no reside en memoria. El no poder ni
                //guardar el nombre de una variable ya apareceria
                //como error de sistema operativo.
    int* punt =(Nodo*)malloc(sizeof(Nodo));
    if (punt == NULL)
    {
        //printf("Cola llena.\n");
        //free(punt);
        return (1); //cLlena es Verdadero
    }
    else
    {
        //printf("Todavia hay lugar disponible.\n");
        free(punt);
        return(0); //cLlena es Falso
    }       //aca solo usar return 0
}

int cSacar(tCola* c, tDato* dato)
{       // aca si es correcto usar *c
    Nodo* aux;
    *dato = (*c)->info;
    aux = (*c);
    *c = (*c)->sig;
    free(aux);
}

void cPoner(tCola* c, tDato dato)   //quedo igual que la pila. este tda esta implementado con lista, y el ultimo de la lista deberia apuntar a null
{
    Nodo* nodo;
    nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->info=dato;
    nodo->sig = *c;     //deberia apuntar a null
    *c = nodo;

    //hay que hacer un mientras para buscar el ultimo elemento
}
