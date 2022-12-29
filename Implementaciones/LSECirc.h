//* a la derecha era para definir un puntero
//* a la izquierda es para indireccion

typedef int tClave;

typedef struct dato
{
    tClave clave;   //tomamos al entero cmo dato almacenado, que es simult. su propia clave
}tDato;

typedef struct Nodo
{
    tDato info;
    struct nodo* sig;
}nodo;

typedef struct Lista
{
    nodo* sig cab;
    nodo* sig act;
}tLista;

void lCrear(tLista* l)
 {
      l->cab = NULL;
 }

int lVacia(tLista* l)
{
    return l->cab == NULL;
}

int lLlena(tLista* l)
{
    return 0;
}

void lPpio (tLista* l)
{
    l->act = l->cab;
}

void lInfo (tLista* l, tDato* x)
{
    *x = (l->act)->info;

}

void lModificar (tLista* l, tDato x)
{
    (l->act)-> info = x;
}

int lFin (tLista* l)
{
    return (l->act == NULL);

}

void lSig (tLista* l)
{
    l->act == (l->act)->sig;
}

void crearNodo(nodo* nuevo, tDato dato)
{
    *nuevo = (*nodo)malloc(sizeof(nodo));
    nuevo->info = dato;
    nuevo->sig = NULL;
}

void lInsertarPpio(tLista* l, tDato dato)
{
    *nodo t, nuevo;
    crearNodo(nuevo, dato);
    if (l->cab == NULL)
    {
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }
    else
    {
        t = l->cab;
        while (t->sig != l->cab)
        {
            t= t->sig;
        }
        nuevo->sig = l->cab;
        t->sig = nuevo;
        l->cab = nuevo;
    }
}

void lInsertarFin(tLista* l, tDato x)
{
    *nodo t, nuevo;
    crearNodo(nuevo, x);
    if (l->cab == NULL)
    {
        nuevo->sig = nuevo;
        l-> cab = nuevo;
    }
    else
    {
        t = l->cab;
        while (t->sig != l->cab)
        {
            t = t->sig;
        }
        nuevo->sig = l->cab;
        t->sig = nuevo;
    }
}

void lInsertarOrdenado(tLista* l, tDato dato, char ord)
{
    *nodo nuevo, t;
    crearNodo(nuevo, dato);
    if (l->cab == NULL)
    {
        nuevo->sig = nuevo;
        l->cab = nuevo;
    }
    else
    {
        if ((((l->cab)->info).clave < dato.clave && ord == 'd') || (((l->cab)->info).clave>dato.clave&&ord=='a'))
        {
            t = l->cab;
            while (t->sig != l->cab)
            {
                t = t->sig;
            }
            nuevo->sig = l->cab;
            t->sig = nuevo;
            l->cab = nuevo;
        }
        else
        {
            t=l->cab;
            while((t->sig != l->cab)&&((t->sig)->info.clave < dato.clave)&&(ord == 'a') || ((t->sig)->info.clave > dato.clave) && (ord == 'd'))
            {
                t = t->sig;
            }
            nuevo->sig = t;
            t->sig = nuevo;
        }
    }
}

void lBorrarActual(tLista* l)
{
    *nodo t, aux;
    if (l->cab == l->actual)
    {
        if ((l->cab)->sig == l->cab)
        {
            t= l->cab;
            l->cab = NULL;
            l->act = NULL;
            free(t);
        }
        else
        {
            aux = l->act;
            t = l->cab;
            while (t->sig != l->cab)
            {
                t = t->sig;
            }
            l->act = (l->act)->sig;
            l->cab = l->act;
            t->sig = l->act;
            free(aux);
        }
        else
        {
            aux= l->act;
            t = l->cab;
            while (t->sig != l->act)
            {
                t = t->sig;
            }
            l->act = (l->act)->sig;
            t->sig = l->act;
            free(aux);
        }
    }
}

void lBorrarFin(tLista* l)
{
    *nodo aux, t;
    t=l->cab;
    if ((l->cab)->sig == l->cab)
    {
        l->cab = NULL;
        free(t);
    }
    else
    {
        aux = l->cab;
        while ((aux->sig)->sig != l->cab)
        {
            aux = aux->sig;
        }
        t = aux->sig;
        aux->sig = l->cab;
        free(t);
    }
}

void lBorrarPpio(tLista* l)
{
    nodo* aux, t;
    aux=l->cab;
    if ((l->cab)->sig == l->cab)
    {
        l->cab = NULL;
    }
    else
    {
        t = l->cab;
        while (t->sig != l->cab)
        {
            t = t->sig;
        }
        l->cab = (l->cab)->sig;
        t->sig = l->cab;
    }
    free(aux);
}

void lBuscarOrd(tLista* l, tDato algo, bool* EXISTE)    //cambiar dato.clave por algo (no pasar subregistros)
{
    nodo* t;
    t=l->cab;
    *EXISTE = false;
    if (l->cab == NULL) //se fija si no esta vacia
    {
        if ((l->cab)->info.clave == dato.clave) //se fija si esta en primer pos
        {
            *EXISTE = true;
            l->act = l->cab;
        }
        else
        {
            t = (l->cab)->sig;
            while (t!=l->cab && t->info.clave == (l->cab)->info.clave)  //saltea repetidos
            {
                t = t->sig;
            }
            if (t!=l->cab)  //salteo todos repetidos y no volvio en circulos al ppio
            {
                if (t->info.clave < (l->cab)->info.clave)   //se fija si lista 'd'
                {
                    while (t!=l->cab && t->info.clave > dato.clave) //no vuelve al ppio y no encuentra uno menor a el
                    {
                        t = t->sig;
                    }
                    else
                    {
                        while (t!=l->cab && t->info.clave < dato.clave) //se fija si 'a'
                        {
                            t = t->sig;
                        }
                    }
                }
                if (t!=l->cab && t->info.clave == dato.clave)
                {
                    *EXISTE = true;
                    l->act = t;
                }
            }
        }
    }
}
