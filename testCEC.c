#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Implementaciones/colaEstaticaCircular.h"


void estadoCola(int a) {
	printf("\n");
	
	if (a == 0) {
		printf("la cola no esta vacia");
	}
	else {
		printf("la cola esta vacia");
	}
}

void vaciarCola(tCola* q) {
	printf("\nVaciando Cola:\n[");
	int a;
	bool primeraVuelta = 1;
	while (cVacia(q) == 0) {
		if (primeraVuelta == 1) { primeraVuelta = 0; }
		else { printf(", "); }
		cSacar(q, &a);
		printf("%d", a);

	}
	printf("]");
}

void main() {

	tCola cola1;
	cCrear(&cola1);
	bool sal;
	sal = cVacia(&cola1);
	printf("%d", sal);
	printf("\n");
	int a = 7;
	cPoner(&cola1, a);
	sal = cVacia(&cola1);
	printf("%d", sal);
	printf("\n");
	int b = 8;
	cPoner(&cola1, b);
	int c;
	cSacar(&cola1, &c);
	printf("\n");
	printf("%d", c);
	cSacar(&cola1, &c);
	printf("\n");
	printf("%d", c);

	sal = cVacia(&cola1);
	estadoCola(sal);
	

	b = 8;
	cPoner(&cola1, b);
	printf("\n");
	sal = cVacia(&cola1);
	estadoCola(sal);
	b = 8;
	cPoner(&cola1, b);
	printf("\n");
	sal = cVacia(&cola1);
	estadoCola(sal);

	printf("\n");
	float porcentaje;
	porcentaje = porcentajeOcupacion(&cola1, CMAX);
	printf("%% de ocupacion: %f", porcentaje);


	vaciarCola(&cola1);


	sal = cVacia(&cola1);
	estadoCola(sal);

	printf("\n");
	int d = 1;
	while (cLlena(&cola1) == 0) {
		printf("%d, ", d);
		cPoner(&cola1, d);
		d = d + 1;
	}
	sal = cVacia(&cola1);
	estadoCola(sal);
	//imprimirCola(&cola1, CMAX);
	vaciarCola(&cola1);
}