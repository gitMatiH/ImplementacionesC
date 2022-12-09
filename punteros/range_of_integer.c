#include <stdio.h>  
int main() {  
    int x;  
    printf("\nInput an integer: ");   
    scanf("%d", &x);  
    if(x >=0 && x <= 25)   
    {  
        printf("Range [0, 25]\n");  
    }   
    else if(x >=26 && x <= 40)   
    {  
        printf("Range (26,50]\n");  
    }   
    else if(x >=41 && x <= 60)   
    {  
        printf("Range (45,75]\n");  
    }   
    else if(x >61 && x <= 80) {  
        printf("Range (61,80]\n");  
    }   
    else   
    {  
    printf("Outside the range\n");  
    }     
    return 0;  
}  