#include <stdio.h>
#define N 10 //Size of Vector

void main(void)
{
	int i, j, aux, vector[N] = { 5,4,5,0,-1,10,23,7,-7,10 };
	printf("El vector desordenado:\n[");
	for (i = 0; i < N - 1; i++)
	{
		printf("%d, ", vector[i]);
	}
	printf("%d] \n", vector[N-1]);
	/*comparación del elemento i-ésimo con los que le siguen*/
	for (i = 0; i < N - 1; i++)
	{
		/*pasada de comparación número i*/
		for (j = i + 1; j < N; j++)
		{
			/*Si están en orden incorrecto, se intercambian*/
			if (vector[i]<vector[j])
			{
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}
	/*Muestra por StdOut el vector ordenado de mayor a menor*/
	printf("El vector ordenado:\n[");
	for (i = 0; i < N - 1; i++)
	{
		printf("%d, ", vector[i]);
	}
	printf("%d]", vector[N-1]);
}