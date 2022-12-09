// programiz | Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int b = 42;
    int *a = &b;
    
    printf("b: %d\n", b);
    printf("&b: %p\n", &b);
    printf("a: %p\n", a);
    
    // go get what a is pointing and use that
    *a = 50;
    
    printf("b: %d\n", b);
    printf("&b: %p\n", &b);
    printf("a: %p\n", a);
    
    
    //lowlevellearning
    int x = 4;
    int * pX = &x;
    int y = *pX;
    
    printf("x: %d\n", x);
    printf("pX: %p\n", pX);
    printf("y: %p\n", y);

    return 0;
}