#define CMAX 15
#include <stdbool.h>

typedef int tClave;

typedef struct Datol
{
    tClave clave;
}tDatol;


typedef struct Lista
{
    tDatol elem[CMAX-1];
    int actual;
    int tope;
}tLista;

void lCrear(tLista* l)
{
    l->tope = -1;       //EN VEZ DEL 0 DEL PSEUDOCODIGO
}

int lVacia(tLista* l)
{
    return l->tope == -1;
}

void lPpio(tLista* l)
{
    l->actual = 0;
}

int lFin(tLista* l)
{
    return l->actual > l->tope;
}

void lInfo(tLista* l, tDatol* x)
{
    *x = l->elem[l->actual];
}

void lSig(tLista* l)
{
    l->actual = l->actual+1;
}

int lLlena(tLista* l)
{
    return ((l->tope) == (CMAX-1));
}

void lModificar(tLista* l, tDatol x)
{
    l->elem[l->actual] = x;
}

void lInsertarPpio(tLista* l, tDatol x)
{
    int i;
    for( i=0; i=l->tope ; i--)
    {
        l->elem[i+1] = l->elem[i];
    }
    l->elem[0] = x;
    l->tope = l->tope+1;
}

void lInsertarFin(tLista* l, tDatol x)
{
    l->tope = l->tope +1;
    l->elem[l->tope] = x;
}

void lBuscarOrdenado(tLista* l, tClave* x, bool* EXISTE)
{
    int pr, ul, central;
    char ord;
    *EXISTE = 0;
    if (l->tope > 0)
    {
        if ((l->elem[0].clave)<(l->elem[l->tope].clave))
        {
            ord = 'a';
        }
        else
        {
            ord='d';
        }
        pr = 0;
        ul = l->tope;
        if (ord == 'a')
        {
            while ((pr <= ul) && (!EXISTE))
            {
                central = div((pr+ul),2).quot;
                if ((l->elem[central].clave) == x)
                {
                    EXISTE = 1;
                    l->actual = central;
                }
                else
                {
                    if (l->elem[central].clave > x)
                    {
                        ul = (central-1);
                    }
                    else
                    {
                        pr = (central+1);
                    }
                }
            }
        }
        else
        {
            while ((pr <= ul) && (!EXISTE))
            {
                central = div((pr+ul),2).quot;
                if ((l->elem[central].clave) == x)
                {
                    EXISTE = 1;
                    l->actual = central;
                }
                else
                {
                    if (l->elem[central].clave > x)
                    {
                        pr = (central-1);
                    }
                    else
                    {
                        ul = (central+1);
                    }

                }
            }
        }
    }
}

void lBorrarActual (tLista* l)
{
    int i;
    for (i = l->actual; i = l->tope -1;i++)
    {
        l->elem[i] = l->elem[i+1];
    }
    l->tope = l->tope-1;
}

void lBorrarPpio (tLista* l)
{
    int i;
    for (i = 0; i = l->tope -1;i++)
    {
        l->elem[i] = l->elem[i+1];
    }
    l->tope = l->tope-1;
}

void lBorrarFin (tLista* l)
{
    l->tope = l;
}

void lInsertarOrden (tLista* l , tClave x, char ord)
{
    int i, pos;
    i = 0; //antes 0
    while (i <= (l->tope) && ((ord == 'a' && l->elem[i].clave < x) || (ord == 'd' && l->elem[i].clave > x)))  //saque los x".clave"
    {
        i++;
    }

    pos = l->tope;
    for (pos; pos>=i; pos--)
    {
        (l->elem[pos+1]) = (l->elem[pos]);
    }
    (l->elem[i].clave) = x;
    (l->tope) = (l->tope +1);
}
