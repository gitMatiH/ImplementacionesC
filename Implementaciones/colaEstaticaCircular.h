#define CMAX 15

typedef int tDato;


typedef struct Cola
{
    tDato elem[CMAX-1];
    int inicio;
    int fin;
}tCola;

void cCrear(tCola* q)
{
    q->inicio = -1;
    q->fin = -1;
}

int cVacia(tCola* q)
{
    return q->inicio == q->fin;
}

int cLlena(tCola* q)

{
    return ((q->inicio == 0 && q->fin == CMAX-1) || ((q->fin+1) == q->inicio));// asi no tiene sentido, q->(inicio+1), deberia ser q->inicio+1
}

void cPoner(tCola* q, tDato x)
{
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

void cSacar(tCola* q, tDato* x) //ojo ahora tDato va por ref
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
