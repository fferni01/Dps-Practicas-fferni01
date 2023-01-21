#include <stdlib.h>

struct flexArrayStruct
{
    int num;
    //int data[1]; DCL38-C
    int data[]
};

void func(size_t array_size)
{
    /*Space is allocated for the struct*/
    struct flexArrayStruct *structP = (struct flexArrayStruct *)malloc(sizeof(struct flexArrayStruct) + sizeof(int) * (array_size - 1));
    if (structP == NULL)
    {
        /*Handle malloc failure */
    }

    structP->num = array_size;

    /*
     *Accessdata[] as if it had been allocated as data[arraysize].
     */

    for (size_t i = 0; i < array_size; ++i)
    {
        structP->data[i] = 1;
    }
}
/*
    1-
        Se declara un array flexible para crear un struct de tamaño dinámico,
    2-
        El error se encuentra en la línea 6
    3-
        La regla incumplida es: DCL38-C. Use the correct syntax when declaring a flexible array member-
*/
