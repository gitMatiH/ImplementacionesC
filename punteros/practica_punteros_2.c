#include <stdio.h>

//prototipos
void swap(int *a, int *b);

//main
int main(void)
{
	int a,b,c;
	a=b=c=0;

	printf("Enter 3 numbers: ");
	//ver docu printf
	scanf("%d %d %d", &a, &b, &c);
	//ver docu scanf
	printf("Result: %d\n", a+b+c);

	int x, y;
	x = 5;
	y = 10;
	printf("x: %d, y: %d\n", x, y);
	swap(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

//def funcion
void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}