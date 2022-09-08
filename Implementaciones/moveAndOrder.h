#include "ListaEstCCorr.h" //solo hace falta lo pertinente al procedimiento
void moveAndOrder(tPila* p,tCola* c, bool* ERROR)
{

typedef int tClave;

typedef struct Dato
{
    tClave clave;
}tDato;

tLista l;       //lista de ciertoTipo(entero p/ nosotros)
tPila paux;     //pila de ciertoTipo(entero p/ nosotros)
int ant, n;
tDato dato;

ERROR = false;
if (!pVacia(p))//aca no van &, ya es un puntero por el pasaje por parametro
{
    lCrear(&l);
    pCrear(&paux);

    while (!pVacia(p) && ERROR!=true)     //cambiamos != por ==
    {
        pSacar(p, &n);
        if (!lLlena(&l))
        {
            dato.clave = n;
            lInsertarOrden(&l, dato.clave, 'a');       //DEBE HABER ERROR
        }
        else
        {
            ERROR = true;
        }
        if (!pLlena(&paux))
        {
            pPoner(&paux, n);
        }
        else
        {
            ERROR = true;
        }
    }
    if (!ERROR)   //antes ERROR!=false
    {
        if (!lVacia(&l))
        {
           lPpio(&l);
           lInfo(&l, &dato);
           if (!cLlena(c))
           {
               cPoner(c, dato.clave);
           }
           else
           {
               ERROR = true;
           }
           ant = dato.clave;
           lSig(&l);
           while (!lFin(&l) && !ERROR)  //PARAR ACA::BIEN RESUELTO
           {
               lInfo(&l, &dato);
               if (!cLlena(c))
               {
                   if (ant!=dato.clave)
                   {
                    cPoner(c, dato.clave);
                   }
               }
               else
               {
                   ERROR = true;
               }
               ant = dato.clave;
               lSig(&l);
           }
        }
        while (!pVacia(&paux) && ERROR!=true)
        {
            pSacar(&paux, &n);
            if (!pLlena(p))
            {
                pPoner(p, n);
            }
            else
            {
                ERROR = true;
            }
        }
    }
}

}
