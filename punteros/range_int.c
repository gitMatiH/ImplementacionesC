#include <stdio.h>  
#include <limits.h>  
#include <float.h>  
  
int main()  
{  
    /* print the range of signed integer type */  
    printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);  
   /* print the range of unsigned integer type */  
    printf("Range of unsigned int 0 to %u\n\n", UINT_MAX);  
    /* print the range of signed char type */  
    printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);  
    /* print the range of unsigned char type */  
    printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);  
    /* print the range of signed long integer type */  
    printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);  
    /* print the range of unsigned long integer type */  
    printf("Range of unsigned long int 0 to %lu\n\n", ULONG_MAX);  
    /* print the range of signed short integer type */  
    printf("Range of signed short int %d to %d\n", SHRT_MIN, SHRT_MAX);  
    /* print the range of unsigned short integer type */  
    printf("Range of unsigned short int 0 to %d\n\n", USHRT_MAX);  
    /* print the range of float type */  
    printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);  
    /* print the range of double type */  
    printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);  
    /* print the range of long double type */  
    printf("Range of long double %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    getchar();
    return 0;  
}  