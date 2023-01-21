#include <stdio.h>
#include <stddef.h>
const char *p;
char funcion1(char *array)
{
    /*
    La regla que se incumple es: DCL30-C. Declare objects with appropriate storage durations.
    
    */
    //char array[10] = "MiCadena";
    array = "MiCadena";
    return array;
}
void funcion2(void)
{
    const char c_str[] = "Todovabien";
    p = c_str;
}
void funcion3(void)
{
    printf("%s\n", p);
}
int main(void)
{
    char array[10]; 
    p = funcion1(array);
    printf("%s \n", p);
    //DCL30-C.
    p = NULL;
    funcion2();
    funcion3();
    printf("%s \n", p);
    //DCL30-C.
    p = NULL;


    return 0;
}