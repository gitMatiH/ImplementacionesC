#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int rings;
   if(argc != 2) {
       printf("Usage: %s number-of-rings\n",argv[0]);
       return 1;
   }

   printf("Pos 1 of array = %s\n", argv[0]);

   rings = atoi(argv[1]);
   printf("Using number-of-rings = %d\n", rings);

   return 0;
}