#include <stdio.h>
#include <stdarg.h>

enum
{
    va_eol = -1
};

unsigned int average(int first, ...)
{
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;

    va_start(args, first);

    while (i != va_eol)
    {
        sum += i;
        count++;
        i = va_arg(args, int);
    }

    va_end(args);
    return (count ? (sum / count) : 0);
}

int main(void)
{
  printf("%d", average(1,6));
}

/*

    1- Calcula la media de una lista de enteros que se le pasa como argumentos,
       suma los elementos de esta lista, aumenta el contador y para finalizar 
       divide la suma total entre el número de elementos totales de esta lista. 

    2- va_eol es usada para saber cuando la lista de variables pasadas como 
       argumento a la función se ha terminado pudiendo así salir del bucle while

    3-  Los siguientes parámetros pertenecen a C++ por lo que los he descartado:
            -Wctor-dtor-privacy,-Wnoexcept,-Wold-style-cast,-Woverloaded-virtual,-Wsign-promo,-Wstrict-null-sentinel
            
        Se ha compilado con el siguiente comando sin obtener ningún warning:
        
        gcc -std=c11 -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op 
            -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 
            -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option 2.1.c
*/
