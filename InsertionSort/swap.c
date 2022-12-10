void swap(int i, int j,int *elem)
{
    int aux;
    aux = elem[i];
    elem[i] = elem[j];
    elem[j] = aux;
}