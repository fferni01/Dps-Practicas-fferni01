#include <stdio.h>

//DCL01-C
unsigned long long int factorial(unsigned int i){
    if(i <= 1){
        return 1;
    }
    return i * factorial(i-1); 
}


int main(int argc, char *argv[]){
    int i = 12, j= 3, f=0; //DCL00-C, DCL04-C,

    if(argc == 1){
        printf("Factorial of %d is %11d\n", i, factorial(i));
    }
    else{
        j = atoi(argv[1]);
        for(f=0;f<j;f++){
            printf("Factorial of %d is %11d\n",f,factorial(f));
        }
    }
    return 0;
}


/*
    1.- Este fragmento de codigo calcula el factorial que le pases como argumento,
        si no le pasas ningun argumento te calcula el factorial de 12.
    2.- 
        DCL04-C. Do not declare more than one variable per declaration
        DCL00-C. Const-qualify immutable objects (La i en este caso nunca deberia cambiar) 
        DCL01-C. Do not reuse variable names in subscopes 

    
*/