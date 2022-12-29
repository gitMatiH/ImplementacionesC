#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Implementaciones/colaEstaticaCircular.h"


void main{

	tCola cola1;
	cCrear(&cola1);
	bool sal;
	sal = cVacia(cola1);
	printf("%d", sal);
}